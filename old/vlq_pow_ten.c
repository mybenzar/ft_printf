/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlq_pow_ten.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 09:16:07 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/15 09:16:18 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*vlq_pow_ten(int pow)
{
	int		i;
	char	*pow_ten;
	char	*zero;

	i = 0;
	if (!(pow_ten = ft_strdup("1"))
		|| !(zero = ft_strdup("00000000000000000")))
		return (NULL);
	while (i < pow)
	{
		ft_strdel(&pow_ten);
		if (!(pow_ten = ft_strnew(i + 1)))
			return (NULL);
		pow_ten[0] = '1';
		ft_strncat(pow_ten, zero, i);
		i++;
	}
	ft_strdel(&zero);
	return (pow_ten);
}
