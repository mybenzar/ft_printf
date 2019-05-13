/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:02:25 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/13 15:39:33 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_prec(char *ret, char *str, int size, int *i)
{
	*i += 1;
	while (*i <= size)
	{
		ret[*i] = str[*i];
		*i += 1;
	}
	ret[*i] = '\0';
}

static char	*do_rounding(char *ret, int *i)
{
	char	*tmp;
	char	*five;

	if (!(five = ft_strdup("5")))
		return (NULL);
	if (ret[*i - 1] == '0')
	{
		ret[*i - 1] = '\0';
		ft_strdel(&five);
		return (ret);
	}
	if (ret[*i - 1] >= '5')
	{
		if (!(tmp = ft_strdup(ret)))
			return (NULL);
		ft_strdel(&ret);
		if (!(ret = vlq_sum(tmp, five)))
			return (NULL);
		ret[*i - 1] = '\0';
		ft_strdel(&tmp);
	}
	ft_strdel(&five);
	return (ret);
}

char		*ft_round(char *str, int prec)
{
	char	*ret;
	int		i;

	i = -1;
	if (!ft_strcmp(str, "0"))
		return ("0");
	if (!(ret = (char *)malloc(sizeof(char) * prec + 3)))
		return (NULL);
	fill_prec(ret, str, prec + 1, &i);
	return (do_rounding(ret, &i));
}
