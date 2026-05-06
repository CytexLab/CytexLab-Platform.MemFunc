/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

// Этот файл распространяется под лицензией Mozilla Public License 2.0.

#ifndef _MEMORY_H
#define _MEMORY_H

#include <Types.hpp>

#ifdef __cplusplus
extern "C" {
#endif

// Базовые функции памяти
LPVOID memcpy(LPVOID dest, LPCVOID src, UINT64 n);
LPVOID memmove(LPVOID dest, LPCVOID src, UINT64 n);
LPVOID memset(LPVOID dest, INT32 c, UINT64 n);
INT32 memcmp(LPCVOID ptr1, LPCVOID ptr2, UINT64 n);
LPVOID memchr(LPCVOID ptr, INT32 c, UINT64 n);

// Функции с указателями на конкретные типы
LPINT8 memcpy_i8(LPINT8 dest, LPCINT8 src, UINT64 n);
LPINT16 memcpy_i16(LPINT16 dest, LPCINT16 src, UINT64 n);
LPINT32 memcpy_i32(LPINT32 dest, LPCINT32 src, UINT64 n);
LPINT64 memcpy_i64(LPINT64 dest, LPCINT64 src, UINT64 n);

LPUINT8 memcpy_u8(LPUINT8 dest, LPCUINT8 src, UINT64 n);
LPUINT16 memcpy_u16(LPUINT16 dest, LPCUINT16 src, UINT64 n);
LPUINT32 memcpy_u32(LPUINT32 dest, LPCUINT32 src, UINT64 n);
LPUINT64 memcpy_u64(LPUINT64 dest, LPCUINT64 src, UINT64 n);

// Заливка памяти для конкретных типов
LPINT8 memset_i8(LPINT8 dest, INT8 value, UINT64 n);
LPINT16 memset_i16(LPINT16 dest, INT16 value, UINT64 n);
LPINT32 memset_i32(LPINT32 dest, INT32 value, UINT64 n);
LPINT64 memset_i64(LPINT64 dest, INT64 value, UINT64 n);

LPUINT8 memset_u8(LPUINT8 dest, UINT8 value, UINT64 n);
LPUINT16 memset_u16(LPUINT16 dest, UINT16 value, UINT64 n);
LPUINT32 memset_u32(LPUINT32 dest, UINT32 value, UINT64 n);
LPUINT64 memset_u64(LPUINT64 dest, UINT64 value, UINT64 n);

// Сравнение блоков памяти
INT32 memcmp_i8(LPCINT8 ptr1, LPCINT8 ptr2, UINT64 n);
INT32 memcmp_i16(LPCINT16 ptr1, LPCINT16 ptr2, UINT64 n);
INT32 memcmp_i32(LPCINT32 ptr1, LPCINT32 ptr2, UINT64 n);
INT32 memcmp_i64(LPCINT64 ptr1, LPCINT64 ptr2, UINT64 n);

INT32 memcmp_u8(LPCUINT8 ptr1, LPCUINT8 ptr2, UINT64 n);
INT32 memcmp_u16(LPCUINT16 ptr1, LPCUINT16 ptr2, UINT64 n);
INT32 memcmp_u32(LPCUINT32 ptr1, LPCUINT32 ptr2, UINT64 n);
INT32 memcmp_u64(LPCUINT64 ptr1, LPCUINT64 ptr2, UINT64 n);

// Поиск символа в памяти
LPCVOID memchr_i8(LPCINT8 ptr, INT8 value, UINT64 n);
LPCVOID memchr_i16(LPCINT16 ptr, INT16 value, UINT64 n);
LPCVOID memchr_i32(LPCINT32 ptr, INT32 value, UINT64 n);
LPCVOID memchr_u8(LPCUINT8 ptr, UINT8 value, UINT64 n);
LPCVOID memchr_u16(LPCUINT16 ptr, UINT16 value, UINT64 n);
LPCVOID memchr_u32(LPCUINT32 ptr, UINT32 value, UINT64 n);

// Обнуление памяти
LPVOID zero_memory(LPVOID dest, UINT64 n);
LPVOID zero_memory_i8(LPINT8 dest, UINT64 n);
LPVOID zero_memory_u8(LPUINT8 dest, UINT64 n);
LPVOID zero_memory_ptr(LPVOID* dest, UINT64 n);

#ifdef __cplusplus
}
#endif

#endif