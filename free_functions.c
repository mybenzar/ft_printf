/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:11:58 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/08 14:12:18 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_flags(t_flags *flags)
{
	ft_bzero(flags, sizeof(t_flags));
	free(flags->spec);
	flags->spec = NULL;
	free(flags);
	flags = NULL;
}

