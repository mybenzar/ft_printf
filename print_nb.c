/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 11:41:59 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/13 10:43:47 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	sharp_zero_space(t_flags *flag, int len)
{
	int diff;

	diff = (flag->id_conv == 'o' ? 1 : 2);
	if ((flag->width > len || flag->dot > len) && flag->sharp == 1
		&& (flag->space || flag->zero) && ft_strchr("oxX", flag->id_conv))
	{
		if (flag->zero && flag->space)
			flag->space -= (flag->id_conv == 'o' ? 1 : 2);
		else if (flag->zero && (flag->dot > len + diff
			|| flag->width > len + diff))
			flag->zero -= (flag->id_conv == 'o' ? 1 : 2);
		else if (flag->space)
			flag->space -= (flag->id_conv == 'o' ? 1 : 2);
	}
}

static void	memory_conv(t_flags *flag, uintmax_t nb)
{
	if (nb == 0)
	{
		ft_putstr("0x");
		flag->len += 2;
	}
	flag->id_conv = 'x';
}

static void	inv_plus_sign(t_flags *flag)
{
	ft_putchar(' ');
	flag->len++;
	flag->space--;
	flag->minus = 1;
}

static void	print_int(t_flags *flag, char *nb_str, uintmax_t nb)
{
	int	len;

	len = (int)ft_strlen(nb_str);
	if (flag->id_conv == 'X')
		nb_str = ft_strupper(nb_str);
	fill_zero_space(flag, len);
	if (nb != 0)
		sharp_zero_space(flag, len);
	if (flag->dot < len && flag->dot != -1)
		flag->zero = 0;
	if (flag->minus == 'i')
		inv_plus_sign(flag);
	if (flag->minus == 1)
		print_nb_padding(flag, nb_str);
	else
		print_nb(flag, nb_str);
	flag->len += len;
}

void		int_converter(t_flags *flag, uintmax_t nb)
{
	char	*nb_str;

	if (flag->id_conv == 'p')
		memory_conv(flag, nb);
	if (nb == 0 && flag->sharp == 1 && (flag->id_conv != 'o'))
		flag->sharp = 0;
	if (flag->dot == 0 && nb == 0)
	{
		flag->zero = 0;
		if (!(nb_str = ft_strdup("")))
			return ;
	}
	else if (!(nb_str = ft_itoabase(nb, get_base(flag->id_conv))))
		return ;
	print_int(flag, nb_str, nb);
	ft_strdel(&nb_str);
	if (flag->plus)
		flag->len++;
	flag->len += flag->zero + flag->space;
}
