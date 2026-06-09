#include "test_runner.h"

int main() {
  SRunner *sr = srunner_create(NULL);
  srunner_add_suite(sr, memcmp_suite());
  srunner_add_suite(sr, memchr_suite());
  srunner_add_suite(sr, strncpy_suite());
  srunner_add_suite(sr, strcspn_suite());
  srunner_run_all(sr, CK_NORMAL);
  int failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (failed == 0) ? 0 : 1;
}
