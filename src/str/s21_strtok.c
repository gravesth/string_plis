#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *s_ptr = NULL;
  char *token = NULL;

  if (str != NULL) {
    s_ptr = str;
  }

  if (s_ptr != NULL) {
    int is_delim = 1;
    while (*s_ptr != '\0' && is_delim) {
      const char *d = delim;
      while (*d != '\0' && *d != *s_ptr) d++;
      if (*d != '\0')
        s_ptr++;
      else
        is_delim = 0;
    }

    if (*s_ptr != '\0') {
      token = s_ptr;

      int end_found = 0;
      while (*s_ptr != '\0' && !end_found) {
        const char *d = delim;
        while (*d != '\0' && *d != *s_ptr) d++;
        if (*d != '\0')
          end_found = 1;
        else
          s_ptr++;
      }

      if (*s_ptr != '\0') {
        *s_ptr = '\0';
        s_ptr++;
      } else {
        s_ptr = NULL;
      }
    } else {
      s_ptr = NULL;
    }
  }
  return token;
}
