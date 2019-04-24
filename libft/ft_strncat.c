/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:38:14 by malavent          #+#    #+#             */
/*   Updated: 2019/04/19 10:18:25 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
	
char	*ft_strncat(char *dest, char const *src, size_t n)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
