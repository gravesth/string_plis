#include <stdio.h>

typedef unsigned long s21_size_t;
#define S21_NULL ((void *)0) 

const void *s21_memchr(const void *memptr, int ch, s21_size_t num); 
char *s21_strncpy(char *dest, const char *src, s21_size_t n);