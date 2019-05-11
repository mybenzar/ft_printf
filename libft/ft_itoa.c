/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:32:48 by malavent          #+#    #+#             */
/*   Updated: 2019/05/11 12:23:34 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_uintsize(uintmax_t n)
{
	int size;

	size = 0;
	while (n / 10)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}

char		*ft_itoa(uintmax_t n)
{
	int		size;
	char	*itoa;

	size = 0;
	size += ft_uintsize(n);
	if (!(itoa = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	itoa[size] = '\0';
	while (--size >= 0)
	{
		itoa[size] = (n % 10) + 48;
		n = (n / 10);
	}
	return (itoa);
}
