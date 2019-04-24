/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:42:24 by malavent          #+#    #+#             */
/*   Updated: 2018/11/26 11:36:31 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t i;
	size_t j;
	size_t final_size;

	i = (size_t)ft_strlen(dest);
	j = (size_t)ft_strlen(src);
	dest += i;
	if (size <= i)
		return (j + size);
	final_size = size - i - 1;
	while (final_size > 0 && *src)
	{
		*dest++ = *src++;
		final_size--;
	}
	*dest = '\0';
	return (i + j);
}
