#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"
#include "../test_runner.h"
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
  s21_size_t n = 6;
  char *s21_dest = malloc(n * sizeof(char));

  ck_assert_ptr_eq(s21_strncpy(s21_dest, s21_src, n), s21_dest);

  free(s21_dest);
}
END_TEST
// tc_extreme
START_TEST(test_null) {
  const char *s21_src = "\0";
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

  ck_assert_int_eq(s21_dest[0], 'X');

  free(s21_dest);
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *s = suite_create("Strncpy Module");

  TCase *tc_basic = tcase_create("Basic Tests");
  tcase_add_test(tc_basic, test_equal_len);
  tcase_add_test(tc_basic, test_min_len);
  tcase_add_test(tc_basic, test_max_len);
  suite_add_tcase(s, tc_basic);

  TCase *tc_return = tcase_create("Return Test");
  tcase_add_test(tc_return, test_return);
  suite_add_tcase(s, tc_return);

  TCase *tc_extreme = tcase_create("Extreme Test");
  tcase_add_test(tc_extreme, test_null);
  tcase_add_test(tc_extreme, test_empty);
  suite_add_tcase(s, tc_extreme);

  return s;
}
