/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:03:58 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/04 15:38:54 by mybenzar         ###   ########.fr       */
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
		//if (flag->width == 0)
		//	return (len);
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
//	int	tmp;
	int plus;

	plus = (flag->plus == 0 ? 0 : 1);
//	if (flag->id_conv == 'f')
//		tmp = flag->dot;
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
	if (DEBUG)
	{
		printf("her,e flag->dot = %d\n", flag->dot);
		printf("her,e flag->space = %d\n", flag->space);
		printf("here, flag->zero = %d\n", flag->zero);
		printf("here, flag->width = %d\n", flag->width);
		printf("here, len = %d\n", len);
		printf("flag->sharp = %d\n", flag->sharp);
	}
//	if (flag->id_conv == 'f')
//		flag->dot = tmp;
	if (flag->width > len && flag->sharp == 1
		&& (flag->space || flag->zero) && ft_strchr("oxX", flag->id_conv))
	{
		if (flag->zero /*&& flag->dot < len*/)
			flag->zero -= (flag->id_conv == 'o' ? 1 : 2);
		if (flag->space/* && flag->dot < len*/)
			flag->space -= (flag->id_conv == 'o' ? 1 : 2);
	}
	if (DEBUG)
	{
		printf("at the end of zero fill, flag->space = %d\n", flag->space);
		printf("flag->zero = %d\n", flag->zero);
	}
}

// regler sur papier le probleme des flags->zero flag->space

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
	if (flag->plus == '+' && flag->id_conv != 'f')
		ft_putchar('+');
	if (flag->plus == '-' && flag->id_conv != 'f')
		ft_putchar('-');
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
	if (flag->plus == '+' && flag->id_conv != 'f')
		ft_putchar('+');
	if (flag->plus == '-' && flag->id_conv != 'f')
		ft_putchar('-');
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
	//min_width = ft_strcmp(str, "(null)") == 0 ? get_min_width(flag, 0) : get_min_width(flag, len);
	if (DEBUG)
	{
		printf("string to be printed in str_conv  = %s\n", str);
		printf("min_width = %d\n", min_width);
	}
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
}

char	*ft_round(char *str, char sign, int prec)
{
	char	*tmp;
	char	*five;
	char	*ret;
	int		i;

	i = 0;
	if (!ft_strcmp(str, "0"))
		return ("0");
	if (!(ret = (char *)malloc(sizeof(char) * prec)))
		return (NULL);
	while (i <= prec)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	if (!(five = ft_strdup("5")))
		return (NULL);
	if (sign == '-')
	{
		if (!(tmp = ft_strdup(ret)))
			return (NULL);
		free(ret);
		ret = vlq_sub(tmp, five);
		free(tmp);
	}
	else
	{
		if (!(tmp = ft_strdup(ret)))
			return (NULL);
		free(ret);
		ret = vlq_sum(tmp, five);
		free(tmp);
	}
	return (ret);
}

/*
**	---> 
*/

void	float_converter(t_flags *flag, double x)
{
	int len;
	char **res;

	res = ft_frexp(x);
	len = ft_strlen(res[0]) + ft_strlen(res[1]);
	if (flag->dot < 0)
		flag->dot = 6;
	if (x < 0)
		flag->plus = '-';
	fill_zero_space(flag, len);
	if (flag->dot < len)
		flag->zero = 0;
	if (flag->minus == 1)
	{
		ft_putstr(res[0]);
		ft_putchar('.');
		print_nb_padding(flag, "no");
	}
	else
	{	
		ft_putstr(res[0]);
		ft_putchar('.');
		print_nb(flag, ft_round(res[1], flag->plus, flag->dot));
	}
	flag->len += len + flag->zero + flag->plus + flag->space + 1;
}

void	lfloat_converter(t_flags *flag, long double x)
{
	int len;
	int len_dec;
	char **res;

	res = ft_frexpl(x);
	len_dec = ft_strlen(res[1]);
	len = ft_strlen(res[0]) + len_dec;
	if (flag->dot < 0)
		flag->dot = 6;
	if (x < 0)
		flag->plus = '-';
	fill_zero_space(flag, len_dec);
	if (flag->dot < len_dec)
		flag->zero = 0;
	if (flag->minus == 1)
	{
		if (flag->plus == '+')
			ft_putchar('+');
		if (flag->plus == '-')
			ft_putchar('-');
		ft_putstr(res[0]);
		ft_putchar('.');
	//	ft_putnstr(ft_round(res[1], flag->plus, flag->dot), flag->dot);
		print_nb_padding(flag, "no");
	}
	else
	{	
		if (flag->plus == '+')
			ft_putchar('+');
		if (flag->plus == '-')
			ft_putchar('-');
		ft_putstr(res[0]);
		ft_putchar('.');
		print_nb(flag, ft_round(res[1], flag->plus, flag->dot));
	//	ft_putnstr(ft_round(res[1], flag->plus, flag->dot), flag->dot);
	}
	flag->len += len + flag->zero + flag->plus + flag->space + 1;
}
