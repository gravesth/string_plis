#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *p = S21_NULL;
  int i = 0;
  while (str1[i] != '\0' && !p) {
    int j = 0;
    while (str2[j] != '\0' && !p) {
      if (str1[i] == str2[j]) p = (char *)(str1 + i);
      j++;
    }
    i++;
  }
  return p;
}