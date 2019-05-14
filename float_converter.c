/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:00:08 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/14 13:32:50 by mybenzar         ###   ########.fr       */
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
	if (res[2][0] == '-')
		flag->plus = '-';
	if (!res[1])
	{
		str_converter(flag, res[0]);
		free_res(res);
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
	if (res[2][0] == '-')
		flag->plus = '-';
	if (!res[1])
	{
		str_converter(flag, res[0]);
		free_res(res);
		return ;
	}
	print_float(flag, res);
}
