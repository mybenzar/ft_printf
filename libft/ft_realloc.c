/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 08:02:48 by malavent          #+#    #+#             */
/*   Updated: 2018/11/27 17:10:28 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	old_size;

	new_ptr = NULL;
	old_size = ft_strlen((const char *)ptr);
	if (!size)
		return (NULL);
	if (!ptr)
	{
		if (!(new_ptr = malloc(size)))
			return (NULL);
		return (new_ptr);
	}
	if (size > old_size)
	{
		if (!(new_ptr = malloc(size)))
			return (NULL);
	}
	if (!(new_ptr = ft_memalloc(size)))
		return (NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
