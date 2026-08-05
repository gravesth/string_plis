#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include <check.h>

Suite *memcmp_suite(void);
Suite *memcpy_suite(void);
Suite *memchr_suite(void);
Suite *strncpy_suite(void);
Suite *strncat_suite(void);
Suite *strerror_suite(void);
Suite *strpbrk_suite(void);
Suite *strtok_suite(void);
#endif
