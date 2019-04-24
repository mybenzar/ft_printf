/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:38:17 by malavent          #+#    #+#             */
/*   Updated: 2018/11/23 08:47:12 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pushback(t_list **lst, t_list *back)
{
	t_list *tmp;

	if (!lst || !back)
		return ;
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = back;
	back->next = NULL;
}
