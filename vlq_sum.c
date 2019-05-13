/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlq_sum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:40:56 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/13 15:39:32 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static int		sum_hold(t_calc *info, char c1, char c2, char c3)
{
	if ((info->len1 >= 0 && info->len2 >= 0
		&& ((c1 + c2 + c3 - 48) > 57))
		|| (info->len1 >= 0 && c1 + c3 > 57)
		|| (info->len2 >= 0 && c2 + c3 > 57))
		return (1);
	return (0);
}
*/
static char		*do_sum(t_calc *info, char *s1, char *s2)
{
	int		i;
	int		hold;
	char	*res;

	if (!(res = ft_strnew(info->max + 2)))
		return (NULL);
	i = info->max;
	while (i > 0)
	{
		hold = 0;
		if ((info->len1 >= 0 && info->len2 >= 0
			&& ((s1[info->len1] + s2[info->len2] + res[i] - 48) > 57))
			|| (info->len1 >= 0 && s1[info->len1] + res[i] > 57) 
			|| (info->len2 >= 0 && s2[info->len2] + res[i] > 57))
			//if (sum_hold(info, s1[info->len1], s2[info->len2], res[i]))
		{
			res[i] -= 10;
			hold = 1;
		}
		res[i] += (info->len1 >= 0) ? s1[info->len1] : 0;
		res[i] += (info->len2 >= 0) ? s2[info->len2] : 0;
		res[i] -= (info->len1 >= 0 && info->len2 >= 0) ? 48 : 0;
		res[--i] += hold;
		if (res[0] == 1)
			res[i] += 48;
		info->len1--;
		info->len2--;
	}
	return (res);
}

static char		*trim_zero(char *s)
{
	int		i;
	char	*ret;

	i = 0;
	while (s[i] == 0)
		i++;
	if (!(ret = ft_strdup(s + i)))
		return (NULL);
	return (ret);
}

char			*vlq_sum(char *s1, char *s2)
{
	char	*res;
	char	*ret;
	t_calc	*info;

	if (!ft_str_isdigit(s1) || !ft_str_isdigit(s2))
		return (NULL);
	if (!(info = (t_calc *)malloc(sizeof(t_calc))))
		return (NULL);
	calc_info(info, s1, s2);
	info->len1 -= 1;
	info->len2 -= 1;
	if (!(res = do_sum(info, s1, s2))
			|| !(ret = trim_zero(res)))
		return (NULL);
	ft_strdel(&res);
	free_calc(info);
	return (ret);
}
