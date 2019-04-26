

#include "ft_printf.h"
#include <stdio.h>

void	printf_flags(t_flags *flag)
{
		printf("padding=%d\n", flag->minus);
		printf("space=%d\n", flag->space);
		printf("width=%d\n", flag->width);
		printf("precision=%d\n", flag->dot);
		printf("len=%d\n", flag->len);
		printf("sharp=%d\n", flag->sharp);
		printf("plus=%c\n", flag->plus);
		printf("id_conv=%c\n", flag->id_conv);
		printf("modif=%d\n", flag->modif);
		printf("zero=%d\n", flag->zero);
}

void	put_flags(t_flags *flags)
{
	ft_putchar('\n');
	ft_putchar(flags->id_conv);
	ft_putchar('\n');
	ft_putnbr(flags->zero);
	ft_putchar('\n');
	ft_putnbr(flags->width);
	ft_putchar('\n');
	ft_putnbr(flags->sharp);
	ft_putchar('\n');
	ft_putnbr(flags->minus);
	ft_putchar('\n');
	ft_putnbr(flags->plus);
	ft_putchar('\n');
	ft_putnbr(flags->dot);
	ft_putchar('\n');
	ft_putnbr(flags->modif);	
	ft_putchar('\n');
}
