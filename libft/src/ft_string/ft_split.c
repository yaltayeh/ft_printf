/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:31:00 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/08/29 12:27:44 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**init_slices_array(const char *s, char c)
{
	char		**slices;
	const char	*ptr;
	const char	*end;
	size_t		count;

	ptr = s;
	end = s + ft_strlen(s);
	count = 0;
	while (s < end)
	{
		if (*ptr == c || *ptr == '\0')
		{
			if (ptr > s)
				count++;
			s = ptr + !!*ptr;
		}
		ptr++;
	}
	slices = malloc((count + 1) * sizeof(char *));
	if (!slices)
		return (NULL);
	slices[count] = NULL;
	return (slices);
}

static char	**ft_add_new_slice(char ***dest, const char *start, \
							const char *end, size_t index)
{
	size_t	slice_len;
	char	*slice;

	slice_len = end - start;
	slice = malloc(++slice_len);
	if (!slice)
	{
		while (**dest)
			free((*dest)[index--]);
		free(*dest);
		return (NULL);
	}
	ft_strlcpy(slice, start, slice_len);
	(*dest)[index] = slice;
	return (*dest);
}

char	**ft_split(char const *s, char c)
{
	char		**slices;
	const char	*ptr;
	const char	*end;
	size_t		i;

	ptr = s;
	end = s + ft_strlen(s);
	i = 0;
	slices = init_slices_array(s, c);
	if (!slices)
		return (NULL);
	while (s < end)
	{
		if (*ptr == c || *ptr == '\0')
		{
			if (ptr > s)
				if (!ft_add_new_slice(&slices, s, ptr, i++))
					return (NULL);
			s = ptr + !!*ptr;
		}
		ptr++;
	}
	return (slices);
}
