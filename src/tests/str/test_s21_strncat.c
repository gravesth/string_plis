#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"
#include "../test_runner.h"

START_TEST(test_strncat_basic) {
  const char *src = "world";
  s21_size_t n = 6;
  char *s21_dest = malloc(20 * sizeof(char));
  char *dest = malloc(20 * sizeof(char));
  strcpy(s21_dest, "hello ");
  strcpy(dest, "hello ");
  s21_strncat(s21_dest, src, n);
  strncat(dest, src, n);
  ck_assert_str_eq(s21_dest, dest);
  free(s21_dest);
  free(dest);
}
END_TEST

START_TEST(test_strncat_partial_n) {
  const char *src = "world";
  s21_size_t n = 3;
  char *s21_dest = malloc(20 * sizeof(char));
  char *dest = malloc(20 * sizeof(char));
  strcpy(s21_dest, "hi ");
  strcpy(dest, "hi ");
  s21_strncat(s21_dest, src, n);
  strncat(dest, src, n);
  ck_assert_str_eq(s21_dest, dest);
  free(s21_dest);
  free(dest);
}
END_TEST

START_TEST(test_strncat_max_n) {
  const char *src = "abc";
  s21_size_t n = 10;
  char *s21_dest = malloc(20 * sizeof(char));
  char *dest = malloc(20 * sizeof(char));
  strcpy(s21_dest, "x");
  strcpy(dest, "x");
  s21_strncat(s21_dest, src, n);
  strncat(dest, src, n);
  ck_assert_str_eq(s21_dest, dest);

  free(s21_dest);
  free(dest);
}
END_TEST

START_TEST(test_strncat_return) {
  const char *src = "test";
  s21_size_t n = 5;
  char *s21_dest = malloc(20 * sizeof(char));
  strcpy(s21_dest, "a");
  ck_assert_ptr_eq(s21_strncat(s21_dest, src, n), s21_dest);
  free(s21_dest);
}
END_TEST

START_TEST(test_strncat_empty_src) {
  const char *src = "";
  s21_size_t n = 5;
  char *s21_dest = malloc(20 * sizeof(char));
  char *dest = malloc(20 * sizeof(char));
  strcpy(s21_dest, "hello");
  strcpy(dest, "hello");
  s21_strncat(s21_dest, src, n);
  strncat(dest, src, n);
  ck_assert_str_eq(s21_dest, dest);
  free(s21_dest);
  free(dest);
}
END_TEST

Suite *strncat_suite(void) {
  Suite *s = suite_create("test block 1");
  TCase *tc_basic = tcase_create("Basic Tests");
  tcase_add_test(tc_basic, test_strncat_basic);      //
  tcase_add_test(tc_basic, test_strncat_partial_n);  //
  tcase_add_test(tc_basic, test_strncat_max_n);
  suite_add_tcase(s, tc_basic);

  TCase *tc_return = tcase_create("test block 2");
  tcase_add_test(tc_return, test_strncat_return);
  suite_add_tcase(s, tc_return);

  TCase *tc_extreme = tcase_create("extra test");
  tcase_add_test(tc_extreme, test_strncat_zero_n);
  tcase_add_test(tc_extreme, test_strncat_empty_src);
  suite_add_tcase(s, tc_extreme);

  return s;
}
