/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 12:51:21 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/13 11:36:05 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	---> get_res converts the binary char into left & right
**	left[0] = '1': multiply by 2^52 to get MSB
**	left is the part on the left of the floating point
**	right is the part on the right of the floating point
*/

static void	res_neg_exp(char *mantissa, int exp, char **res)
{
	char	*right;
	int		i;
	int		j;

	i = 0;
	exp = -exp;
	if (!(right = ft_strnew(52 + exp)))
		return ;
	while (i < exp - 1)
		right[i++] = '0';
	if (exp == 1023 && !ft_strchr(mantissa, '1'))
		right[i++] = '0';
	else
		right[i++] = '1';
	j = 0;
	while (i < 52 + exp)
	{
		if (mantissa[j] == '0' || mantissa[j] == '1')
			right[i++] = mantissa[j++];
	}
	right[i] = '\0';
	if (!(res[0] = ft_strdup("0"))
		|| !(res[1] = ft_bintodec(right)))
		return ;
	ft_strdel(&right);
}

static void	res_big_exp(char *mantissa, int exp, char **res)
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
	while (i < exp + 1)
		left[i++] = '0';
	if (!(res[0] = ft_bintowhole(left))
		|| (!(res[1] = ft_strdup("0"))))
		return ;
	ft_strdel(&left);
}

static void	res_pos_exp(char *mantissa, int exp, char **res)
{
	char	*left;
	char	*right;

	if (exp > 52)
		res_big_exp(mantissa, exp, res);
	if (!(left = ft_strnew(exp + 1)))
		return ;
	left[0] = '1';
	if (!(ft_strncat(left, mantissa, exp)))
		return ;
	if (!(right = ft_strdup(mantissa + exp)))
		return ;
	if (!(res[0] = ft_bintowhole(left))
		|| (!(res[1] = ft_bintodec(right))))
		return ;
	ft_strdel(&left);
	ft_strdel(&right);
}

void		get_res(char *mantissa, int exp, char **res)
{
	if (exp < 0)
		res_neg_exp(mantissa, exp, res);
	else
		res_pos_exp(mantissa, exp, res);
}
