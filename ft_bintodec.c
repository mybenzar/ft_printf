/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:15:46 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/12 13:23:44 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 **	---> bintodec computes the following sum : (sum 5^(frac_digits - i) 
 **	which is equal to the decimal part (in base 10)
 */

char	*ft_bintodec(char *vlq)
{
	int i;
	int j;
	char *ret;
	char *tmp;
	char *pow;
	char *tmp_pow;

	i = 0;
	j = ft_strlen(vlq) - 1;
	if (!(ret = ft_strnew(ft_strlen(vlq) + 1)))
		return (NULL);
	vlq_initialize(ret, '0', ft_strlen(vlq));
	while (vlq[i] != '\0')
	{
		if (vlq[i] == '1')
		{
			if (!(pow = ft_strdup(vlq_fivepow(i))))
				return (NULL);
			tmp_pow = ft_strdup(pow);
			free(pow);
			pow = get_pow_ten(tmp_pow, j);
			free(tmp_pow);
			tmp = ft_strdup(ret);
			free(ret);
			ret = ft_strdup(vlq_sum(tmp, pow));
			free(pow);
			free(tmp);
		}
		i++;
		j--;
	}
	return (ret);
}
