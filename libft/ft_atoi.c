/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:37:23 by malavent          #+#    #+#             */
/*   Updated: 2019/04/02 17:27:23 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	signe;

	i = 0;
	signe = 1;
	res = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\f' || str[i] == '\t'
	|| str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	res = res * signe;
	return (res);
}
