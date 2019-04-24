/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:28:38 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/19 10:18:29 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	i = ft_strlen((const char*)str) - 1;
	j = 0;
	while (i >= j)
	{
		ft_swap(&str[i], &str[j]);
		i--;
		j++;
	}
	return (str);
}
