/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:09:37 by malavent          #+#    #+#             */
/*   Updated: 2019/04/02 20:54:37 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen_base(uintmax_t value, uintmax_t base)
{
	static size_t size = 0;

	if (value < base)
		size++;
	else
	{
		ft_numlen_base(value / base, base);
		ft_numlen_base(value % base, base);
	}
	return (size);
}
