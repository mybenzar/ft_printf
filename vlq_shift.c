/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlq_shift.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:51:46 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/12 13:52:21 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	vlq_nshift(char *s, int size, int shifts)
{
	int i;

	i = 0;
	if (shifts == 0)
		return ;
	while (++i < shifts)
		vlq_shift_left(s, size);
}

void	vlq_shift_left(char *s, int size)
{
	int		i;
	char	*tmp;

	i = size - 1;
	if (!(tmp = ft_strdup(s)))
		return ;
	s[i--] = '0';
	while (i >= 0)
	{
		s[i] = tmp[i + 1];
		i--;
	}
	ft_strdel(&tmp);
}
