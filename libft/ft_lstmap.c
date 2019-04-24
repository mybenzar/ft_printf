/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 12:34:40 by malavent          #+#    #+#             */
/*   Updated: 2018/11/26 11:36:22 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;
	t_list *temp1;

	new = NULL;
	while (lst)
	{
		temp1 = f(lst);
		if (new == NULL)
		{
			new = temp1;
			tmp = new;
			new->next = NULL;
		}
		else
		{
			new->next = temp1;
			new = new->next;
		}
		lst = lst->next;
	}
	return (tmp);
}
