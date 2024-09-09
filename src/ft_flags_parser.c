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
 
enum e_flags	ft_flags_parser(const char **fmt, int *number)
{
	char			flags_character[16];
	char			*flag;
	enum e_flags	flags;
	int					flag_index;

	flags = NONE;
	ft_strlcpy(flags_character, FLAGS_CHARACTERS, -1);
	flag = ft_strchr(flags_character, **fmt);
	while (flag)
	{
		flag_index = flag - flags_character;
		if (ft_isdigit(*flag))
			*number = ft_atoi_track(fmt);
		else
			*fmt = *fmt + 1;

		if (*flag == ' ' || *flag == '.' || *flag == '-')
			*number = ft_atoi_track(fmt);
		if (ft_isdigit(*flag))
			flags |= SPACE;
		else
			flags |= (1 << flag_index);
		flag = ft_strchr(flags_character, **fmt);
	}
	return (flags);
}
