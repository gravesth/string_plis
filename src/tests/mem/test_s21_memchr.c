#include "../../s21_string.h"
#include <check.h>
#include <string.h>

START_TEST(test_memchr_basic) {
  char mass[] = "hello world"; 
  char ch = '0'; 

  const int *orig = memchr(mass, ch, strlen(mass));
  const int *s21_result = s21_memchr(mass, ch, strlen(mass));

  ck_assert_ptr_eq(orig, s21_result);
}
END_TEST

START_TEST(test_memchr_array) { 
  char *mass = {"123123", "dsfasdfasd", "dddsasd"}; 
  char ch = '1';

  const int *orig = memchr(mass, ch, strlen(mass));
  const int *s21_result = s21_memchr(mass, ch, strlen(mass));

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

int main() { 
    Suite *s = memchr_suite(); 

    SRunner *sr = srunner_create(s); 
    srunner_run_all(sr, CK_NORMAL);
    int num_failed = srunner_ntests_failed(sr); 
    srunner_free(sr);
    return (num_failed == 0) ? 0 : 1;
}