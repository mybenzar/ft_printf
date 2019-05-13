/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:49:31 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/13 12:10:42 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_flag(char *format, t_flags *flags, va_list va, int *i)
{
	*i += 1;
	if (format[*i] && (get_flag_conv(format, i, flags)))
	{
		get_flags(flags);
		print_param(flags, va);
	}
}

static void	handle_pct(int *i, int *len)
{
	*i += 2;
	ft_putchar('%');
	*len += 1;
}

static void	handle_format(char *format, t_flags *flags, va_list va, int *len)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		ft_bzero(flags, sizeof(t_flags));
		if (format[i] && format[i] != '%')
		{
			ft_putchar(format[i]);
			*len += 1;
		}
		if (format[i] == '%' && format[i + 1] != '%' && format[i + 1])
		{
			handle_flag(format, flags, va, &i);
			*len += flags->len;
			free(flags->spec);
		}
		if (format[i] == '%' && format[i + 1] == '%')
			handle_pct(&i, len);
		else
			i++;
	}
}

int			ft_printf(const char *format, ...)
{
	char	*str_format;
	va_list	va;
	int		len;
	t_flags *flags;

	len = 0;
	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (-1);
	va_start(va, format);
	if (!(str_format = ft_strdup((char *)format)))
		return (0);
	handle_format(str_format, flags, va, &len);
	va_end(va);
	free_flags(flags);
	ft_strdel(&str_format);
	return (len);
}
