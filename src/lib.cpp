/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

// Этот файл распространяется под лицензией Mozilla Public License 2.0.

#include <Memory.hpp>

#ifdef __cplusplus
extern "C" {
#endif

// Базовые функции
LPVOID memcpy(LPVOID dest, LPCVOID src, UINT64 n) {
    if (!dest || !src) return NULL;
    
    LPUINT8 d = (LPUINT8)dest;
    LPCUINT8 s = (LPCUINT8)src;
    
    for (UINT64 i = 0; i < n; i++) {
        d[i] = s[i];
    }
    
    return dest;
}

LPVOID memmove(LPVOID dest, LPCVOID src, UINT64 n) {
    if (!dest || !src) return NULL;
    
    LPUINT8 d = (LPUINT8)dest;
    LPCUINT8 s = (LPCUINT8)src;
    
    if (d < s) {
        for (UINT64 i = 0; i < n; i++) {
            d[i] = s[i];
        }
    } else if (d > s) {
        for (UINT64 i = n; i > 0; i--) {
            d[i - 1] = s[i - 1];
        }
    }
    
    return dest;
}

LPVOID memset(LPVOID dest, INT32 c, UINT64 n) {
    if (!dest) return NULL;
    
    LPUINT8 d = (LPUINT8)dest;
    UINT8 value = (UINT8)c;
    
    for (UINT64 i = 0; i < n; i++) {
        d[i] = value;
    }
    
    return dest;
}

INT32 memcmp(LPCVOID ptr1, LPCVOID ptr2, UINT64 n) {
    if (!ptr1 || !ptr2) return (ptr1 == ptr2) ? 0 : (ptr1 ? 1 : -1);
    
    LPCUINT8 p1 = (LPCUINT8)ptr1;
    LPCUINT8 p2 = (LPCUINT8)ptr2;
    
    for (UINT64 i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return (p1[i] < p2[i]) ? -1 : 1;
        }
    }
    
    return 0;
}

LPVOID memchr(LPCVOID ptr, INT32 c, UINT64 n) {
    if (!ptr) return NULL;
    
    LPCUINT8 p = (LPCUINT8)ptr;
    UINT8 value = (UINT8)c;
    
    for (UINT64 i = 0; i < n; i++) {
        if (p[i] == value) {
            return (LPVOID)(p + i);
        }
    }
    
    return NULL;
}

// Обнуление памяти
LPVOID zero_memory(LPVOID dest, UINT64 n) {
    return memset(dest, 0, n);
}

LPVOID zero_memory_i8(LPINT8 dest, UINT64 n) {
    return memset(dest, 0, n * sizeof(INT8));
}

LPVOID zero_memory_u8(LPUINT8 dest, UINT64 n) {
    return memset(dest, 0, n * sizeof(UINT8));
}

LPVOID zero_memory_ptr(LPVOID* dest, UINT64 n) {
    return memset(dest, 0, n * sizeof(LPVOID));
}

// Типизированные функции (макросы для генерации)
#define DEFINE_MEMCPY_TYPE(type, prefix) \
    LP##type memcpy_##prefix(LP##type dest, LPC##type src, UINT64 n) { \
        return (LP##type)memcpy(dest, src, n * sizeof(type)); \
    }

#define DEFINE_MEMSET_TYPE(type, prefix) \
    LP##type memset_##prefix(LP##type dest, type value, UINT64 n) { \
        for (UINT64 i = 0; i < n; i++) { \
            dest[i] = value; \
        } \
        return dest; \
    }

#define DEFINE_MEMCMP_TYPE(type, prefix) \
    INT32 memcmp_##prefix(LPC##type ptr1, LPC##type ptr2, UINT64 n) { \
        return memcmp(ptr1, ptr2, n * sizeof(type)); \
    }

// Генерация функций для знаковых типов
DEFINE_MEMCPY_TYPE(INT8, i8)
DEFINE_MEMCPY_TYPE(INT16, i16)
DEFINE_MEMCPY_TYPE(INT32, i32)
DEFINE_MEMCPY_TYPE(INT64, i64)

DEFINE_MEMSET_TYPE(INT8, i8)
DEFINE_MEMSET_TYPE(INT16, i16)
DEFINE_MEMSET_TYPE(INT32, i32)
DEFINE_MEMSET_TYPE(INT64, i64)

DEFINE_MEMCMP_TYPE(INT8, i8)
DEFINE_MEMCMP_TYPE(INT16, i16)
DEFINE_MEMCMP_TYPE(INT32, i32)
DEFINE_MEMCMP_TYPE(INT64, i64)

// Генерация функций для беззнаковых типов
DEFINE_MEMCPY_TYPE(UINT8, u8)
DEFINE_MEMCPY_TYPE(UINT16, u16)
DEFINE_MEMCPY_TYPE(UINT32, u32)
DEFINE_MEMCPY_TYPE(UINT64, u64)

DEFINE_MEMSET_TYPE(UINT8, u8)
DEFINE_MEMSET_TYPE(UINT16, u16)
DEFINE_MEMSET_TYPE(UINT32, u32)
DEFINE_MEMSET_TYPE(UINT64, u64)

DEFINE_MEMCMP_TYPE(UINT8, u8)
DEFINE_MEMCMP_TYPE(UINT16, u16)
DEFINE_MEMCMP_TYPE(UINT32, u32)
DEFINE_MEMCMP_TYPE(UINT64, u64)

// Поиск символа
LPCVOID memchr_i8(LPCINT8 ptr, INT8 value, UINT64 n) {
    return memchr(ptr, (INT32)value, n * sizeof(INT8));
}

LPCVOID memchr_i16(LPCINT16 ptr, INT16 value, UINT64 n) {
    return memchr(ptr, (INT32)value, n * sizeof(INT16));
}

LPCVOID memchr_i32(LPCINT32 ptr, INT32 value, UINT64 n) {
    return memchr(ptr, value, n * sizeof(INT32));
}

#ifdef __cplusplus
}
#endif