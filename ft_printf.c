/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:49:31 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/29 12:09:23 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	char *str_format;
	va_list	va;
	int 	i;
	int 	len;
	t_flags *flags;

	i = 0;
	len = 0;
	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (-1);
	va_start(va, format);
	if (!(str_format = ft_strdup((char *)format)))
		return (0);
	if (DEBUG)
	{
		printf("\n\n_____________________________________________________________________________\n\n");
		printf("str_format = %s\n", str_format);
	}
	while (str_format[i] != '\0')
	{
		ft_bzero(flags, sizeof(t_flags));
		if (str_format[i] && str_format[i] != '%')
		{
			ft_putchar(str_format[i]);
			len += 1;
		}	
		if (str_format[i] == '%' && str_format[i + 1] != '%' && str_format[i + 1])
		{
			i++;
			if (str_format[i] && (get_flag_conv(str_format, &i, flags)))
			{
				get_flags(flags);
				if (DEBUG)
				{
					printf("\n\nFLAGS\n");
					printf_flags(flags);
					printf("\n\n");
				}
				print_param(flags, va);
			}
			len = len + flags->len;
			free(flags->spec);
		}
		if (str_format[i] == '%' && str_format[i + 1] == '%')
		{
			i += 2;
			ft_putchar('%');
			len++;
		}
		else
			i++;

	}
	va_end(va);
	free_flags(flags);
	free(str_format);
	str_format = NULL;
	if (DEBUG)
	{
		printf("final len = %d\n", len);
		printf("\n\n_____________________________________________________________________________\n\n");
	}
	return (len);
}
