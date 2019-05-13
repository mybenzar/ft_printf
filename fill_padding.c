/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 11:44:42 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/13 14:51:12 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	min_width_no_precision(t_flags *flag, int len)
{
	if (flag->dot == 0)
	{
		flag->space = flag->width;
		if (len == 0)
			return (len);
		else
			return (flag->width);
	}
	else if (flag->dot < 0)
	{
		if (flag->width == 0 || flag->width <= len)
			return (len);
		else if (flag->width > len)
		{
			flag->space = flag->width - len;
			return (len);
		}
	}
	return (-1);
}

int			get_min_width(t_flags *flag, int len)
{
	if (flag->dot <= 0)
		return (min_width_no_precision(flag, len));
	else
	{
		if (flag->dot > len)
		{
			if (flag->width > len)
				flag->space = flag->width - len;
			else
				return (len);
		}
		else if (flag->dot < flag->width)
		{
			flag->space = flag->width - flag->dot;
			return (flag->dot);
		}
		else if (flag->dot > flag->width)
			return (flag->dot);
		return (flag->width);
	}
	return (-1);
}

static void	fill_no_prec(t_flags *flag, int len)
{
	int plus;

	plus = (flag->plus == 0 ? 0 : 1);
	if (flag->width > len)
	{
		if (flag->zero == 1)
		{
			if (flag->space == 1 && flag->plus == '-')
				flag->space = 0;
			flag->zero = flag->width - len - plus - (flag->space == 0 ? 0 : 1);
			if (flag->dot == 0)
				flag->space = flag->width - len - plus;
		}
		else
			flag->space = flag->width - len - plus;
	}
	else
		flag->zero = 0;
}

void		fill_zero_space(t_flags *flag, int len)
{
	int plus;

	plus = (flag->plus == 0 ? 0 : 1);
	if (flag->dot <= 0)
		fill_no_prec(flag, len);
	else if (flag->dot > 0 && flag->width != 0)
	{
		if (flag->dot > len && flag->dot > flag->width)
			flag->zero = flag->dot - len;
		else if (flag->dot > len && flag->dot < flag->width)
		{
			flag->zero = flag->dot - len;
			flag->space = flag->width - flag->dot - plus;
		}
		else if (flag->dot <= len && flag->dot > flag->width)
			flag->zero = flag->dot - len;
		else if (flag->dot <= len && flag->dot < flag->width
				&& len < flag->width)
			flag->space = flag->width - len - plus;
	}
	else if (flag->dot != 0 && flag->width == 0)
		flag->zero = ((flag->dot > len) ? (flag->dot - len) : 0);
}
