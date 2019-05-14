/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 11:48:38 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/14 12:19:03 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_base(char conv)
{
	if (conv == 'd' || conv == 'i' || conv == 'u')
		return (10);
	if (conv == 'o')
		return (8);
	if (conv == 'x' || conv == 'X' || conv == 'p')
		return (16);
	return (-1);
}

static void	print_exp(t_flags *flag)
{
	if (flag->id_conv == 'o' || flag->id_conv == 'x' || flag->id_conv == 'X')
		ft_putchar('0');
	if (flag->id_conv == 'x')
	{
		ft_putchar('x');
		flag->len += 2;
		return ;
	}
	if (flag->id_conv == 'X')
		ft_putchar('X');
	flag->len += (flag->id_conv == 'o' ? 1 : 2);
}

static void	print_sign(t_flags *flag)
{
	if (flag->plus == '+')
		ft_putchar('+');
	if (flag->plus == '-')
		ft_putchar('-');
}

void		print_nb_padding(t_flags *flag, char *nb_str)
{
	if (flag->id_conv != 'f')
		print_sign(flag);
	if (flag->id_conv != 'f'
		&& ((flag->sharp == 1 && ft_strcmp(nb_str, "")
		&& ft_strcmp(nb_str, "0"))
		|| (flag->sharp == 1 && flag->id_conv == 'o'
		&& ft_strcmp(nb_str, "0"))))
		print_exp(flag);
	if (flag->zero != 0)
		print_nchar(flag->zero, '0');
	if (ft_strcmp(nb_str, "no"))
		ft_putstr(nb_str);
	if (flag->space != 0)
		print_nchar(flag->space, ' ');
}

void		print_nb(t_flags *flag, char *nb_str)
{
	if (flag->space != 0)
		print_nchar(flag->space, ' ');
	print_sign(flag);
	if (flag->id_conv != 'f'
		&& ((flag->sharp == 1 && ft_strcmp(nb_str, "")
		&& ft_strcmp(nb_str, "0"))
		|| (flag->sharp == 1 && flag->id_conv == 'o'
		&& ft_strcmp(nb_str, "0"))))
		print_exp(flag);
	if (flag->zero != 0)
		print_nchar(flag->zero, '0');
	ft_putstr(nb_str);
}
