/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lfloat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 11:29:43 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/03 12:13:06 by mybenzar         ###   ########.fr       */
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
	unsigned char		tmp;
	char				*nb_str;

	i = 0;
	if (!(nb_str = (char *)malloc(sizeof(char) * 81)))
		return (NULL);
	tmp = *(unsigned long *)(&x);
	while (i <= 79)
	{
		if (tmp & 1)
			nb_str[i] = '1';
		else
			nb_str[i] = '0';
		tmp >>= 1;
		i++;
	}
	nb_str[i] = '\0';
	ft_strrev(nb_str);
//	if (DEBUG)
		ft_printf("at the end of dftoa, nb_str = %s & len = %d\n", nb_str, (int)ft_strlen(nb_str));
	return (nb_str);
}

int	get_exp_l(char *exp_str)
{
	int nb;
	int i;
	int j;

	j = 10;
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
	//(sign = 0) ? (nb -= 1023) : (nb += 1023);
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
	if (!(right = ft_strnew(64 + exp)))
		return ;
	left[0] = '0';
	while (i < exp - 1)
		right[i++] = '0';
	right[i++] = '1';
	while (i < 64 + exp)
	{
		if (mantissa[j] == '0' || mantissa[j] == '1')
			right[i++] = mantissa[j++]; 
	}
	right[i] = '\0';
	//res[0] = ft_bintowhole(left);
	res[0] = ft_strdup("0");
	res[1] = ft_bintodec(right);
}

void	res_big_exp_l(char *mantissa, int exp, char **res)
{
	char	*left;
	int		i;

	i = 0;
	if (!(left = ft_strnew(exp + 1)))
		return ;
	left[0] = '1';
	if (!(ft_strncat(left, mantissa, exp)))
		return ;
	while (left[i] == '0' || left[i] == '1')
		i++;
	printf("i = %d\n", i);
	while (i < exp + 1)
		left[i++] = '0';
	res[0] = ft_bintowhole(left);
	res[1] = ft_strdup("0");
}

void	res_pos_exp_l(char *mantissa, int exp, char **res)
{
	char	*left;
	char	*right;

	if (exp > 64)
		res_big_exp(mantissa, exp, res);
	if (!(left = ft_strnew(exp + 1)))
		return ;
	if (!(right = ft_strnew(64 - exp)))
		return ;
	left[0] = '1';
	if (!(ft_strncat(left, mantissa, exp)))
		return ;
	mantissa += exp;
	if (!(ft_strcpy(right, mantissa)))
		return ;
	res[0] = ft_bintowhole(left);
	res[1] = ft_bintodec(right);
}

void	get_res_l(char *mantissa, int exp, char **res)
{
	res[2] = 0;
	if (exp < 0)
		res_neg_exp_l(mantissa, exp, res);
	else
		res_pos_exp_l(mantissa, exp, res);
}
