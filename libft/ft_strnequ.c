/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:38:28 by malavent          #+#    #+#             */
/*   Updated: 2018/11/17 15:12:53 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!n)
		return (1);
	while (n-- > 1 && *s1 == *s2 && *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (0);
	return (1);
}
