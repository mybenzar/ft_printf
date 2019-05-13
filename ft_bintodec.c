/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:15:46 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/13 15:14:33 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	---> bintodec computes the following sum : (sum 5^(frac_digits - i)
**	which is equal to the decimal part (in base 10)
*/

static char	*compute_sum(char *vlq, char *ret, int i, int j)
{
	char	*tmp;
	char	*pow;
	char	*tmp_pow;

	while (vlq[++i] != '\0')
	{
		if (vlq[i] == '1')
		{
			if (!(pow = ft_strdup(vlq_fivepow(i)))
				|| !(tmp_pow = ft_strdup(pow)))
				return (NULL);
			ft_strdel(&pow);
			if (!(pow = get_pow_ten(tmp_pow, j))
				|| !(tmp = ft_strdup(ret)))
				return (NULL);
			ft_strdel(&tmp_pow);
			ft_strdel(&ret);
			if (!(ret = vlq_sum(tmp, pow)))
				return (NULL);
			ft_strdel(&pow);
			ft_strdel(&tmp);
		}
		j--;
	}
	return (ret);
}

char		*ft_bintodec(char *vlq)
{
	int		i;
	int		j;
	char	*ret;

	i = -1;
	j = ft_strlen(vlq) - 1;
	if (!(ret = ft_strnew(ft_strlen(vlq) + 1)))
		return (NULL);
	vlq_initialize(ret, '0', ft_strlen(vlq));
	return (compute_sum(vlq, ret, i, j));
}
