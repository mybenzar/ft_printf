/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 12:16:27 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/11 12:17:13 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	str_padding(t_flags *flag, char *str, int min_width)
{
	if (flag->id_conv == 'f' && flag->plus)
	{
		flag->len++;
		ft_putchar(flag->plus);
	}
	if (flag->dot != 0)
		ft_putnstr(str, min_width);
	if (flag->space != 0)
		print_nchar(flag->space, ' ');
}

static void	str_no_padding(t_flags *flag, char *str, int min_width)
{
	if (flag->space != 0)
		print_nchar(flag->space, ' ');
	if (flag->id_conv == 'f' && flag->plus)
	{
		flag->len++;
		ft_putchar(flag->plus);
	}
	if (flag->dot != 0)
		ft_putnstr(str, min_width);
}

void	str_converter(t_flags *flag, char *str)
{
	int min_width;
	int	len;

	if (str == NULL)
	{
		if (!(str = ft_strdup("(null)")))
			return ;
	}
	len = (int)ft_strlen(str);
	min_width = get_min_width(flag, len);
	if (flag->id_conv == 'f' && flag->plus && flag->space)
		flag->space--;
	if (flag->minus == 1)
		str_padding(flag, str, min_width);
	else
		str_no_padding(flag, str, min_width);
	if (!ft_strcmp(str, "(null)") && flag->dot == 0)
		flag->len = flag->space;
	else
		flag->len += flag->space + ((min_width > len) ? len : min_width);
	if (!ft_strcmp("(null)", str))
		ft_strdel(&str);
}
