/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlq_calc_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:07:01 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/12 14:09:30 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	calc_info(t_calc *info, char *s1, char *s2)
{
	int i;

	i = 0;
	info->len1 = ft_strlen(s1);
	info->len2 = ft_strlen(s2);
	info->len1_static = info->len1;
	info->len2_static = info->len2;
	info->max = ft_max(info->len1, info->len2);
	info->min = ft_min(info->len1, info->len2);
	info->sum = info->len1 + info->len2;
	info->ten_dec = 1;
}
