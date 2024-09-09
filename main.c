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
	TEST(1, print(" %01d ", 0));
	TEST(3, print(" %04d ", 9));
	TEST(4, print(" %01d ", 10));
	TEST(5, print(" %02d ", 11));
	TEST(6, print(" %03d ", 15));
	TEST(7, print(" %04d ", 16));
	TEST(8, print(" %05d ", 17));
	TEST(9, print(" %01d ", 99));
	TEST(10, print(" %02d ", 100));
	TEST(11, print(" %03d ", 101));
	TEST(15, print(" %04d ", -14));
	TEST(16, print(" %05d ", -15));
	TEST(17, print(" %06d ", -16));
	TEST(21, print(" %09d ", INT_MAX));
	TEST(23, print(" %011d ", LONG_MAX));
	TEST(24, print(" %012d ", LONG_MIN));
	TEST(25, print(" %013d ", UINT_MAX));
	TEST(26, print(" %014d ", ULONG_MAX));
	TEST(27, print(" %015d ", 9223372036854775807LL));
	TEST(28, print(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
}