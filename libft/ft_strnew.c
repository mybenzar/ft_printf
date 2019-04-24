/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:33:45 by malavent          #+#    #+#             */
/*   Updated: 2018/12/11 17:22:21 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new;

	if (!(new = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
