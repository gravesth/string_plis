#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  int i = 0;
  int f = 1;
  while (str1[i] != '\0' && f) {
    int j = 0;
    while (str2[j] != '\0' && f) {
      if (str1[i] == str2[j]) f = 0;
      j++;
    }
    if (f) len++;
    i++;
  }
  return len;
}