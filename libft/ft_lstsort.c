/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 08:56:29 by malavent          #+#    #+#             */
/*   Updated: 2018/11/26 11:36:22 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsort(t_list *lst, int (*cmp)(int, int))
{
	t_list	*tmp;
	t_list	*tmp2;
	int		sort_kind;

	sort_kind = 0;
	if (!lst)
		return (NULL);
	tmp = lst;
	if ((sort_kind = (*cmp)((int)tmp->content, (int)(tmp->next)->content) == 0))
		sort_kind = 1;
	else
		sort_kind = (*cmp)((int)tmp->content, (int)(tmp->next)->content);
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((*cmp)((int)tmp->content, (int)tmp2->content) != sort_kind)
				ft_lstswap_content(tmp, tmp2);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (lst);
}
