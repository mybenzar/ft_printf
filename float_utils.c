/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 09:05:33 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/15 09:05:59 by mybenzar         ###   ########.fr       */
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
