/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 09:06:42 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/15 09:10:48 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_prec(char *ret, char *str, int size)
{
	int j;
	int i;

	i = 0;
	j = ft_strlen(str);
	while (i <= size && i < j)
	{
		ret[i] = str[i];
		i += 1;
	}
	ret[i] = '\0';
}

int		only_nine(char *ret)
{
	int i;

	i = 0;
	while (ret[i] != '\0')
	{
		if (ret[i] != '9')
			return (0);
		i++;
	}
	return (1);
}
