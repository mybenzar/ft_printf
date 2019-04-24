/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:07:34 by malavent          #+#    #+#             */
/*   Updated: 2019/03/21 17:00:07 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_inbase(int base, char c)
{
	if (base <= 10)
		return (c >= '0' && c <= '0' + base);
	else
	{
		if (c >= '0' && c <= '9')
			return (1);
		return ((c >= 'A' && c <= 'A' + (base % 10 - 1))
		|| (c >= 'a' && c <= 'a' + (base % 10 - 1)));
	}
}

static void	ft_trim_blanks(const char *str, int *i)
{
	*i = 0;
	while (str[*i] == '\n' || str[*i] == '\v' || str[*i] == '\f'
	|| str[*i] == ' ' || str[*i] == '\r')
		*i += 1;
}

static int	ft_signe(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int			ft_atoi_base(const char *str, int base)
{
	int	i;
	int signe;
	int res;

	signe = 1;
	if (base < 1 || base > 16)
		return (0);
	ft_trim_blanks(str, &i);
	if ((str[i] == '-' || str[i] == '+'))
	{
		signe = ft_signe(str[i]);
		if (base != 10 && signe == -1)
			return (0);
		i++;
	}
	while (ft_is_inbase(base, str[i]))
	{
		res = res * base + ft_convert_dec(str[i], base);
		i++;
	}
	res = res * signe;
	return (res);
}
