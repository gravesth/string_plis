#include "../string.h"
#include "strerror.h"

char* s21_strerror(int errnum) {
  static const char* error[] = CURRENT_SYSTEM_ERRORS;
  const char* message = NULL;
  if (errnum < 0 || errnum > MAX_ERROR_CODE || error[errnum] == NULL) {
    message = "Unknown error";
  } else {
    message = error[errnum];
  }
  return (char*)message;
}