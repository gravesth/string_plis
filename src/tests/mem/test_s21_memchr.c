#include "../../s21_string.h"

START_TEST(test_memchr_basic) {
  char mass[] = "hello world"; 
  char ch = '0'; 

  const int *orig = memchr(mass, ch, strlen(mass));
  const int *s21_result = s21_memchr(mass, ch, strlen(mass));

  ck_assert_ptr_eq(orig, s21_result);
}
END_TEST

START_TEST(test_memchr_array) { 
  char mass[] = {0x12, 0x34, 0x123, 0x2b}; 
  unsigned ch = 0x123;

  const int *orig = memchr(mass, ch, sizeof(mass));
  const int *s21_result = s21_memchr(mass, ch, sizeof(mass));
  
  ck_assert_ptr_eq(orig, s21_result);

}

Suite *memchr_suite(void) {
  Suite *s = suite_create("Tests");
  TCase *tc = tcase_create("Tests");
  tcase_add_test(tc, test_memchr_basic);
  tcase_add_test(tc, test_memchr_array);
  suite_add_tcase(s, tc);
  return s;
}
