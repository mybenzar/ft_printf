/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:44:53 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/14 12:26:34 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	float_padding(t_flags *flag, char **res)
{
	//print_nb_padding(flag, res[1]);
	ft_putnstr(res[1], flag->dot);
	if (flag->space != 0)
		print_nchar(flag->space, ' ');
}

static void	float_no_padding(t_flags *flag, char **res, int len_dec)
{
	if (flag->dot > len_dec)
		flag->zero = flag->dot - len_dec;
	ft_putnstr(res[1], flag->dot);
	print_nchar(flag->zero, '0');
}

static void	print_whole(t_flags *flag, char **res, int len_whole)
{
	int		width_whole;
	int		zero_whole;
	int		tmp_space;

	zero_whole = flag->zero != 0 ? 1 : 0;
	width_whole = flag->width - flag->dot - (flag->plus != 0 ? 1 : 0) - 1;
	flag->width = flag->width - len_whole - (flag->plus == '-' ? 1 : 0);
	fill_zero_space(flag, flag->dot);
	if (width_whole > len_whole && zero_whole)
	{
		flag->zero = width_whole - len_whole;
		flag->space -= flag->zero;
	}
	if (flag->dot != 0 && flag->plus != '-' && flag->space)
		flag->space--;
	tmp_space = flag->space;
	if (flag->minus == 1)
		flag->space = 0;
	print_nb(flag, res[0]);
	flag->space = tmp_space;
}

void		print_float(t_flags *flag, char **res)
{
	int		len_dec;
	int		len_whole;

	if (flag->space && flag->plus != '-')
		flag->space++;
	if (flag->dot < 0)
		flag->dot = 6;
	ft_round(res, flag);
	len_dec = ft_strlen(res[1]);
	len_whole = ft_strlen(res[0]);
	print_whole(flag, res, len_whole);
	flag->zero = 0;
	if (flag->dot != 0 || flag->sharp)
	{
		flag->len++;
		ft_putchar('.');
	}
	if (flag->minus == 1)
		float_padding(flag, res);
	else
		float_no_padding(flag, res, len_dec);
	free_res(res);
	flag->len += len_whole + flag->dot + flag->space;
	flag->len += (flag->plus != 0 ? 1 : 0);
}
