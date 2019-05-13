/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:11:58 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/13 13:49:45 by mybenzar         ###   ########.fr       */
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

void	free_res(char **res)
{
	ft_strdel(&res[0]);
	ft_strdel(&res[1]);
	ft_strdel(&res[2]);
	free(res);
	res = NULL;
}

void	free_calc(t_calc *info)
{
	ft_bzero(info, sizeof(t_calc));
	free(info);
	info = NULL;
}
