/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:03:58 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/08 13:48:20 by mybenzar         ###   ########.fr       */
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

static int		get_min_width(t_flags *flag, int len)
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

static void		fill_zero_space(t_flags *flag, int len)
{
	int plus;

	plus = (flag->plus == 0 ? 0 : 1);
	if (DEBUG)
	{
		printf("flag->dot = %d\n", flag->dot);
		printf("flag->width = %d\n", flag->width);
	}
	if (flag->dot <= 0 && flag->width > len)
	{
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

void	print_sign(t_flags *flag)
{
		if (flag->plus == '+')
			ft_putchar('+');
		if (flag->plus == '-')
			ft_putchar('-');
}

static void		print_nb_padding(t_flags *flag, char *nb_str)
{
	if (flag->id_conv != 'f')
		print_sign(flag);
	/*if (flag->plus == '+' && flag->id_conv != 'f')
		ft_putchar('+');
	if (flag->plus == '-' && flag->id_conv != 'f')
		ft_putchar('-');*/
	if ((flag->sharp == 1 && ft_strcmp(nb_str, "") && ft_strcmp(nb_str, "0"))
		|| (flag->sharp == 1 && flag->id_conv == 'o' && ft_strcmp(nb_str, "0")))
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
//	if (flag->id_conv != 'f')
		print_sign(flag);
	/*if (flag->plus == '+' && flag->id_conv != 'f')
		ft_putchar('+');
	if (flag->plus == '-' && flag->id_conv != 'f')
		ft_putchar('-');*/
	if ((flag->sharp == 1 && ft_strcmp(nb_str, "") && ft_strcmp(nb_str, "0"))
		|| (flag->sharp == 1 && flag->id_conv == 'o' && ft_strcmp(nb_str, "0")))
		print_exp(flag);
	if (flag->zero != 0)
		print_nchar(flag->zero, '0');
	ft_putstr(nb_str);
}

void	char_converter(t_flags *flag, unsigned char c)
{
	fill_zero_space(flag, 1);
	if (DEBUG)
	{
		printf("\n\nchar to be printed = %c\n", c);
		printf("flag->space = %d\n", flag->space);
	}
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

char *ft_strupper(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		str[i] = ft_toupper(str[i]);
	return (str);
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

	if (nb == 0 && flag->sharp == 1 && (flag->id_conv != 'o' /*|| (flag->id_conv == 'o' && flag->width))*/))
		flag->sharp = 0;
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
	if (nb != 0 && (flag->width > len || flag->dot > len) && flag->sharp == 1
		&& (flag->space || flag->zero) && ft_strchr("oxX", flag->id_conv))
	{
		if (flag->zero && flag->space)
			flag->space -= (flag->id_conv == 'o' ? 1 : 2);
		else if (flag->zero)
			flag->zero -= (flag->id_conv == 'o' ? 1 : 2);
		else if (flag->space)
			flag->space -= (flag->id_conv == 'o' ? 1 : 2);
	}
	if (DEBUG)
	{
		printf("in int conv after space and zero modif flag->space = %d\n", flag->space);
		printf("flag->zero = %d\n", flag->zero);
	}
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
	ft_strdel(&nb_str);
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
	//min_width = ft_strcmp(str, "(null)") == 0 ? get_min_width(flag, 0) : get_min_width(flag, len);
	if (DEBUG)
	{
		printf("string to be printed in str_conv  = %s\n", str);
		printf("min_width = %d\n", min_width);
	}
	if (flag->id_conv == 'f' && flag->plus)
		flag->space--;
	if (flag->minus == 1)
	{
		if (flag->id_conv == 'f' && flag->plus)
			ft_putchar(flag->plus);
		if (flag->dot != 0)
			ft_putnstr(str, min_width);
		if (flag->space != 0)
			print_nchar(flag->space, ' ');
	}
	else
	{
		if (flag->space != 0)
			print_nchar(flag->space, ' ');
		if (flag->id_conv == 'f' && flag->plus)
			ft_putchar(flag->plus);
		if (flag->dot != 0)
			ft_putnstr(str, min_width);
	}
	if (DEBUG)
	{
		printf("before, flag->len = %d\n", flag->len);
		printf("flag->space = %d\n", flag->space);
		printf("min_width = %d\n", min_width);
		printf("len = %d\n", len);
	}
	if (!ft_strcmp(str, "(null)") && flag->dot == 0)
		flag->len = flag->space;
	else
		flag->len = flag->space + ((min_width > len) ? len : min_width);
	if (!ft_strcmp("(null)", str))
		ft_strdel(&str);
}

char	*ft_round(char *str, int prec)
{
	char	*tmp;
	char	*five;
	char	*ret;
	int		i;

	i = 0;
	if (DEBUG)
		printf("in round, str = %s\n", str);
	if (!ft_strcmp(str, "0"))
		return ("0");
	if (!(ret = (char *)malloc(sizeof(char) * prec)))
		return (NULL);
	while (i <= prec + 1)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	if (DEBUG)
		printf("ret = %s\n", ret);
	if (!(five = ft_strdup("5")))
		return (NULL);
	if (ret[i - 1] == '0')
	{
		ret[i - 1] = '\0';
		ft_strdel(&five);
		return (ret);
	}
	if (ret[i - 1] >= '5')
	{
		if (!(tmp = ft_strdup(ret)))
			return (NULL);
		free(ret);
		ret = vlq_sum(tmp, five);
		ret[i - 1] = '\0';
		ft_strdel(&tmp);
	}
	ft_strdel(&five);
	return (ret);
}

/*
**	---> Double and Long Double Print Functions
*/

void	float_converter(t_flags *flag, double x)
{
	char **res;

	if (x < 0)
		flag->plus = '-';
	if (!(res = ft_frexp(x)))
		return ;
	if (!res[1])
	{
		str_converter(flag, res[0]);
		ft_strdel(&res[0]);
		ft_strdel(&res[1]);
		free(res);
		return ;
	}
	print_float(flag, res);
}

void	lfloat_converter(t_flags *flag, long double x)
{
	char **res;

	if (x < 0)
		flag->plus = '-';
	if (!(res = ft_frexpl(x)))
		return ;
	if (!res[1])
	{
		str_converter(flag, res[0]);
		ft_strdel(&res[0]);
		ft_strdel(&res[1]);
		free(res);
		return ;
	}
	print_float(flag, res);
}

void	print_float(t_flags *flag, char **res)
{
	int	len_dec;
	int	len_whole;
	int	zero_whole;
	int width_whole;

	zero_whole = flag->zero != 0 ? 1 : 0;
	len_dec = ft_strlen(res[1]);
	len_whole = ft_strlen(res[0]);
	if (flag->dot < 0)
		flag->dot = 6;
	if (flag->dot < len_dec + len_whole)
		flag->zero = 0;
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
	print_nb(flag, res[0]);
	flag->zero = 0;
	if (flag->dot != 0 || flag->sharp)
		ft_putchar('.');
	if (flag->minus == 1)
		print_nb_padding(flag, ft_round(res[1], flag->dot - 1));
	else
	{
		if (flag->dot > len_dec)
			flag->zero = flag->dot - len_dec;
		ft_putnstr(ft_round(res[1], flag->dot - 1), flag->dot);
		print_nchar(flag->zero, '0');
	}
	ft_strdel(&res[0]);
	ft_strdel(&res[1]);
	free(res);
	flag->len += len_whole + flag->dot + flag->space + (flag->plus == '-' ? 1 : 0) + (flag->dot > 0 ? 1 : 0);
}

