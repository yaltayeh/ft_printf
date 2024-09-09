/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:52:52 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/08 19:53:42 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/*  ************************************************************************** */
  
#include "ft_printf.h"
 
enum e_flags	ft_flags_format(const char **fmt, int *number)
{
	char			flags_character[7];
	char			*flag;
	enum e_flags	flags;

	flags = NONE;
	ft_strlcpy(flags_character, FLAGS_CHARACTERS, -1);
	flag = ft_strchr(flags_character, **fmt);
	while (flag)
	{
		*fmt = *fmt + 1;
		if (*flag == ' ' || *flag == '0' || *flag == '.')
			*number = ft_atoi_track(fmt);
		flags |= (1 << (flag - flags_character));
		flag = ft_strchr(flags_character, **fmt);
	}
	return (flags);
}
