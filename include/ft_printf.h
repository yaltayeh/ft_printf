/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:02:23 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/08 20:03:27 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h>

# define CONVENTIONS_CHARACTERS "cspdiuxX%"
# define FLAGS_CHARACTERS "#+ -.0123456789"
# define HEX_BASE "0123456789abcdef"
# define DECIMAL_BASE "0123456789"



typedef enum	e_flags
{
	NONE = 0,
	SHARP = 1 << 0,
	PLUS = 1 << 1,
	SPACE = 1 << 2,
	MINUS = 1 << 3,
	DOT = 1 << 4,
	ZERO = 1 << 5,
	NUMBER = 1 << 6
}	t_flags;

typedef union u_handler_input
{
	char	c;
	char	*str;
	void	*ptr;
	int		i32;
	unsigned int u32;
}	t_handler_input;

typedef struct s_handler_data
{
	t_handler_input input;
	t_flags flags;
	int numbers[8];
	int to_upper;
	int is_digit;
	int is_char;
	int (*handle)(t_handler_input, char **);
} t_handler_data;

int	ft_printf(const char *fmt, ...);

int	ft_main(t_handler_data data);

t_flags	ft_flags_parser(const char **fmt, int *numbers, t_flags flags);

int	ft_printf_redirect(va_list *ap, char conversions, \
				t_flags flags, int *numbers);


/* %c Prints a single character. */
int	ft_char_handle(t_handler_input in, char **out);

/* %s Prints a string (as defined by the common C convention). */
int	ft_str_handle(t_handler_input in, char **out);

/* %p The void * pointer argument has to be printed in hexadecimal format. */
int	ft_pointer_handle(t_handler_input in, char **out);

/*  %d Prints a decimal (base 10) number.
    %i Prints an integer in base 10.        */
int	ft_decimal_handle(t_handler_input in, char **out);

/* %u Prints an unsigned decimal (base 10) number. */
int	ft_u_decimal_handle(t_handler_input in, char **out);

/* %x Prints a number in hexadecimal (base 16) lowercase format. */
/* %X Prints a number in hexadecimal (base 16) uppercase format. */
int	ft_hex_handle(t_handler_input in, char **out);

int	ft_percent_handle(t_handler_input in, char **out);

#endif
