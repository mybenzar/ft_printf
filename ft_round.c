/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:02:25 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/14 12:26:35 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_prec(char *ret, char *str, int size)
{
	int j;
	int i;

	i = 0;
	j = ft_strlen(str);
	while (i <= size && i < j)
	{
		ret[i] = str[i];
		i += 1;
	}
	ret[i] = '\0';
}

static int	only_nine(char *ret)
{
	int i;

	i = 0;
	while (ret[i] != '\0')
	{
		if (ret[i] != '9')
			return (0);
		i++;
	}
	return (1);
}

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

static void	do_rounding(char *ret, int i, char **res)
{
	char	*tmp;
	char	*five;

	if (!(five = ft_strdup("5")))
		return ;
	if (ret[i - 1] == '0')
	{
		ret[i - 1] = '\0';
		if (!(tmp = ft_strdup(res[1])))
			return ;
		ft_strdel(&res[1]);
		if (!(res[1] = ft_strdup(tmp)))
			return ; 
	}
	else if (ret[i - 1] >= '5')
	{
		if ((only_nine(ret) && i - 1 < (int)ft_strlen(ret)) || i == 1)
		{
			round_whole(res);
			return ;
		}
		if (!(tmp = ft_strdup(ret)))
			return ;
		ft_strdel(&ret);
		if (!(ret = vlq_sum(tmp, five)))
			return ;
		ret[i - 1] = '\0';
		ft_strdel(&res[1]);
		if (!(res[1] = ft_strdup(ret)))
			return ; 
		ft_strdel(&tmp);
	}
	ft_strdel(&five);
}

void		ft_round(char **res, t_flags *flag)
{
	char	*ret;
	int 	prec;

	prec = flag->dot - 1; 
	if (!ft_strcmp(res[1], "0"))
		return ;
	//	return ("0");
	if (!(ret = ft_strnew(prec + 2)))
		return ;
	fill_prec(ret, res[1], prec + 1);
	do_rounding(ret, prec + 2, res);
}
