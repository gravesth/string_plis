#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) { 
	const unsigned char *ptr1 = (unsigned char *)str1;
	const unsigned char *ptr2 = (unsigned char *)str2;

	for (s21_size_t i = 0; i < n; i++) {
		if(ptr1[i] != ptr2[i]) { 
			if (ptr1[i] < ptr2[i]) return -1; 
			else return 1; 
		}
	}
	return 0; 	
}
