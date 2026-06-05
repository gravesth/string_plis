#include "../../s21_string.h"

START_TEST(test_memcmp_basic){ 
	char mass1[] = "hello world1";
	char mass2[] = "hello world2";

	int orig = memcmp(mass1, mass2, 12); 
	int s21_result = s21_memcmp(mass1, mass2, 12); 

	ck_assert_int_eq(orig, s21_result); 
	
}
END_TEST



