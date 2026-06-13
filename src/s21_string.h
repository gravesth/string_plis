#include <check.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long s21_size_t;
#define S21_NULL ((void *)0)

void *s21_memchr(const void *memptr, int ch, s21_size_t num);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strerror(int errnum);