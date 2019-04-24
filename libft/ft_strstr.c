/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:21:45 by malavent          #+#    #+#             */
/*   Updated: 2018/11/17 15:38:08 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int find;

	find = 0;
	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && find == 0)
	{
		find = 1;
		while (needle[j] != '\0')
		{
			if (haystack[i + j] != needle[j])
				find = 0;
			j++;
		}
		j = 0;
		i++;
	}
	if (find == 1)
		return ((char *)haystack + i - 1);
	return (NULL);
}
