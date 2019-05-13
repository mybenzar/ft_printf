/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintowhole.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:14:11 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/13 14:50:27 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	---> bintowhole converts the exponent binary string into a decimal string
**	by multiplying corresponding powers of two by '1' bits
*/

char	*ft_bintowhole(char *vlq)
{
	int		i;
	char	*ret;
	char	*tmp;
	char	*pow;

	i = 0;
	if (!(ret = ft_strnew(ft_strlen(vlq) + 1)))
		return (NULL);
	ft_strrev(vlq);
	while (vlq[i] != 0)
	{
		if (vlq[i] == '1')
		{
			if (!(pow = ft_strdup(vlq_binpow(i)))
				|| !(tmp = ft_strdup(ret)))
				return (NULL);
			ft_strdel(&ret);
			if (!(ret = vlq_sum(tmp, pow)))
				return (NULL);
			ft_strdel(&pow);
			ft_strdel(&tmp);
		}
		i++;
	}
	return (ret);
}
