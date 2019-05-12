/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldftoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:25:43 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/12 13:25:45 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ldftoa(long double x)
{
	int					i;
	int					j;
	unsigned char		*tmp;
	char				*nb_str;
	int					k;

	i = 0;
	j = 0;
	k = 0;
	if (!(nb_str = (char *)malloc(sizeof(char) * 81)))
		return (NULL);
	tmp = (unsigned char *)(&x);
	while (i < 10)
	{
		j = 0;
		while (j < 8)
		{
			if (tmp[i] & 1)
				nb_str[k] = '1';
			else
				nb_str[k] = '0';
			tmp[i] >>= 1;
			k++;
			j++;
		}
		i++;
	}
	nb_str[k] = '\0';
	ft_strrev(nb_str);
	return (nb_str);
}
