#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "../../s21_string.h"

START_TEST(test_sprintf_c_basic) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%c", 'A');
  int r2 = sprintf(buf2, "%c", 'A');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_c_width) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%5c", 'B');
  int r2 = sprintf(buf2, "%5c", 'B');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_c_left_align) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%-5c", 'C');
  int r2 = sprintf(buf2, "%-5c", 'C');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_s_basic) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%s", "Hello");
  int r2 = sprintf(buf2, "%s", "Hello");
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_s_width_precision) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%10.3s", "Hello World");
  int r2 = sprintf(buf2, "%10.3s", "Hello World");
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_s_left_align) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%-10.4s", "Hello World");
  int r2 = sprintf(buf2, "%-10.4s", "Hello World");
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_d_basic) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%d", 12345);
  int r2 = sprintf(buf2, "%d", 12345);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_d_negative) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%d", -9876);
  int r2 = sprintf(buf2, "%d", -9876);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_d_plus_sign) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%+d", 555);
  int r2 = sprintf(buf2, "%+d", 555);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_d_space_sign) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "% d", 555);
  int r2 = sprintf(buf2, "% d", 555);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_d_precision) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%.5d", 42);
  int r2 = sprintf(buf2, "%.5d", 42);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_d_zero_precision) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%.0d", 0);
  int r2 = sprintf(buf2, "%.0d", 0);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_d_long) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%ld", 123456789012L);
  int r2 = sprintf(buf2, "%ld", 123456789012L);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_d_short) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%hd", (short)32767);
  int r2 = sprintf(buf2, "%hd", (short)32767);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_u_basic) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%u", 4294967295U);
  int r2 = sprintf(buf2, "%u", 4294967295U);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_u_long) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%lu", 123456789012UL);
  int r2 = sprintf(buf2, "%lu", 123456789012UL);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_f_basic) {
  char buf1[120] = {0};
  char buf2[120] = {0};
  int r1 = s21_sprintf(buf1, "%f", 123.456);
  int r2 = sprintf(buf2, "%f", 123.456);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_f_precision) {
  char buf1[120] = {0};
  char buf2[120] = {0};
  int r1 = s21_sprintf(buf1, "%.2f", 123.456);
  int r2 = sprintf(buf2, "%.2f", 123.456);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_f_zero_precision) {
  char buf1[120] = {0};
  char buf2[120] = {0};
  int r1 = s21_sprintf(buf1, "%.0f", 123.556);
  int r2 = sprintf(buf2, "%.0f", 123.556);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_f_rounding) {
  char buf1[120] = {0};
  char buf2[120] = {0};
  int r1 = s21_sprintf(buf1, "%.1f", 0.25);
  int r2 = sprintf(buf2, "%.1f", 0.25);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_percent) {
  char buf1[100] = {0};
  char buf2[100] = {0};
  int r1 = s21_sprintf(buf1, "%%");
  int r2 = sprintf(buf2, "%%");
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_sprintf_combined) {
  char buf1[200] = {0};
  char buf2[200] = {0};
  int r1 = s21_sprintf(buf1, "A: %c, B: %s, C: %+d, D: %lu, E: %.2f%%", 'x',
                       "hello", -10, 20UL, 9.99);
  int r2 = sprintf(buf2, "A: %c, B: %s, C: %+d, D: %lu, E: %.2f%%", 'x',
                   "hello", -10, 20UL, 9.99);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

Suite *sprintf_suite(void) {
  Suite *s = suite_create("sprintf");
  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, test_sprintf_c_basic);
  tcase_add_test(tc, test_sprintf_c_width);
  tcase_add_test(tc, test_sprintf_c_left_align);
  tcase_add_test(tc, test_sprintf_s_basic);
  tcase_add_test(tc, test_sprintf_s_width_precision);
  tcase_add_test(tc, test_sprintf_s_left_align);
  tcase_add_test(tc, test_sprintf_d_basic);
  tcase_add_test(tc, test_sprintf_d_negative);
  tcase_add_test(tc, test_sprintf_d_plus_sign);
  tcase_add_test(tc, test_sprintf_d_space_sign);
  tcase_add_test(tc, test_sprintf_d_precision);
  tcase_add_test(tc, test_sprintf_d_zero_precision);
  tcase_add_test(tc, test_sprintf_d_long);
  tcase_add_test(tc, test_sprintf_d_short);
  tcase_add_test(tc, test_sprintf_u_basic);
  tcase_add_test(tc, test_sprintf_u_long);
  tcase_add_test(tc, test_sprintf_f_basic);
  tcase_add_test(tc, test_sprintf_f_precision);
  tcase_add_test(tc, test_sprintf_f_zero_precision);
  tcase_add_test(tc, test_sprintf_f_rounding);
  tcase_add_test(tc, test_sprintf_percent);
  tcase_add_test(tc, test_sprintf_combined);
  suite_add_tcase(s, tc);
  return s;
}
