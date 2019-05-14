/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frexpl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 12:45:07 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/14 15:23:16 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	check_nan_inf_l(char *mantissa, char *exp_str)
{
	if (!ft_strcmp("111111111111111", exp_str) && ft_strchr(mantissa, '1'))
		return (1);
	if (!ft_strcmp("111111111111111", exp_str) && !ft_strchr(mantissa, '1'))
		return (-1);
	return (0);
}

static char	**lhandle_ni(char **res, char *nb_str, char *mantissa, char *exp)
{
	if (check_nan_inf_l(mantissa, exp) == 1)
	{
		if (!(res[0] = ft_strdup("nan")))
			return (NULL);
		res[1] = NULL;
		ft_strdel(&nb_str);
		ft_strdel(&mantissa);
		return (res);
	}
	if (check_nan_inf_l(mantissa, exp) == -1)
	{
		if (!(res[0] = ft_strdup("inf")))
			return (NULL);
		res[1] = NULL;
		ft_strdel(&nb_str);
		ft_strdel(&mantissa);
		return (res);
	}
	return (NULL);
}

char		**ft_frexpl(long double x)
{
	char	*nb_str;
	char	*mantissa;
	char	exp_str[16];
	char	**res;
	int		i;

	i = 0;
	exp_str[15] = '\0';
	if (!(res = (char **)malloc(sizeof(char *) * 3))
		|| !(nb_str = ft_ldftoa(x))
		|| !(res[2] = ft_strnew(1))
		|| !(ft_strncpy(exp_str, nb_str + 1, 15))
		|| !(mantissa = ft_strdup(nb_str + 16)))
		return (NULL);
	if (check_nan_inf_l(mantissa, exp_str) != 0)
		return (lhandle_ni(res, nb_str, mantissa, exp_str));
	get_res_l(mantissa, get_exp_l(exp_str), res);
	if (!ft_strchr(nb_str + 1, '1') && nb_str[0] == '1')
		ft_strcpy(res[2], "-\0");
	ft_strdel(&nb_str);
	ft_strdel(&mantissa);
	return (res);
}
