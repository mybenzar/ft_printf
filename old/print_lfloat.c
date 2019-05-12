/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lfloat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 11:29:43 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/12 13:28:05 by mybenzar         ###   ########.fr       */
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


int		check_nan_inf_l(char *mantissa, char *exp_str/*, int sign*/)
{
	if (!ft_strcmp("111111111111111", exp_str) && ft_strchr(mantissa, '1'))
		return (1);
	if (!ft_strcmp("111111111111111", exp_str) && !ft_strchr(mantissa, '1'))
		return (-1);
	return (0);
}

char	**ft_frexpl(long double x)
{
	char *nb_str;
	char *mantissa;
	char exp_str[16];
	char **res;
	int i;

	i = 0;
	exp_str[15] = '\0';
	if (!(res = (char **)malloc(sizeof(char *) * 2)) || !(nb_str = ft_ldftoa(x))
		|| !(ft_strncpy(exp_str, nb_str + 1, 15))
		|| !(mantissa = ft_strdup(nb_str + 16)))
		return (NULL);
	if (check_nan_inf_l(mantissa, exp_str) == 1)
	{
		res[0] = ft_strdup("nan");
		res[1] = NULL;
		ft_strdel(&nb_str);
		return (res);
	}
	if (check_nan_inf_l(mantissa, exp_str) == -1)
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
	ft_strdel(&mantissa);
	return (res);
}
