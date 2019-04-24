/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:39:27 by malavent          #+#    #+#             */
/*   Updated: 2018/11/26 11:36:22 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char			*str;
	unsigned int	i;

	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		str[i] = *s1++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
