#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define print(x, ...) \
	printf("ft_printf(\"%s\", %s)\n", x, #__VA_ARGS__);\
	a = printf("'"x"'\n", __VA_ARGS__); \
	b = ft_printf("'"x"'\n", __VA_ARGS__); \
	printf("%d == %d\n", a, b);	

#define TEST(i, x)\
	printf("\n%d: ", i);\
	x

int main()
{
	int a, b;

	printf("'%-4s'", "12345678");
	TEST(9, print("%7.7s|%7.3s", "hello", "world"));
	return 0;
	TEST(29, print(" %-1p %-2p ", 0, 0));
	TEST(148, print(" %-4X ", 9));
	TEST(149, print(" %-1X ", 10));
	TEST(151, print(" %-3X ", 15));
	TEST(152, print(" %-4X ", 16));
	TEST(153, print(" %-5X ", 17));
	TEST(154, print(" %-1X ", 99));
	TEST(157, print(" %-1X ", -9));
	TEST(167, print(" %-10X ", INT_MIN));
	TEST(168, print(" %-11X ", LONG_MAX));
	TEST(169, print(" %-12X ", LONG_MIN));
	TEST(170, print(" %-13X ", UINT_MAX));
	TEST(171, print(" %-14X ", ULONG_MAX));
	TEST(172, print(" %-15X ", 9223372036854775807LL));
	TEST(173, print(" %-9X %-10X %-11X %-12X %-13X %-14X %-15X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	TEST(118, print(" %04X ", 9));
	TEST(119, print(" %01X ", 10));
	TEST(121, print(" %03X ", 15));
	TEST(122, print(" %04X ", 16));
	TEST(123, print(" %05X ", 17));
	TEST(124, print(" %01X ", 99));
	TEST(127, print(" %01X ", -9));
	TEST(137, print(" %010X ", INT_MIN));
	TEST(138, print(" %011X ", LONG_MAX));
	TEST(139, print(" %012X ", LONG_MIN));
	TEST(140, print(" %013X ", UINT_MAX));
	TEST(141, print(" %014X ", ULONG_MAX));
	TEST(142, print(" %015X ", 9223372036854775807LL));
	TEST(143, print(" %09X %010X %011X %012X %013X %014X %015X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	TEST(128, print(" %.2X ", 1));
	TEST(130, print(" %.2X ", 10));
	TEST(131, print(" %.3X ", 11));
	TEST(132, print(" %.4X ", 15));
	TEST(133, print(" %.5X ", 16));
	TEST(134, print(" %.6X ", 17));
	TEST(137, print(" %.3X ", 101));
	TEST(148, print(" %.9X ", INT_MIN));
	TEST(149, print(" %.10X ", LONG_MAX));
	TEST(150, print(" %.11X ", LONG_MIN));
	TEST(151, print(" %.12X ", UINT_MAX));
	TEST(152, print(" %.13X ", ULONG_MAX));
	TEST(153, print(" %.14X ", 9223372036854775807LL));
	TEST(154, print(" %.8X %.9X %.10X %.11X %.12X %.13X %.14X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	TEST(1, print(" %#x ", 0));
	TEST(25, print(" %#x ", LONG_MIN));
	TEST(29, print(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	TEST(31, print(" %#X ", 0));
	TEST(55, print(" %#X ", LONG_MIN));
	TEST(59, print(" %#X %#X %#X %#X %#X %#X %#X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	TEST(2, print(" % 1s", ""));
	TEST(3, print("% 1s ", ""));
}

