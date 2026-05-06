#!/bin/bash
set -e

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[0;37m'

# Стили
BOLD='\033[1m'
DIM='\033[2m'
UNDERLINE='\033[4m'
BLINK='\033[5m'
REVERSE='\033[7m'

# Сброс
NC='\033[0m' # No Color

project_name="CytexLab.Kernel.MemFunc"
total_operations=2

# Инициализация переменных
build_type=""
build_cache_dir=""
output_dir=""
hide=0
declare -A dependences

# Разбор аргументов командной строки
while [ $# -gt 0 ]; do
    case "$1" in
        --build-type|-b)
            build_type="$2"
            shift 2
            ;;
        --hide|-h)
            hide=1
            shift
            ;;
		--build-cache|-bh)
			build_cache_dir="$2"
			shift 2
			;;
		--output-dir|-od)
			output_dir="$2"
			shift 2
			;;
        --dependence|-d)
			dependences["$2"]="$3"
			shift 3
			;;
		*)
            shift
            ;;
    esac
done

if [ $hide -eq 0 ]; then
	echo "Сборка модуля $project_name"
	echo "Для работы необходимо:"
	echo "  * Компилятор clang"
	echo "  * Линковщик llvm"
	echo ""
fi

# Если тип сборки не указан, запрашиваем
if [ -z "$build_type" ]; then
    echo "Введите тип сборки:"
    read build_type
	echo ""
fi

check_depen() {
	if [ -z "${dependences["$1"]}" ]; then
		if [ -d "./deps/$1" ]; then
			dependences["$1"]="./deps/$1"
		else
			echo -e "${RED}${BOLD}[ERROR]${NC} Не найдена зависимость $1"
			echo -e "${BLUE}${BOLD}[INFO]${NC} Укажите путь до корня пакета через параметр -d/--dependence"
			echo -e "${BLUE}${BOLD}[INFO]${NC} Поместите весь проект в папку deps/$1"
			exit 1
		fi
	fi 
}

check_depen "CytexLab-Platform.Base"

if [ -z "$build_cache_dir" ]; then
	build_cache_dir="build"
fi
if [ -z "$output_dir" ]; then
	output_dir="lib"
fi

mkdir -p "$build_cache_dir"
mkdir -p "$output_dir"

# Проверка и установка типа сборки
if [ "$build_type" != "Debug" ] && [ "$build_type" != "Release" ]; then
    echo -e "${RED}${BOLD}[ERROR]${NC} Не верный тип сборки ($build_type)"
    echo -e "${YELLOW}${BOLD}[WARN]${NC} Будет использован тип сборки \"Debug\""
    build_type="Debug"
fi

mkdir -p "build/$build_type"
mkdir -p "lib/$build_type"

compile_flags="-I ./include -I ./${dependences["CytexLab-Platform.Base"]}/include -nostdlib -ffreestanding -fno-rtti -fno-exceptions -fno-stack-protector"

if [ "$build_type" = "Debug" ]; then
    compile_flags="$compile_flags -g -O0"
elif [ "$build_type" = "Release" ]; then
    compile_flags="$compile_flags -O3 -march=x86-64 -flto"
fi

log() {
    if [ "$hide" -eq 0 ]; then
        echo -e "${BLUE}${BOLD}($1/$2)${NC} $3"
    fi
}

compile() {
	log $2 $total_operations $1
	if ! clang++ -c "./src/$1" -o "$build_cache_dir/$build_type/$project_name/$1.o" $compile_flags 2>&1; then
		echo -e "${RED}${BOLD}[ERROR]${NC} Ошибка компиляции $1"
		exit 1
	fi
}

archive() {
	log $2 $total_operations "Archiving $project_name..."
	local obj_files=$(find "$build_cache_dir/$build_type/$project_name" -name "*.o" )
	if ! llvm-ar rcs $1 $obj_files 2>&1; then
		echo -e "${RED}${BOLD}[ERROR]${NC} Ошибка архивирования"
		exit 1
	fi
}

compile "lib.cpp" 1

archive "$output_dir/$build_type/$build_type.$project_name.a" 2

# Если не указан флаг --hide, ждём нажатия Enter
if [ "$hide" -eq 0 ]; then
    echo ""
    echo "Успешно!"
    echo "Для выхода нажмите Enter..."
    read
fi