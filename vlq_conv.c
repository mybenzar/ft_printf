/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlq_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:50:11 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/12 13:50:27 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	vlq_tmp_conv(t_calc *info, char *s1, char *s2)
{
	int i;

	i = 0;
	while (i <= info->len1)
		s1[i++] -= 48;
	i = 0;
	while (i <= info->len2)
		s2[i++] -= 48;
}

void	vlq_tmp_conv_rev(char *s, int size)
{
	int i;

	i = 0;
	while (i < size)
		s[i++] += 48;
}

void	vlq_tmp_conv_rev2(t_calc *info, char *s1, char *s2)
{
	int i;

	i = 0;
	while (i < info->len1_static)
		s1[i++] += 48;
	i = 0;
	while (i < info->len2_static)
		s2[i++] += 48;
}
