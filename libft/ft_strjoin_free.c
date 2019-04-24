/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgheraie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:12:28 by mgheraie          #+#    #+#             */
/*   Updated: 2018/12/14 16:25:53 by mgheraie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char **s1, char **s2)
{
	char	*str;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(*s1) + ft_strlen(*s2);
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_strcpy(str, *s1);
	ft_strcat(str, *s2);
	ft_strdel(s1);
	ft_strdel(s2);
	return (str);
}
