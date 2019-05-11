/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:09:37 by malavent          #+#    #+#             */
/*   Updated: 2019/05/11 12:24:54 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen_base(uintmax_t value, uintmax_t base)
{
	size_t	size;

	size = 0;
	while (value != 0)
	{
		value /= base;
		size++;
	}
	return (size);
}
