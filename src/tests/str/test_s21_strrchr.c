#include <string.h>

#include "../../s21_string.h"
#include "../test_runner.h"
// tc_basic
START_TEST(start_symbol_test) {
  char *str = "abcd";
  ck_assert_ptr_eq(s21_strrchr(str, 97), strrchr(str, 97));
}
END_TEST

START_TEST(end_symbol_test) {
  char *str = "abcd";
  ck_assert_ptr_eq(s21_strrchr(str, 100), strrchr(str, 100));
}
END_TEST

START_TEST(center_symbol_test) {
  char *str = "abcad";
  ck_assert_ptr_eq(s21_strrchr(str, 98), strrchr(str, 98));
}
END_TEST

START_TEST(tween_symbol_test) {
  char *str = "abcad";
  ck_assert_ptr_eq(s21_strrchr(str, 'a'), strrchr(str, 'a'));
}
END_TEST

// tc_border
START_TEST(null_symbol_test) {
  char *str = "abcad";
  ck_assert_ptr_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
}
END_TEST

START_TEST(null_ptr_test) {
  char *str = "abcad";
  ck_assert_ptr_eq(s21_strrchr(str, 'm'), strrchr(str, 'm'));
}
END_TEST

// tc_border_str
START_TEST(empty_str_test) {
  char *str = "";
  ck_assert_ptr_eq(s21_strrchr(str, 'a'), strrchr(str, 'a'));
}
END_TEST

START_TEST(special_symbol_test) {
  char *str = "abc\td";
  ck_assert_ptr_eq(s21_strrchr(str, '\t'), strrchr(str, '\t'));
}
END_TEST

Suite *strrchr_suite(void) {
  Suite *s = suite_create("test module");
  TCase *tc_basic = tcase_create("test block 1");
  tcase_add_test(tc_basic, start_symbol_test);
  tcase_add_test(tc_basic, end_symbol_test);
  tcase_add_test(tc_basic, center_symbol_test);
  tcase_add_test(tc_basic, tween_symbol_test);
  suite_add_tcase(s, tc_basic);

  TCase *tc_border = tcase_create("test block 2");
  tcase_add_test(tc_border, null_symbol_test);
  tcase_add_test(tc_border, null_ptr_test);
  suite_add_tcase(s, tc_border);

  TCase *tc_border_str = tcase_create("Test block 3");
  tcase_add_test(tc_border_str, empty_str_test);
  tcase_add_test(tc_border_str, special_symbol_test);
  suite_add_tcase(s, tc_border_str);
  return s;
}