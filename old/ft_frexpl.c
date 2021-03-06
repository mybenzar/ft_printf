/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frexpl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 12:45:07 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/11 12:54:06 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_nan_inf_l(char *mantissa, char *exp_str)
{
	if (!ft_strcmp("111111111111111", exp_str) && ft_strchr(mantissa, '1'))
		return (1);
	if (!ft_strcmp("111111111111111", exp_str) && !ft_strchr(mantissa, '1'))
		return (-1);
	return (0);
}

static char	**lhandle_ni(char **res, char *nb_str, char *mantissa, char *exp_str)
{
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
		|| !(ft_strncpy(exp_str, nb_str + 1, 15))
		|| !(mantissa = ft_strdup(nb_str + 16)))
		return (NULL);
	if (check_nan_inf_l(mantissa, exp_str) != 0)
		return (lhandle_ni(res, nb_str, mantissa, exp_str));
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
