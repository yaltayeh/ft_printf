#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

#define print(x, ...) \
	printf("%s\n", x);\
	printf("'"x"'\n", __VA_ARGS__); \
	ft_printf("'"x"'\n", __VA_ARGS__);	

#define TEST(i, x)\
	printf("\n%d: ", i);\
	x;

int main()
{
	TEST(10, print(" % d ", 0));
	TEST(12, print(" % d ", 1));
	TEST(13, print(" % d ", 9));
	TEST(14, print(" % d ", 10));
	TEST(15, print(" % d ", 11));
	TEST(16, print(" % d ", 15));
	TEST(17, print(" % d ", 16));
	TEST(18, print(" % d ", 17));
	TEST(19, print(" % d ", 99));
	TEST(20, print(" % d ", 100));
	TEST(21, print(" % d ", 101));
	TEST(31, print(" % d ", INT_MAX));
	TEST(34, print(" % d ", LONG_MIN));
	TEST(38, print(" % d % d % d % d % d % d % d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	TEST(39, print(" % i ", 0));
	TEST(41, print(" % i ", 1));
	TEST(42, print(" % i ", 9));
	TEST(43, print(" % i ", 10));
	TEST(44, print(" % i ", 11));
	TEST(45, print(" % i ", 15));
	TEST(46, print(" % i ", 16));
	TEST(47, print(" % i ", 17));
	TEST(48, print(" % i ", 99));
	TEST(49, print(" % i ", 100));
	TEST(50, print(" % i ", 101));
	TEST(60, print(" % i ", INT_MAX));
	TEST(63, print(" % i ", LONG_MIN));
	TEST(67, print(" % i % i % i % i % i % i % i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	TEST(67, print(" % i % i % i % i % i % i % i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
}