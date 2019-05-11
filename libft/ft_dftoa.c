/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dftoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 12:20:06 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/11 12:21:35 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	---> ft_dftoa extracts the binary value of the float into a string
*/

char	*ft_dftoa(double x)
{
	int					i;
	unsigned long		tmp;
	char				*nb_str;

	i = 0;
	if (!(nb_str = (char *)malloc(sizeof(char) * 65)))
		return (NULL);
	tmp = *(unsigned long *)(&x);
	while (i <= 63)
	{
		if (tmp & 1)
			nb_str[i] = '1';
		else
			nb_str[i] = '0';
		tmp >>= 1;
		i++;
	}
	nb_str[i] = '\0';
	ft_strrev(nb_str);
	return (nb_str);
}
