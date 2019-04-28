/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:25:41 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/28 11:54:58 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	conv_signed(t_flags *flags, va_list va)
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

void	pr_uint(t_flags *flags, va_list va)
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


static void	other_conv(t_flags *flags, va_list va)
{
	if (flags->id_conv == 'p')
	{
		/*if (flags->modif == h)
			print_memory(flags, va_arg(va, short int *));
		if (flags->modif == l)
			print_memory(flags, va_arg(va, long int *));
		else*/
		flags->sharp = 1;
		int_converter(flags, (uintmax_t)va_arg(va, void *));
	}
	if (flags->id_conv == 's')
	{
		/*if (flags->modif == l)
			wstr_converter(flags, va_arg(va, wchar_t *));*/
		str_converter(flags, va_arg(va, char *));
	}
	if ((flags->id_conv == 'c' && flags->modif == n))
	{
		/*if (flags->modif == l)
			wint_converter(flags, va_arg(va, wint_t));
		if (flags->modif == hh)
			str_converter(flags, va_arg(va, char *));*/
		char_converter(flags, (unsigned char)va_arg(va, int));
	}
	if (flags->id_conv == 'n')
		char_converter(flags, flags->spec[index_is_special(flags->spec)]);
	if (flags->id_conv == 'f')
	{
		/*if (flags->modif == 'l' || flags->modif == 'L')
			float_converter(flags, va_arg(va, long double));
		else*/
			float_converter(flags, va_arg(va, double));
	}
}

void	print_param(t_flags *flags, va_list va)
{
	intmax_t	nb_sign;
	
	if (flags->id_conv == 'd')
	{
		nb_sign = conv_signed(flags, va);
		// je ne comprenais plus pourquoi on avait mis ca, en fait dans tous les cas on veut remettre nb en positif, non?
		// car int_conv prend des unsigned en entree
		if (nb_sign < 0 /*&& flags->space == 1*/)
		{
			nb_sign = -nb_sign;
			flags->plus = '-';
			if (!flags->width && flags->space)
				flags->space = 0;
		}
		int_converter(flags, nb_sign);
	}
	else if (ft_strchr("ouxX", flags->id_conv) != NULL)
		pr_uint(flags, va);
	else
		other_conv(flags, va);
}

