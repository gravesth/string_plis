#include <check.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long s21_size_t;
#define S21_NULL ((void *)0)

void *s21_memchr(const void *memptr, int ch, s21_size_t num);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strerror(int errnum);
char *s21_strpbrk(const char *str1, const char *str2);
int get_len(const char *str);  // вспомогательная функция длины
int *prefixFunction(const char *needle);  // вспомогательная префикс функция
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
