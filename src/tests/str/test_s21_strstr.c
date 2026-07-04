#include <string.h>

#include "../../s21_string.h"
#include "../test_runner.h"

// tc_basic
START_TEST(start_symbol_test) {
  ck_assert_ptr_eq(s21_strstr("aabccs", "aab"), strstr("aabccs", "aab"));
}
END_TEST

START_TEST(end_symbol_test) {
  ck_assert_ptr_eq(s21_strstr("ccsaab", "aab"), strstr("ccsaab", "aab"));
}
END_TEST

START_TEST(center_symbol_test) {
  ck_assert_ptr_eq(s21_strstr("cssaabcss", "aab"), strstr("cssaabcss", "aab"));
}
END_TEST

START_TEST(only_symbol_test1) {
  ck_assert_ptr_eq(s21_strstr("a", "a"), strstr("a", "a"));
}
END_TEST

START_TEST(only_symbol_test2) {
  ck_assert_ptr_eq(s21_strstr("a", "b"), strstr("a", "b"));
}
END_TEST

START_TEST(fail_test) {
  ck_assert_ptr_eq(s21_strstr("abbdb", "abc"), strstr("abbdb", "abc"));
}
END_TEST

// tc_empty
START_TEST(empty_str1_test) {
  ck_assert_ptr_eq(s21_strstr("", "ab"), strstr("", "ab"));
}
END_TEST

START_TEST(empty_str2_test) {
  ck_assert_ptr_eq(s21_strstr("ab", ""), strstr("ab", ""));
}
END_TEST

START_TEST(empty_str_test) {
  ck_assert_ptr_eq(s21_strstr("", ""), strstr("", ""));
}
END_TEST

// tc_specific
START_TEST(register_test) {
  ck_assert_ptr_eq(s21_strstr("AABaab", "aab"), strstr("AABaab", "aab"));
}
END_TEST

START_TEST(special_symbol_test) {
  ck_assert_ptr_eq(s21_strstr("abca\taa", "a\ta"), strstr("abca\taa", "a\ta"));
}
END_TEST

Suite *strstr_suite(void) {
  Suite *s = suite_create("test module");
  TCase *tc_basic = tcase_create("test block 1");
  tcase_add_test(tc_basic, start_symbol_test);
  tcase_add_test(tc_basic, end_symbol_test);
  tcase_add_test(tc_basic, center_symbol_test);
  tcase_add_test(tc_basic, only_symbol_test1);
  tcase_add_test(tc_basic, only_symbol_test2);
  tcase_add_test(tc_basic, fail_test);
  suite_add_tcase(s, tc_basic);

  TCase *tc_empty = tcase_create("test block 2");
  tcase_add_test(tc_empty, empty_str1_test);
  tcase_add_test(tc_empty, empty_str2_test);
  tcase_add_test(tc_empty, empty_str_test);
  suite_add_tcase(s, tc_empty);

  TCase *tc_specific = tcase_create("Test block 3");
  tcase_add_test(tc_specific, register_test);
  tcase_add_test(tc_specific, special_symbol_test);
  suite_add_tcase(s, tc_specific);
  return s;
}