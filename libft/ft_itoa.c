/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:32:48 by malavent          #+#    #+#             */
/*   Updated: 2019/04/02 17:01:22 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//remettre en uintmax ?

/*static int	ft_sign(uintmax_t n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	ft_intmin(uintmax_t *n)
{
	if (*n == -2147483648)
	{
		*n = -147483648;
		return (1);
	}
	return (0);
}*/

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
//	int		negative;
	int		size;
	char	*itoa;
//	int		intmin;

	size = 0;
//	negative = ft_sign(n);
//	intmin = ft_intmin(&n);
//	n = (negative == 1) ? -n : n;
	size += ft_uintsize(n) /*+ negative + intmin*/;
	if (!(itoa = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	itoa[size] = '\0';
/*	if (negative)
	{
		if (intmin)
			itoa[1] = 50;
		itoa[0] = '-';
	}*/
	while (--size >= 0/*(negative + intmin)*/)
	{
		itoa[size] = (n % 10) + 48;
		n = (n / 10);
	}
	return (itoa);
}
