#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

enum	e_flags
{
	NONE = 0,
	HASH = 1,
	SPACE = 2,
	PLUS = 4,
	MINES = 8,
	ZERO = 16,
	DOT = 32,
};

/*
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

enum	e_conversions
{
	CHAR,
	STRING,
	POINTER,
	DECIMAL,
	INTEGER,
	UNSIGNED_DECIMAL,
	HEXADECIMAL_LOWERCASE,
	HEXADECIMAL_UPPERCASE,
	PERCENT,
};
*/


int	ft_printf(const char *fmt, ...);

#endif
