/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:00:16 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/08 20:00:23 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <limits.h>


# define CASE "'%c'", '0'
# define TEST "\n"CASE

int main()
{
	int a = ft_printf(TEST);
	int b = printf   (TEST);
	ft_printf("\n%d == %d\n", a, b);
}
