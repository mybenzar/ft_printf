/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 12:13:54 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/11 12:15:28 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_converter(t_flags *flag, unsigned char c)
{
	fill_zero_space(flag, 1);
	if (flag->minus == 1)
	{
		ft_putchar(c);
		if (flag->zero && flag->id_conv == 'n')
		{
			flag->len += flag->zero;
			print_nchar(flag->zero, '0');
		}
		if (flag->space != 0)
			print_nchar(flag->space, ' ');
	}
	else
	{
		if (flag->space != 0)
			print_nchar(flag->space, ' ');
		if (flag->zero && flag->id_conv == 'n')
		{
			flag->len += flag->zero;
			print_nchar(flag->zero, '0');
		}
		ft_putchar(c);
	}
	flag->len += 1 + flag->space;
}
