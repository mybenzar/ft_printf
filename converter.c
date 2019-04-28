/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:03:58 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/28 11:54:59 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int		get_base(char conv)
{
	if (conv == 'd' || conv == 'i' || conv == 'u')
		return (10);
	if (conv == 'o')
		return (8);
	if (conv == 'x' || conv == 'X' || conv == 'p')
		return (16);
	return (-1);
}

static int		min_width_no_precision(t_flags *flag, int len)
{
	if (flag->dot == 0)
	{
		flag->space = flag->width;
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

static int		get_min_width(t_flags *flag, int len)
{
	if (flag->dot <= 0)
		return (min_width_no_precision(flag, len));
	else
	{
		//if (flag->width == 0)
		//	return (len);
		if (flag->dot > len)
			flag->space = flag->width - len;
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

static void		fill_zero_space(t_flags *flag, int len)
{
	int	tmp;
	int plus;

	plus = (flag->plus == 0 ? 0 : 1);
	if (flag->id_conv == 'f')
		tmp = flag->dot;
	if (flag->dot <= 0 && flag->width > len)
	{
		// a ete recemment modifie. avant il n yavait pas de condition if, et seul le else existait
		if (flag->zero == 1)
		{
			flag->zero = flag->width - len - plus - (flag->space == 0 ? 0 : 1);
			if (flag->dot == 0)
				flag->space = flag->width - len - plus;
		}
		else
			flag->space = flag->width - len - plus;
	}
	if (flag->dot <= 0 && flag->width <= len)
		flag->zero = 0;
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
	if (flag->id_conv == 'f')
		flag->dot = tmp;
	if (flag->sharp == 1 && (flag->space || flag->zero) && ft_strchr("oxX", flag->id_conv))
	{
		if (flag->zero)
			flag->zero -= (flag->id_conv == 'o' ? 1 : 2);
		if (flag->space)
			flag->space -= (flag->id_conv == 'o' ? 1 : 2);
	}
	if (DEBUG)
	{
		printf("at the end of zero fill, flag->space = %d\n", flag->space);
		printf("flag->zero = %d\n", flag->zero);
	}
}

void		print_nchar(int size, char c)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putchar(c);
		i++;
	}
}

void		ft_putnstr(char *str, int size)
{
	int i;

	i = 0;
	while (i < size && str[i] != '\0')
		ft_putchar(str[i++]);
}

static void		print_exp(t_flags *flag)
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

static void		print_nb_padding(t_flags *flag, char *nb_str)
{
	if (flag->plus == '+')
		ft_putchar('+');
	if (flag->plus == '-')
		ft_putchar('-');
	if ((flag->sharp == 1 && ft_strcmp(nb_str, "") && ft_strcmp(nb_str, "0"))
		|| (flag->sharp == 1 && flag->id_conv == 'o'))
		print_exp(flag);
	if (flag->zero != 0)
		print_nchar(flag->zero, '0');
	if (ft_strcmp(nb_str, "no"))
		ft_putstr(nb_str);
	if (flag->space != 0)
		print_nchar(flag->space, ' ');
}

static void		print_nb(t_flags *flag, char *nb_str)
{
	if (flag->space != 0)
		print_nchar(flag->space, ' ');
	if (flag->plus == '+')
		ft_putchar('+');
	if (flag->plus == '-')
		ft_putchar('-');
	if ((flag->sharp == 1 && ft_strcmp(nb_str, "") && ft_strcmp(nb_str, "0"))
		|| (flag->sharp == 1 && flag->id_conv == 'o'))
		print_exp(flag);
	if (flag->zero != 0)
		print_nchar(flag->zero, '0');
	ft_putstr(nb_str);
}

void	char_converter(t_flags *flag, unsigned char c)
{
	fill_zero_space(flag, 1);
	if (flag->minus == 1)
	{
		ft_putchar(c);
		if (flag->space != 0)
			print_nchar(flag->space, ' ');
	}
	else
	{
		if (flag->space != 0)
			print_nchar(flag->space, ' ');
		ft_putchar(c);
	}
	flag->len = 1 + flag->space;
}

char *ft_strupper(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		str[i] = ft_toupper(str[i]);
	return (str);
}

static double	round(long long dec, char sign)
{
	if (sign == '-') 
		dec = dec - 5;
	else
		dec = dec + 5;
	return (dec / 10);
}

static char	*dec_to_rounded_a(long double x, int prec, char sign)
{
	uintmax_t	dec;
	char		*dec_str;

	dec = round(((x - (long)x) * ft_power(10, prec + 1)), sign);
	if (!(dec_str = ft_itoa(dec)))
		return (NULL);
	return (dec_str);
}

void	int_converter(t_flags *flag, uintmax_t nb)
{
	char	*nb_str;
	int		len;
	
	if (DEBUG)
		printf("nb to be processed in int conv = %lu\n", nb);
	if (flag->id_conv == 'p')
	{	
		if (nb == 0)
		{
			ft_putstr("0x");
			flag->len += 2;
		}
		flag->id_conv = 'x';
	}
	if (flag->dot == 0 && nb == 0)
	{
		flag->zero = 0;
		if (!(nb_str = ft_strdup("")))
			return ;
	}
	else if (!(nb_str = ft_itoabase(nb, get_base(flag->id_conv))))
		return ;
	if (DEBUG)
		printf("nb_str to be printed before process in int conv = %s\n", nb_str);
	if (flag->id_conv == 'X')
		nb_str = ft_strupper(nb_str);
	len = (int)ft_strlen(nb_str);
	if (DEBUG)
		printf("in intconv, len = %d\n", len);
	fill_zero_space(flag, len);
	if (flag->dot < len && flag->dot != -1)
		flag->zero = 0;
	if (flag->minus == 'i')
	{
		ft_putchar(' ');
		flag->len++;
		flag->space--;
		flag->minus = 1;
	}
	if (flag->minus == 1)
		print_nb_padding(flag, nb_str);
	else
		print_nb(flag, nb_str);
	if (DEBUG)
	{
		printf("\n\nin int_converter, flag->len = %d\n", flag->len);
		printf("flag->zero = %d\n", flag->zero);
		printf("flag->plus = %d\n", flag->plus);
		printf("flag->space = %d\n", flag->space);
		printf("len = %d\n\n", len);
	}
	free(nb_str);
	if (flag->plus)
		flag->len++;
	flag->len += len + flag->zero + flag->space;
	if (DEBUG)
		printf("final int conv flag->len = %d\n", flag->len);
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
	if (flag->minus == 1)
	{
		if (flag->dot != 0)
			ft_putnstr(str, min_width);
		if (flag->space != 0)
			print_nchar(flag->space, ' ');
	}
	else
	{
		if (flag->space != 0)
			print_nchar(flag->space, ' ');
		if (flag->dot != 0)
			ft_putnstr(str, min_width);
	}
/*	if (DEBUG)
	{
		printf("before, flag->len = %d\n", flag->len);
		printf("flag->space = %d\n", flag->space);
		printf("min_width = %d\n", min_width);
	}*/
	flag->len = flag->space + ((min_width > len) ? len : min_width);
	//printf("after, flag->len = %d\n", flag->len);
}

void	float_converter(t_flags *flag, long double x)
{
	int		i_part;
	char	*i_str;
	int		len;
	
	i_part = (long)x;
	//a mettre de preference dans le parsing, la valeur par defaut de la precision
	if (flag->dot < 0)
		flag->dot = 6;
/*	if (flag->dot >= 15)
	{
		flag->zero = flag->dot - 14;
		flag->dot = 7;
	}*/
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

