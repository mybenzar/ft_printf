/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:48:56 by malavent          #+#    #+#             */
/*   Updated: 2019/05/11 12:24:16 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_itoa(int base, uintmax_t value, size_t size)
{
	char *itoa;

	if (!(itoa = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	itoa[size] = '\0';
	while (value >= (uintmax_t)base && size)
	{
		itoa[size - 1] = ft_convert_itoc(value % base);
		value = value / base;
		size--;
	}
	itoa[0] = value != 0 ? ft_convert_itoc(value) : '0';
	return (itoa);
}

char		*ft_itoabase(uintmax_t value, int base)
{
	char	*itoa;
	size_t	size;

	if (base == 10)
		return (ft_itoa(value));
	if (value == 0)
		return (ft_itoa(0));
	size = ft_numlen_base(value, base);
	itoa = ft_fill_itoa(base, value, size);
	return (itoa);
}
