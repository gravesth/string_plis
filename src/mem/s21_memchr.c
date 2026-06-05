#include "../s21_string.h"
// приводим memprt к массиву байт, а также ch переводим в байты
void *s21_memchr(const void *memptr, int ch, s21_size_t num) {
    const unsigned char *ptr = (const unsigned char *)memptr;
    const unsigned char *result = NULL;
    unsigned char val = (unsigned char)ch;

    for (s21_size_t i = 0; i < num && result == NULL; i++) {
        if (val == *(ptr + i)) result = (ptr + i);
    }

    return result; 
}


