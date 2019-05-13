/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:49:50 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/13 10:51:57 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_size(char *spec, int *i)
{
	int size;
	int k;

	k = 0;
	size = 0;
	while (ft_isdigit(spec[k]) && spec[k])
	{
		size = (size * 10) + (spec[k] - 48);
		*i += 1;
		k++;
	}
	return (size);
}

void	get_size_width(t_flags *flags, int *i)
{
	if (ft_isdigit(flags->spec[*i]) && flags->spec[*i] != '0'
		&& flags->width == 0)
		flags->width = get_size((flags->spec) + *i, i);
	if (flags->spec[*i] == '.')
	{
		*i += 1;
		flags->dot = get_size(flags->spec + *i, i);
	}
}
