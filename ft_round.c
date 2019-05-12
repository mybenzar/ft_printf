/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:02:25 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/12 13:02:56 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_round(char *str, int prec)
{
	char	*tmp;
	char	*five;
	char	*ret;
	int		i;

	i = -1;
	if (!ft_strcmp(str, "0"))
		return ("0");
	if (!(ret = (char *)malloc(sizeof(char) * prec + 3)))
		return (NULL);
	while (++i <= prec + 1)
		ret[i] = str[i];
	ret[i] = '\0';
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

