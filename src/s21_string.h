#include <stdio.h>

typedef unsigned long s21_size_t;
#define S21_NULL ((void *)0) 

const void *s21_memchr(const void *memptr, int ch, s21_size_t num); 
const int *s21_memcmp(const void *str1, const void *str2, s21_size_t n);
