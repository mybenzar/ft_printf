/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:08:16 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/08 14:32:08 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_integer(char id_conv)
{
	if (ft_strchr("diouxXp", id_conv) != NULL)
		return (1);
	return (0);
}

int		is_fconv(char c)
{
	if (ft_strchr(F_TYPE, c) != NULL)
		return (1);
	return (0);
}

int		is_special(char c)
{
	if (c == '"' || c == '\'' || c == '%')
		return (1);
	return (0);
}

void	parsing_flags(t_flags *flags)
{
	if (flags->id_conv == 'i')
		flags->id_conv = 'd';
	if (flags->zero != 0 && flags->minus != 0)
		flags->zero = 0;
	if (flags->space == 1 && flags->plus == '+')
		flags->space = 0;
}

int		is_alt_special(char c)
{
	if (c == '\n' || c == '\a' || c == '\f' || c == '\b'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}
