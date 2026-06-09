#include <string.h>

#include "../../s21_string.h"
#include "../test_runner.h"


//basic_tests

START_TEST(symbol_start)
{
    ck_assert_int_eq(s21_strcspn("Hello", "H"), strcspn("Hello", "H"));
}
END_TEST

START_TEST(symbol_center)
{
    ck_assert_int_eq(s21_strcspn("Hello", "lo"), strcspn("Hello", "lo"));
}
END_TEST

START_TEST(symbol_end)
{
    ck_assert_int_eq(s21_strcspn("Hello", "o"), strcspn("Hello", "o"));
}
END_TEST

//empty_tests

START_TEST(str1_empty)
{
    ck_assert_int_eq(s21_strcspn("", "A"), strcspn("", "A"));
}
END_TEST


START_TEST(str2_empty)
{
    ck_assert_int_eq(s21_strcspn("Hello", ""), strcspn("Hello", ""));
}
END_TEST

START_TEST(str_empty)
{
    ck_assert_int_eq(s21_strcspn("", ""), strcspn("", ""));
}
END_TEST

//coincidences_tests

START_TEST(complete_coincidences)
{
    ck_assert_int_eq(s21_strcspn("aaaaaaaaa", "a"), strcspn("aaaaaaaaa", "a"));
}
END_TEST

START_TEST(absence_coincidences)
{
    ck_assert_int_eq(s21_strcspn("aaaaaa", "b"), strcspn("aaaaaa", "b"));
}
END_TEST

//specific_test

START_TEST(specific_symbol)
{
    ck_assert_int_eq(s21_strcspn("Hel\nlo", "\n"), strcspn("Hel\nlo", "\n"));
}
END_TEST


Suite *strcspn_suite(void)
{
    Suite *s = suite_create("Strcspn_module");

    TCase* tc_basic = tcase_create("Basic Tests");
    tcase_add_test(tc_basic, symbol_start);
    tcase_add_test(tc_basic, symbol_center);
    tcase_add_test(tc_basic, symbol_end);
    suite_add_tcase(s, tc_basic);


    TCase *tc_empty = tcase_create("Empty Tests");
    tcase_add_test(tc_empty, str1_empty);
    tcase_add_test(tc_empty, str2_empty);
    tcase_add_test(tc_empty, str_empty);
    suite_add_tcase(s, tc_empty);


    TCase *tc_coincidence = tcase_create("Coincidence Tests");
    tcase_add_test(tc_coincidence, complete_coincidences);
    tcase_add_test(tc_coincidence, absence_coincidences);
    suite_add_tcase(s, tc_coincidence);

    TCase *tc_specific = tcase_create("Specific Tests");
    tcase_add_test(tc_specific, specific_symbol);
    suite_add_tcase(s, tc_specific);

    return s;

}