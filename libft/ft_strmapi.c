/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:38:22 by malavent          #+#    #+#             */
/*   Updated: 2018/12/11 18:09:31 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	if (s == NULL || !f)
		return (0);
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (0);
	i = 0;
	while (*s != '\0')
	{
		new[i] = (*f)(i, *s);
		s++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
