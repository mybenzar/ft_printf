/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:00:08 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/12 13:00:11 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	float_converter(t_flags *flag, double x)
{
	char **res;

	if (x < 0)
		handle_neg(flag);
	if (!(res = ft_frexp(x)))
		return ;
	if (!res[1])
	{
		str_converter(flag, res[0]);
		ft_strdel(&res[0]);
		ft_strdel(&res[1]);
		free(res);
		res = NULL;
		return ;
	}
	print_float(flag, res);
}

void	lfloat_converter(t_flags *flag, long double x)
{
	char **res;

	if (x < 0)
		handle_neg(flag);
	if (!(res = ft_frexpl(x)))
		return ;
	if (!res[1])
	{
		str_converter(flag, res[0]);
		ft_strdel(&res[0]);
		ft_strdel(&res[1]);
		free(res);
		res = NULL;
		return ;
	}
	print_float(flag, res);
}
