# Пакет CytexLab.Kernel.MemFunc (CytexLab-Platform.MemFunc)
Пакет CytexLab-Platform.MemFunc предоставляет функции для работы с памятью на платформе CytexLab-Platform
## Файлы
1. Memory.hpp
## Функции
1. LPVOID memcpy(LPVOID dest, LPCVOID src, UINT64 n);
2. LPVOID memmove(LPVOID dest, LPCVOID src, UINT64 n);
3. LPVOID memset(LPVOID dest, INT32 c, UINT64 n);
4. INT32 memcmp(LPCVOID ptr1, LPCVOID ptr2, UINT64 n);
5. LPVOID memchr(LPCVOID ptr, INT32 c, UINT64 n);
6. LPVOID zero_memory(LPVOID dest, UINT64 n);
# Сборка
## Linux
Зависимости:
  1. Clang  
  2. LLVM (ld.lld, lld)  
### Debug
Debug сборка включает в себя отладочную информацию и/или отладочные символы в файле Debug.CytexLab.Kernel.MemFunc.* (Также допускается вариант создания файла рядом с библиотекой: Debug.CytexLab.Kernel.MemFunc.pdb)  
`./build.sh -b Debug` - Для запуска сборки с автовыбором Debug как режима сборки  
`./build.sh` - После запуска, необходимо будет выбрать Debug как режим сборки  
`./build.sh -b Debug -h` - Для запуска сборки с автовыбором Debug как режима сборки и тихим режимом  
`./build.sh -b Debug -d CytexLab-Platform.Base путь/к/папке/с/пакетом` - Для запуска сборки с автовыбором Debug как режима сборки и автоматическим предоставлением зависимости для сборки

### Release
Release сборка включает в себя максимальную оптимизацию по скорости и/или убирает отладочную информацию и отладочные символы  
`./build.sh -b Release` - Для запуска сборки с автовыбором Release как режима сборки  
`./build.sh` - После запуска, необходимо будет выбрать Release как режим сборки  
`./build.sh -b Release -h` - Для запуска сборки с автовыбором Release как режима сборки и тихим режимом
`./build.sh -b Release -d CytexLab-Platform.Base путь/к/папке/с/пакетом` - Для запуска сборки с автовыбором Release как режима сборки и автоматическим предоставлением зависимости для сборки
## Windows
Будет позже :)
# Лицензии
Платформа CytexLab-Platform и ее пакеты (в том числе библиотеки, тест и исполняемые файлы) распространяются под лицензией MPL 2.0 (Mozilla Public License, см. LICENSE и/или на сайте Mozilla)