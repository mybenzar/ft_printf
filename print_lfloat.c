/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lfloat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 11:29:43 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/08 12:25:27 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "ft_printf.h"

/*
**	Sign = 1 bit
**	Exponent = 15 bits
**	Integer Part = 1 bit
**	Mantissa = 63 bits
**	"In contrast to the single and double-precision formats, this format does 
**	not utilize an implicit/hidden bit. 
**	Rather, bit 63 contains the integer part of the significand and bits 62-0 
**	hold the fractional part. Bit 63 will be 1 on all normalized numbers."
*/
char	*ft_ldftoa(long double x)
{
	int					i;
	int					j;
	unsigned char		*tmp;
	char				*nb_str;
	int					k;

	i = 0;
	j = 0;
	k = 0;
	if (!(nb_str = (char *)malloc(sizeof(char) * 81)))
		return (NULL);
	tmp = (unsigned char *)(&x);
	while (i < 10)
	{
		j = 0;
		while (j < 8)
		{
			if (tmp[i] & 1)
				nb_str[k] = '1';
			else
				nb_str[k] = '0';
			tmp[i] >>= 1;
			k++;
			j++;
		}
		i++;
	}
	nb_str[k] = '\0';
	ft_strrev(nb_str);
	return (nb_str);
}

int	get_exp_l(char *exp_str)
{
	int nb;
	int i;
	int j;

	j = 14;
	i = 0;
	nb = 0;
	while (exp_str[i] != '\0')
	{
		if (exp_str[i] == '1')
			nb = nb + pow2(j);
		i++;
		j--;
	}
	nb -= 16383;
	return (nb);
}

void	res_neg_exp_l(char *mantissa, int exp, char **res)
{
	char	*left;
	char	*right;
	int		i;
	int		j;

	i = 0;
	j = 0;
	exp = -exp;
	if (!(left = ft_strnew(exp + 1)))
		return ;
	if (!(right = ft_strnew(63 + exp)))
		return ;
	left[0] = '0';
	while (i < exp - 1)
		right[i++] = '0';
	while (i < 63)
	{
		if (mantissa[j] == '0' || mantissa[j] == '1')
			right[i++] = mantissa[j++]; 
	}
	right[i] = '\0';
	res[0] = ft_strdup("0");
	res[1] = ft_bintodec(right);
	ft_strdel(&right);
	ft_strdel(&left);
}

void	res_big_exp_l(char *mantissa, int exp, char **res)
{
	char	*left;
	int		i;

	i = 0;
	if (!(left = ft_strnew(exp + 1)))
		return ;
	if (!(ft_strncat(left, mantissa, exp + 1)))
		return ;
	while (left[i] == '0' || left[i] == '1')
		i++;
	while (i < exp + 1)
		left[i++] = '0';
	res[0] = ft_bintowhole(left);
	ft_strdel(&left);
	res[1] = ft_strdup("0");
}

void	res_pos_exp_l(char *mantissa, int exp, char **res)
{
	char	*left;
	char	*right;

	if (exp > 64)
		res_big_exp_l(mantissa, exp, res);
	if (!(left = ft_strnew(exp + 1)))
		return ;
	if (!(right = ft_strnew(63 - exp)))
		return ;
	if (!(ft_strncat(left, mantissa, exp + 1)))
		return ;
	mantissa += exp + 1;
	if (!(ft_strcpy(right, mantissa)))
		return ;
	res[0] = ft_bintowhole(left);
	ft_strdel(&left);
	res[1] = ft_bintodec(right);
	ft_strdel(&right);
}

void	get_res_l(char *mantissa, int exp, char **res)
{
	res[2] = 0;
	if (exp < 0)
		res_neg_exp_l(mantissa, exp, res);
	else
		res_pos_exp_l(mantissa, exp, res);
}

int		check_nan_inf_l(char *mantissa, char *exp_str/*, int sign*/)
{
	if (!ft_strcmp("111111111111111", exp_str) && ft_strchr(mantissa, '1'))
	{
	//	ft_putstr("NaN");
		return (1);
	}
	if (!ft_strcmp("111111111111111", exp_str) && !ft_strchr(mantissa, '1'))
	{
/*		if (sign == '1')	
			ft_putchar('-');
		ft_putstr("inf");*/
		return (-1);
	}
	return (0);
}

char	**ft_frexpl(long double x)
{
	char *nb_str;
	char mantissa[65];
	char exp_str[16];
	char **res;
	int i;

	i = 0;
	mantissa[64] = '\0';
	exp_str[15] = '\0';
	if (!(res = (char **)malloc(sizeof(char *) * 3)))
		return (NULL);
	if (!(nb_str = ft_ldftoa(x)))
		return (NULL);
	if (!(ft_strncpy(exp_str, nb_str + 1, 15)))
		return (NULL);
	if (!(ft_strncpy(mantissa, nb_str + 16, 63)))
		return (NULL);
	if (check_nan_inf_l(mantissa, exp_str))
		return (NULL);
	if (check_nan_inf_l(mantissa, exp_str) == 1)
	{
		res[0] = ft_strdup("nan");
		res[1] = NULL;
		ft_strdel(&nb_str);
		return (res);
	}
	if (check_nan_inf_l(mantissa, exp_str/*, nb_str[0]*/) == -1)
	{
		res[0] = ft_strdup("inf");
		res[1] = NULL;
		ft_strdel(&nb_str);
		return (res);
	}
	get_res_l(mantissa, get_exp_l(exp_str), res);
	
	if (ft_strlen(res[0]) != 1 && res[0][0] == '0')
	{
		while (res[0][i] == '0')
			i++;
		res[0] += i;
	}
	ft_strdel(&nb_str);
	return (res);
}
