#include <string.h>

#include "../../s21_string.h"
#include "../test_runner.h"

// tc_basic

START_TEST(only_delim_test) {
  char str_s21[] = "A, B, C";
  char str_orig[] = "A, B, C";
  const char *delim = ",";
  char *res_s21_1 = s21_strtok(str_s21, delim);
  char *res_orig_1 = strtok(str_orig, delim);

  ck_assert_str_eq(res_s21_1, res_orig_1);

  char *res_s21_2 = s21_strtok(NULL, delim);
  char *res_orig_2 = strtok(NULL, delim);

  ck_assert_str_eq(res_s21_2, res_orig_2);
}
END_TEST

START_TEST(some_delim_test) {
  char str_s21[] = "A, B! C";
  char str_orig[] = "A, B! C";
  const char *delim = ",!";
  char *res_s21_1 = s21_strtok(str_s21, delim);
  char *res_orig_1 = strtok(str_orig, delim);

  ck_assert_str_eq(res_s21_1, res_orig_1);

  char *res_s21_2 = s21_strtok(NULL, delim);
  char *res_orig_2 = strtok(NULL, delim);

  ck_assert_str_eq(res_s21_2, res_orig_2);
}
END_TEST
// tc_struct

START_TEST(contract_delim_test1) {
  char str_s21[] = "A,,,, B! C";
  char str_orig[] = "A,,,, B! C";
  const char *delim = ",!";
  char *res_s21_1 = s21_strtok(str_s21, delim);
  char *res_orig_1 = strtok(str_orig, delim);

  ck_assert_str_eq(res_s21_1, res_orig_1);

  char *res_s21_2 = s21_strtok(NULL, delim);
  char *res_orig_2 = strtok(NULL, delim);

  ck_assert_str_eq(res_s21_2, res_orig_2);
}
END_TEST
START_TEST(contract_delim_test2) {
  char str_s21[] = ",,,";
  const char *delim = ",!";
  char *res_s21_1 = s21_strtok(str_s21, delim);

  ck_assert_ptr_null(res_s21_1);
}
END_TEST

// tc_extreme
START_TEST(not_delim_test) {
  char str_s21[] = "A,,,, B! C";
  char str_orig[] = "A,,,, B! C";
  const char *delim = "E";
  char *res_s21_1 = s21_strtok(str_s21, delim);
  char *res_orig_1 = strtok(str_orig, delim);

  ck_assert_str_eq(res_s21_1, res_orig_1);
}
END_TEST
START_TEST(empty_str_test) {
  char str_s21[] = "";
  const char *delim = ",!";
  char *res_s21_1 = s21_strtok(str_s21, delim);

  ck_assert_ptr_null(res_s21_1);
}

END_TEST

Suite *strtok_suite(void) {
  Suite *s = suite_create("test module");
  TCase *tc_basic = tcase_create("test block 1");
  tcase_add_test(tc_basic, only_delim_test);
  tcase_add_test(tc_basic, some_delim_test);
  suite_add_tcase(s, tc_basic);

  TCase *tc_struct = tcase_create("test block 2");
  tcase_add_test(tc_struct, contract_delim_test1);
  tcase_add_test(tc_struct, contract_delim_test2);
  suite_add_tcase(s, tc_struct);

  TCase *tc_extreme = tcase_create("Test block 3");
  tcase_add_test(tc_extreme, not_delim_test);
  tcase_add_test(tc_extreme, empty_str_test);
  suite_add_tcase(s, tc_extreme);
  return s;
}