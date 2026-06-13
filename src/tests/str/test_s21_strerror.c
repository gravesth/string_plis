#include <string.h>

#include "../../s21_string.h"
#include "../../str/strerror.h"
#include "../test_runner.h"

// tc_basic
START_TEST(success_test) { ck_assert_str_eq(s21_strerror(0), strerror(0)); }
END_TEST
START_TEST(call_test) { ck_assert_str_eq(s21_strerror(4), strerror(4)); }
END_TEST

// tc_extreme

START_TEST(os_test) {
#if defined(__APPLE__) || defined(__MACH__)
  ck_assert_str_eq(s21_strerror(106), strerror(106));

#elif defined(__linux__)
  ck_assert_str_eq(s21_strerror(133), strerror(133));
#endif
}
END_TEST

START_TEST(unknow_test) {
  ck_assert_str_eq(s21_strerror(MAX_ERROR_CODE + 1), "Unknown error");
}
END_TEST

START_TEST(negative_test) {
  ck_assert_str_eq(s21_strerror(-1), "Unknown error");
}
END_TEST

Suite *strerror_suite(void) {
  Suite *s = suite_create("Strerror Module");

  TCase *tc_basic = tcase_create("Basic Tests");
  tcase_add_test(tc_basic, success_test);
  tcase_add_test(tc_basic, call_test);
  suite_add_tcase(s, tc_basic);

  TCase *tc_extreme = tcase_create("Extreme tests");
  tcase_add_test(tc_extreme, os_test);
  tcase_add_test(tc_extreme, unknow_test);
  tcase_add_test(tc_extreme, negative_test);
  suite_add_tcase(s, tc_extreme);

  return s;
}
