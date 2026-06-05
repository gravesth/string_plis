CС = gcc 
CLAGS = -Wall -Werror -Wextra -Include

# TEST_TARGET = gcov_report
TARGET = s21_string.a

OBJ = mem/s21_memchr.o mem/s21_memcmp.o

CHECK_LIBS = -lcheck -lsubunit -lm -lpthread

$(TARGET): $(OBJ)
	ar rcs $(TARGET) $(OBJ)

all: $(TARGET)

s21_memchr.o: s21_memchr.c
	$(CC) -c mem/s21_memchr.c -o mem/s21_memchr.o

s21_memcmp.o: s21_memcmp
	$(CC) -c mem/s21_memcmp.c -o mem/s21_memcmp.o

test:
	gcc -o test tests/test_s21_memchr.c tests/test_s21_memcmp.c $(CHECK_LIBS) && ./test

style:
	clang-format -i *.c *.h

clean:
	rm -f $(TARGET) && rm -f *.o

.PHONY: all test clean gcov_report

