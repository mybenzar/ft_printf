/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:02:25 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/14 10:35:49 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_prec(char *ret, char *str, int size, int *i)
{
	int j;

	j = ft_strlen(str);
	while (*i <= size && *i < j)
	{
		ret[*i] = str[*i];
		*i += 1;
	}
		ret[*i] = '\0';
}

static char	*do_rounding(char *ret, int i, char **res)
{
	char	*tmp;
	char	*five;
	char	*one;


	if (!(one = ft_strdup("1")))
		return (NULL);
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
		if (i == 1)
		{
			if (!(tmp = ft_strdup(res[0])))
				return (NULL);
			ft_strdel(&res[0]);
			if (!(res[0] = vlq_sum(tmp, one)))
				return (NULL);
			ft_strdel(&tmp);
		}
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

void		ft_round(char **res, int prec)
{
	char	*ret;
	int		i;

	i = 0;
	if (!ft_strcmp(res[1], "0"))
		return ;
	//	return ("0");
	if (!(ret = ft_strnew(prec + 2)))
		return ;
	fill_prec(ret, res[1], prec + 1, &i);
	ft_strdel(&res[1]);
	res[1] = do_rounding(ret, prec + 2, res);
}
