/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldftoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:25:43 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/13 14:49:04 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_nb(char *nb_str, unsigned char *tmp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
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
}

char		*ft_ldftoa(long double x)
{
	unsigned char		*tmp;
	char				*nb_str;

	if (!(nb_str = (char *)malloc(sizeof(char) * 81)))
		return (NULL);
	tmp = (unsigned char *)(&x);
	fill_nb(nb_str, tmp);
	ft_strrev(nb_str);
	return (nb_str);
}
