/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:54:51 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/08 13:59:03 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_modif(t_flags *flags)
{
	char *tmp;

	if (ft_strlen(flags->spec) < 2)
		return ;
	if (!(tmp = ft_strdup(flags->spec + (ft_strlen(flags->spec) - 2))))
	{
		flags->modif = n;
		return ;
	}
	if (ft_strncmp(flags->spec, "hh", 2) == 0)
		flags->modif = hh;
	else if (ft_strncmp(flags->spec, "ll", 2) == 0)
		flags->modif = ll;
	else if (tmp[0] == 'l' )
		flags->modif = l;
	else if (tmp[0] == 'L')
		flags->modif = L;
	else if (tmp[0] == 'h')
		flags->modif = h;
	else
		flags->modif = n;
	free(tmp);
}

int		get_size(char *spec, int *i)
{
	int size;
	int k;

	k = 0;
	size = 0;
	while (ft_isdigit(spec[k]) && spec[k])
	{
		size = (size * 10) + (spec[k] - 48);
		*i += 1;
		k++;
	}
	return (size);
}

void	get_size_width(t_flags *flags, int *i)
{
	if (ft_isdigit(flags->spec[*i]) && flags->spec[*i] != '0'
		&& flags->width == 0)
		flags->width = get_size((flags->spec) + *i, i);
	if (flags->spec[*i] == '.')
	{
		*i += 1;
		flags->dot = get_size(flags->spec + *i, i);
	}
}

void	get_opt(t_flags *flags, int *i)
{
	get_size_width(flags, i);
	if (ft_strchr( "0#-+ ", flags->spec[*i]) != NULL)
	{
		if (flags->spec[*i] == '0')
			flags->zero = 1;
		if (flags->spec[*i] == '#')
			flags->sharp = 1;
		if (flags->spec[*i] == '-')
			flags->minus = 1;
		if (flags->spec[*i] == '+')
			flags->plus = '+';
		if (flags->spec[*i] == ' ' && flags->plus != '+' && (flags->width
			|| flags->id_conv == 'd' || flags->id_conv == 'i'))
			flags->space = 1;
	}
	if (flags->minus == 1 && flags->space == 1)
		flags->minus = 'i';
	if (flags->minus == 1 && flags->zero)
		flags->zero = 0;
}

void	get_flags(t_flags *flags)
{
	int i;

	i = 0;
	flags->dot = -1;
	while (flags->spec[i])
	{
		get_opt(flags, &i);
		if (flags->spec[i] != '.')
			i += 1;
	}
	get_modif(flags);
	parsing_flags(flags);
}

int		get_flag_no_id(char *format, int *i, t_flags *flags)
{
	int k;

	k = *i;
	flags->id_conv = 'n';
	if (format[index_is_special(format + k)])
		*i = k + index_is_special(format + k);
	if (!(flags->spec = ft_strdup(format + k)))
		return (0);
	return (1);
}

int		get_flag_conv(char *format, int *i, t_flags *flags)
{
	int start;
	int k;

	k = *i;
	start = k;
	if (format[k] && no_id_conv(format + k))
		return (get_flag_no_id(format, i, flags));
	while (format[k] && format[k] != '%' && !is_alt_special(format[k])
		&& (ft_strchr(VALID, format[k]) != NULL)) 
	{
		if (is_fconv(format[k]))
		{
			flags->id_conv = format[k];
			*i = k;
			if (!(flags->spec = ft_strsub(format, start, k - start + 1)))
				return (0);
			return (1);
		}
		k += 1;
	}
	return (0);
}
