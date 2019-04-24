/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:27:30 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/02 16:05:12 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*dec_to_rounded_a(float x, int prec)
{
	int		dec;
	char	*dec_str;
	int		len;

	dec = (int)((x - (long)x) * ft_power(10, prec + 1));
	if (!(dec_str = ft_itoa(dec)))
		return (NULL);
	len = ft_strlen(dec_str);
	if (str[len] >= '5')
		str[len - 1] += 1;
	return (dec_str);
}

void	float_converter(float x)
{
	int		i_part;
	char	*i_str;
	char	*d_str;
	
	i_part = (long)x;
	if (flag->dot == 0)
	{
		if (x - i_part >= 5)
			x += 1;
		x = i_part;
			
	}
	if (x - i_part == 0)
	{
		int_converter(i_part);
		return ;
	}
	if (!(i_str = ft_itoa((long)x)))
		return (NULL);
	(x < 0) ? ft_putchar('-') : ft_putchar('+');
	len = (int)ft_strlen(nb_str) + flag->dot;
	fill_zero_space(flag, len);
	if (flag->dot < len)
		flag->zero = 0;
	if (flag->minus == 1)
		print_nb_padding(flag, nb_str);
	else
		print_nb(flag, nb_str);
	flag->len += len + flag->zero + flag->plus + flag->space;

}

static long long	round(long long dec, char sign)
{
	if (sign == '-') 
		dec = dec - 5;
	else
		dec = dec + 5;
	return (dec / 10);
}

static double	round_to(long long x, int dec_nb)
{
	int 	i;
	long 	dec;
	
	i = 0;
	dec = (long)((x -(long)x) * ft_power(10, dec_nb));
	return (x + dec);
}

static float ft_fmod(long double x, long double y)
{
	printf("round_to = %f\n", round_to((x / y), 2));
	return (x - y * round_to((x / y), 2));
}


static long	dec_to_long(long double x)
{
	long		nbr_final;
	long long	digits;
	long double		nbr;

	digits = 1;
	nbr = x - (long)x;
	printf("ft_mod returns = %f\n", ft_fmod(nbr, 10));
		nbr = nbr * 10;
	printf("ft_mod returns = %f\n", ft_fmod(nbr, 10));
		nbr = nbr * 10;
	printf("ft_mod returns = %f\n", ft_fmod(nbr, 10));
		nbr = nbr * 10;
	printf("ft_mod returns = %f\n", ft_fmod(nbr, 10));
		nbr = nbr * 10;
		printf("nbr=%Lf\n", nbr);
	printf("ft_mod returns = %f\n", ft_fmod(nbr, 10));
		nbr = nbr * 10;
		printf("nbr=%Lf\n", nbr);
	printf("ft_mod returns = %f\n", ft_fmod(nbr, 10));
		nbr = nbr * 10;
		printf("nbr=%Lf\n", nbr);
	printf("ft_mod returns = %f\n", ft_fmod(nbr, 10));
		nbr = nbr * 10;
		printf("nbr=%Lf\n", nbr);
	printf("ft_mod returns = %f\n", ft_fmod(nbr, 10));

		nbr = nbr * 10;
		printf("nbr=%Lf\n", nbr);
	printf("ft_mod returns = %f\n", ft_fmod(nbr, 10));
	/*while (ft_fmod(nbr, 10) != 0)
	{

		nbr = nbr * 10;
		printf("nbr = %Lf\n", nbr);
		digits = digits * 10;
	}
	nbr /= 10;
	digits /= 10;*/
	nbr_final = ft_fmod(nbr, digits);
	return (nbr_final);
}

static char	*dec_to_rounded_a(long double x, int prec, int sign)
{
	long		dec;
	char		*dec_str;

	printf("\nx=%Lf\n", x - (long)x);
	printf("\ndec=%ld\n", (long)((x -(long)x) * ft_power(10, prec + 1)));
	printf("\ndec_to_long = %ld\n", dec_to_long(x));
	dec = round(((long long)((x - (long)x) * ft_power(10, prec + 1))), sign);
	printf("\nrounded_dec = %ld\n", dec);
	if (!(dec_str = ft_itoa(dec)))
		return (NULL);
	return (dec_str);
}
