/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:03:58 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/11 16:15:07 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_round(char *str, int prec)
{
	char	*tmp;
	char	*five;
	char	*ret;
	int		i;

	i = -1;
	if (!ft_strcmp(str, "0"))
		return ("0");
	if (!(ret = (char *)malloc(sizeof(char) * prec + 3)))
		return (NULL);
	while (++i <= prec + 1)
		ret[i] = str[i];
	ret[i] = '\0';
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
		ft_strdel(&ret);
		if (!(ret = vlq_sum(tmp, five)))
			return (NULL);
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
		res = NULL;
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
		res = NULL;
		return ;
	}
	print_float(flag, res);
}

void	free_res(char **res)
{
	ft_strdel(&res[0]);
	ft_strdel(&res[1]);
	free(res);
	res = NULL;
}

void	float_padding(t_flags *flag, char **res)
{
	char	*round;

	if (!(round = ft_round(res[1], flag->dot - 1)))
		return ;
	print_nb_padding(flag, round);
	ft_strdel(&round);
}

void	float_no_padding(t_flags *flag, char **res, int len_dec)
{
	char	*round;

	if (flag->dot > len_dec)
		flag->zero = flag->dot - len_dec;
	if (!(round = ft_round(res[1], flag->dot - 1)))
		return ;
	ft_putnstr(round, flag->dot);
	ft_strdel(&round);
	print_nchar(flag->zero, '0');
}

void	print_whole(t_flags *flag, char **res, int len_whole)
{
	int		width_whole;
	int		zero_whole;

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
	print_nb(flag, res[0]);
}

void	print_float(t_flags *flag, char **res)
{
	int		len_dec;
	int		len_whole;

	len_dec = ft_strlen(res[1]);
	len_whole = ft_strlen(res[0]);
	if (flag->space && flag->plus != '-')
		flag->space++;
	if (flag->dot < 0)
		flag->dot = 6;
	print_whole(flag, res, len_whole);
	flag->zero = 0;
	if (flag->dot != 0 || flag->sharp)
		ft_putchar('.');
	if (flag->minus == 1)
		float_padding(flag, res);
	else
		float_no_padding(flag, res, len_dec);
	free_res(res);
	flag->len += len_whole + flag->dot + flag->space;
	flag->len += (flag->plus == '-' ? 1 : 0) + (flag->dot > 0 ? 1 : 0);
}
