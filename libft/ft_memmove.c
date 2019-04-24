/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:36:33 by malavent          #+#    #+#             */
/*   Updated: 2018/11/26 11:36:22 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t len)
{
	char		*p_dest;
	char const	*p_src;

	if (dest == src)
		return (dest);
	if (dest < src)
	{
		p_dest = (char *)dest;
		p_src = (char const *)src;
		while (len--)
			*(p_dest)++ = *(p_src)++;
	}
	else
	{
		p_dest = (char *)dest + (len - 1);
		p_src = (char const *)src + (len - 1);
		while (len--)
			*p_dest-- = *p_src--;
	}
	return (dest);
}
