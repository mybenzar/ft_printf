/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_float_converter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 10:01:38 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/01 10:01:44 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	float_converter(t_flags *flag, long double x)
{
	int		i_part;
	char	*i_str;
	int		len;
	
	i_part = (long)x;
	//a mettre de preference dans le parsing, la valeur par defaut de la precision
	if (flag->dot < 0)
		flag->dot = 6;
	if (i_part < 0)
		flag->plus = '-';
	if (flag->dot == 0)
	{
		if (x - i_part >= 5)
			x += 1;
		x = i_part;
	}
	if (x - i_part == 0)
	{
		flag->id_conv = 'i';
		flag->dot = -1;
		int_converter(flag, i_part);
		return ;
	}
	if (!(i_str = ft_itoa((long)x)))
		return ;
	len = (int)ft_strlen(i_str) + flag->dot;
	fill_zero_space(flag, len);
	if (flag->dot < len)
		flag->zero = 0;
	if (flag->minus == 1)
	{
		ft_putstr(i_str);
		ft_putchar('.');
		ft_putnstr(dec_to_rounded_a(x, flag->dot, flag->plus), flag->dot);
		print_nb_padding(flag, "no");
	}
	else
	{	
		ft_putstr(i_str);
		ft_putchar('.');
		print_nb(flag, dec_to_rounded_a(x, flag->dot, flag->plus));
	}
	flag->len += len + flag->zero + flag->plus + flag->space + 1;
}
