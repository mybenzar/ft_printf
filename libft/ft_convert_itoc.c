/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_itoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:06:50 by malavent          #+#    #+#             */
/*   Updated: 2019/03/30 19:00:18 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_convert_itoc(uintmax_t value)
{
	char	*base_ref;

	base_ref = "0123456789abcdef";
	return (base_ref[value]);
}
