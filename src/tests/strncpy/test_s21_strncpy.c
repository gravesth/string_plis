#include <check.h>
#include <string.h>

#include "../../s21_string.h"
// tc_basic
START_TEST(test_equal_len) {
  const char *s21_src = "abcdf";
  const char *src = "abcdf";
  s21_size_t n = 6;
  char *s21_dest = malloc(n * sizeof(char));
  char *dest = malloc(n * sizeof(char));
  s21_strncpy(s21_dest, s21_src, n);
  strncpy(dest, src, n);

  ck_assert_str_eq(s21_dest, dest);

  free(s21_dest);
  free(dest);
}
END_TEST

START_TEST(test_min_len) {
  const char *s21_src = "abcdf";
  const char *src = "abcdf";
  s21_size_t n = 5;
  char *s21_dest = malloc(n * sizeof(char));
  char *dest = malloc(n * sizeof(char));
  s21_strncpy(s21_dest, s21_src, n);
  strncpy(dest, src, n);

  ck_assert_mem_eq(s21_dest, dest, n);

  free(s21_dest);
  free(dest);
}
END_TEST

START_TEST(test_max_len) {
  const char *s21_src = "abcdf";
  const char *src = "abcdf";
  s21_size_t n = 7;
  char *s21_dest = malloc(n * sizeof(char));
  char *dest = malloc(n * sizeof(char));
  s21_strncpy(s21_dest, s21_src, n);
  strncpy(dest, src, n);

  ck_assert_mem_eq(s21_dest, dest, n);

  free(s21_dest);
  free(dest);
}
END_TEST
// tc_return
START_TEST(test_return) {
  const char *s21_src = "abcdf";
  const char *src = "abcdf";
  s21_size_t n = 6;
  char *s21_dest = malloc(n * sizeof(char));

  ck_assert_ptr_eq(s21_strncpy(s21_dest, s21_src, n), s21_dest);

  free(s21_dest);
}
END_TEST
// tc_extreme
START_TEST(test_null) {
  const char *s21_src = "\0";
  const char *src = "\0";
  s21_size_t n = 1;
  char *s21_dest = malloc(n * sizeof(char));

  ck_assert_ptr_eq(s21_strncpy(s21_dest, s21_src, n), s21_dest);

  free(s21_dest);
}
END_TEST

START_TEST(test_empty) {
  const char *s21_src = "abcd";
  s21_size_t n = 5;
  char *s21_dest = malloc(n * sizeof(char));
  s21_dest[0] = 'X';
  s21_strncpy(s21_dest, s21_src, 0);

  ck_assert_char_eq(s21_dest, 'X');

  free(s21_dest);
}
END_TEST
