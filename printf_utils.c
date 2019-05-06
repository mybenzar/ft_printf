/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:05:31 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/06 11:54:57 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	get_size(char *spec, int *i)  //chope la size pour la precision ou la width si 
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
/*	if (k == 0)
		return (-1);*/
	/*	if (spec[k] != '.' && spec[k] != '\0')
		return (0);*/
	return (size);
}

int is_integer(char id_conv)
{
	if (ft_strchr("diouxXp", id_conv) != NULL)
		return (1);
	return (0);
}
/*
int parse_modifiers(t_flags *flags)
{	
	if ((flags->modif == l || flags->modif == h) && !(ft_strchr("diouxXp", flags->id_conv)))
	{
		ft_putstr(ER_MODIF);
		return (-1);
	}
	if (flags->modif == hh && !(flags->id_conv == 'c'))
	{
		ft_putstr(ER_MODIF);
		return (-1);
	}
	if (flags->modif == L && !(flags->id_conv == 'f'))
	{
		ft_putstr(ER_MODIF);
		return (-1);
	}
	return (1);
}
*/
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
//	parse_modifiers(flags);	
}

void get_opt(t_flags *flags, int *i)
{

	if (ft_isdigit(flags->spec[*i]) && flags->spec[*i] != '0' && flags->width == 0)
		flags->width = get_size((flags->spec) + *i, i);
	if (flags->spec[*i] == '.')
	{
		*i += 1;
		flags->dot = get_size(flags->spec + *i, i);// saute le point
	}
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
		if (flags->spec[*i] == ' ' && flags->plus != '+' && (flags->width || flags->id_conv == 'd'
			|| flags->id_conv == 'i'))
			flags->space = 1;
	}
	// invisible minus sign
	if (flags->minus == 1 && flags->space == 1)
		flags->minus = 'i';
	if (flags->minus == 1 && flags->zero)
		flags->zero = 0;
}

void 	parsing_flags(t_flags *flags)
{
	if (flags->id_conv == 'i')
		flags->id_conv = 'd'; // i est deprecie
	if (flags->zero != 0 && flags->minus != 0)
		flags->zero = 0;
	if (flags->space == 1 && flags->plus == '+')
		flags->space = 0; // gerer le cas ou l'arg est signe et neg remmettre a 0
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


int is_fconv(char c)
{
	if (ft_strchr(F_TYPE, c) != NULL)
		return (1);
	return (0);
} 

int is_special(char c)
{
	if (c == '"' || c == '\'' || c == '%')
		return (1);
	return (0);
}

int	index_is_special(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_special(str[i]))
			return (i);
		i++;
	}
	return (-1);
}

int is_alt_special(char c)
{
	if (c == '\n' || c == '\a' || c == '\f' || c == '\b' || c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	no_id_conv(char *format)
{
	int k;

	k = 0;
	while (format[k])
	{
		if (is_fconv(format[k]))
			return (0);
		k++;
	}
	return (1);
}

int	get_flag_conv(char *format, int *i, t_flags *flags)
{
	int start;
	int k;

	k = *i;
	start = k;
	if (format[k] && no_id_conv(format))
	{
		flags->id_conv = 'n';
		if (format[index_is_special(format + k)])
			*i = k + index_is_special(format + k);
		if (!(flags->spec = ft_strdup(format + k)))
			return (0);
		if (DEBUG)
			printf("in get flag conv for id_conv 'n', flags->spec = %s\n", flags->spec);
		return (1);
	}
	while (format[k] && format[k] != '%' && !is_alt_special(format[k])
		&& (ft_strchr(VALID, format[k]) != NULL)) //si il y a un char alt_spe, il met fin a la specification de format
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

void	free_flags(t_flags *flags)
{
	ft_bzero(flags, sizeof(t_flags));
	free(flags->spec);
	flags->spec = NULL;
	free(flags);
	flags = NULL;
}

