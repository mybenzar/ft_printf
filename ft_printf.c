/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:49:31 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/08 12:13:32 by mybenzar         ###   ########.fr       */
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
		//		printf("\n________________________\n");
		//		printf("\nflags->spec = %s\n", flags->spec);
				get_flags(flags, va);
			//	printf_flags(flags);
				print_param(flags, va);


			}
		//	printf("before, len = %d\n", len);
			len = len + flags->len;
		//	printf("\nlen = %d\n\n\n", len);
		//	printf("\n__________________________\n");
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
