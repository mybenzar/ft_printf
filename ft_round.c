/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:02:25 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/15 09:22:21 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	round_whole(char **res)
{
	char	*tmp;
	char	*one;

	if (!(one = ft_strdup("1"))
		|| !(tmp = ft_strdup(res[0])))
		return ;
	if (!ft_strcmp(res[0], "0"))
	{
		ft_strdel(&res[0]);
		if (!(res[0] = ft_strdup("1")))
			return ;
	}
	ft_strdel(&res[0]);
	if (!(res[0] = vlq_sum(tmp, one)))
		return ;
	ft_strdel(&res[1]);
	if (!(res[1] = ft_strdup("0")))
		return ;
	ft_strdel(&tmp);
	ft_strdel(&one);
}

static void	round_sup(char *ret, int i, char **res)
{
	char	*five;

	if ((only_nine(ret) && i - 1 < (int)ft_strlen(ret)) || i == 1)
	{
		round_whole(res);
		return ;
	}
	if (!(five = ft_strdup("5")))
		return ;
	ft_strdel(&res[1]);
	if (!(res[1] = vlq_sum(ret, five)))
		return ;
	res[1][i - 1] = '\0';
	if (res[1][i - 2] == '1' && i == 2)
		round_whole(res);
	ft_strdel(&five);
}

static void	do_rounding(char *ret, int i, char **res)
{
	char	*tmp;

	if (ret[i - 1] == '0')
	{
		ret[i - 1] = '\0';
		if (!(tmp = ft_strdup(ret)))
			return ;
		ft_strdel(&res[1]);
		if (!(res[1] = ft_strdup(tmp)))
			return ;
		ft_strdel(&tmp);
	}
	else if (ret[i - 1] >= '5')
		round_sup(ret, i, res);
	ft_strdel(&ret);
}

void		ft_round(char **res, t_flags *flag)
{
	char	*ret;
	int		prec;

	prec = flag->dot - 1;
	if (!ft_strcmp(res[1], "0"))
		return ;
	if (!(ret = ft_strnew(prec + 2)))
		return ;
	fill_prec(ret, res[1], prec + 1);
	do_rounding(ret, prec + 2, res);
}
