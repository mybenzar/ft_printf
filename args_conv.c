/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:25:41 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/15 09:37:26 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	conv_signed(t_flags *flags, va_list va)
{
	if (flags->modif == h)
		return ((short int)va_arg(va, int));
	if (flags->modif == hh)
		return ((char)va_arg(va, int));
	if (flags->modif == l)
		return (va_arg(va, long int));
	if (flags->modif == ll)
		return (va_arg(va, long long int));
	else
		return (va_arg(va, int));
}

void		pr_uint(t_flags *flags, va_list va)
{
	flags->plus = 0;
	if (flags->modif == h)
		int_converter(flags, va_arg(va, unsigned int));
	else if (flags->modif == hh)
		int_converter(flags, (unsigned char)va_arg(va, unsigned int));
	else if (flags->modif == l)
		int_converter(flags, va_arg(va, unsigned long int));
	else if (flags->modif == ll)
		int_converter(flags, va_arg(va, unsigned long long int));
	else
		int_converter(flags, va_arg(va, unsigned int));
}

void		other_conv(t_flags *flags, va_list va)
{
	if (flags->id_conv == 'p')
	{
		flags->sharp = 1;
		int_converter(flags, (uintmax_t)va_arg(va, void *));
	}
	if (flags->id_conv == 's')
		str_converter(flags, va_arg(va, char *));
	if ((flags->id_conv == 'c' && flags->modif == n))
		char_converter(flags, (unsigned char)va_arg(va, int));
	if (flags->id_conv == 'n')
	{
		flags->dot = -1;
		flags->plus = (flags->plus == '+' ? 0 : flags->plus);
		if (index_is_special(flags->spec) >= 0)
			char_converter(flags, flags->spec[index_is_special(flags->spec)]);
	}
	if (flags->id_conv == 'f')
	{
		if (flags->modif == L)
			lfloat_converter(flags, va_arg(va, long double));
		else
			float_converter(flags, va_arg(va, double));
	}
}

void		print_param(t_flags *flags, va_list va)
{
	intmax_t	nb_sign;

	if (flags->id_conv == 'd')
	{
		nb_sign = conv_signed(flags, va);
		if (nb_sign < 0)
		{
			nb_sign = -nb_sign;
			handle_neg(flags);
		}
		int_converter(flags, nb_sign);
	}
	else if (ft_strchr("ouxX", flags->id_conv) != NULL)
		pr_uint(flags, va);
	else
		other_conv(flags, va);
}
