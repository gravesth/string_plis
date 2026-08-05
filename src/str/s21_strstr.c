#include <stdlib.h>

#include "../s21_string.h"

int get_len(const char *str) {
  int len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

int *prefixFunction(const char *needle) {
  int *pf = NULL;
  int len = get_len(needle);

  if (len > 0) {
    pf = (int *)malloc(len * sizeof(int));
  }

  if (pf != NULL) {
    pf[0] = 0;
    int i = 1;
    int indpf = 0;

    while (needle[i] != '\0') {
      while (indpf > 0 && needle[indpf] != needle[i]) {
        indpf = pf[indpf - 1];
      }

      if (needle[indpf] == needle[i]) {
        indpf++;
      }

      pf[i] = indpf;
      i++;
    }
  }

  return pf;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *p = S21_NULL;
  int *pf = S21_NULL;
  int i = 0;
  int j = 0;
  int found = 0;
  if (*needle == '\0') {
    p = (char *)haystack;
    found = 1;
  } else {
    pf = prefixFunction(needle);
  }

  while (pf != NULL && haystack[i + j] != '\0' && !found) {
    if (haystack[i + j] == needle[j]) {
      j++;

      if (needle[j] == '\0') {
        p = (char *)(haystack + i);
        found = 1;
      }
    } else if (j > 0) {
      i = i + j - pf[j - 1];
      j = pf[j - 1];
    } else {
      i++;
      j = 0;
    }
  }

  if (pf != NULL) {
    free(pf);
    pf = S21_NULL;
  }

  return p;
}
