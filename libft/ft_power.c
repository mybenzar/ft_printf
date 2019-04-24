/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 08:19:14 by malavent          #+#    #+#             */
/*   Updated: 2019/04/01 17:40:09 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_power(int n, int power)
{
	int res;

	res = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power--)
		res = res * n;
	return (res);
}
