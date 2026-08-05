#include "../s21_string.h"
#include "strerror.h"

char *s21_strrchr(const char *str, int c) {
  char *symbol = NULL;
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == (char)c) symbol = (char *)(str + i);
    ;
    i++;
  }
  if ((char)c == '\0') symbol = (char *)(str + i);

  return symbol;
}