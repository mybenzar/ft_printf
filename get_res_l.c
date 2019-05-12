/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:26:00 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/12 13:29:06 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	res_neg_exp_l(char *mantissa, int exp, char **res)
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

static void	res_big_exp_l(char *mantissa, int exp, char **res)
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

static void	res_pos_exp_l(char *mantissa, int exp, char **res)
{
	char	*left;
	char	*right;

	if (exp > 64)
		res_big_exp_l(mantissa, exp, res);
	if (!(left = ft_strnew(exp + 1)) || !(right = ft_strnew(63 - exp))
		|| !(ft_strncat(left, mantissa, exp + 1))
		|| !(ft_strcpy(right, mantissa + exp + 1)))
		return ;
	res[0] = ft_bintowhole(left);
	ft_strdel(&left);
	res[1] = ft_bintodec(right);
	ft_strdel(&right);
}

void	get_res_l(char *mantissa, int exp, char **res)
{
	if (exp < 0)
		res_neg_exp_l(mantissa, exp, res);
	else
		res_pos_exp_l(mantissa, exp, res);
}
