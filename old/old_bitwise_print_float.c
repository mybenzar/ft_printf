/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:44:53 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/04 10:23:24 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

uintmax_t lnbase2(uintmax_t val)
{
	uintmax_t tmp;
	static const uintmax_t logTable[256] = 
	{
		0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
	};

	tmp = val >> 24;
	if (tmp)
		return (24 + logTable[tmp]);
	tmp = val >> 16;
	if (tmp)
		return (16 + logTable[tmp]);
	tmp = val >> 8;
	if (tmp)
		return (8 + logTable[tmp]);
	return (logTable[tmp]);
}

uint32_t binary_digits(int prec)
{
	return (3 + prec / 3);
}

void	dec_to_binary(long double x, char *str)
{
	double	dec;
	int		i;

	i = 1;
	dec = x - (long)x;
	str[0] = '.';
	//printf("initial dec = %f\n", dec);
	while (i <= 32)
	{
		dec *= 2;
		//printf("int_dec=%d\n", (int)dec);
		//printf("dec = %f\n", dec);
		if ((int)dec == 1)
		{
			str[i] = '1';
			dec = dec - 1;
		}
		else
			str[i] = '0';
		i++;
	}
	str[i] = '\0';
}
/*
static char	*float_to_binary(long double x)
{
	char *whole;
	char *str;
	char dec[34];

	if (!(whole = ft_itoabase((long)x, 2)))
		return (NULL);
	dec_to_binary(x, dec);
	if (!(str = ft_strjoin(whole, dec)))
		return (NULL);
	free(whole);
	return (str);
}*/

static void	float_to_binary(long double x, char *nb_str)
{
	int			i;
	uintmax_t	tmp;

	i = 63;
	tmp = (uintmax_t)x;
	nb_str[64] = '\0';
	while (i != 0)
	{
		nb_str[i] = tmp % 2 + 48; 
		tmp /= 2;
		i--;
	}
	nb_str[0] = sign;
}

static void ft_swap(char a, char b)
{
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
}

static int	ft_strchr_index(char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	get_exp(char *binary) //also converts to scientific form
{
	int i;
	int exp;

	exp = 0;
	i = ft_strchr_index(binary, '.');
	while (binary[1] != '.' && binary[i] != '\0')
	{
		ft_swap(binary[i - 1], binary [i]);
		i--;
		exp++;
	}
	return (i);
}

static void	get_mantissa(char *binary, char *mantissa)
{
	int	i;

	i = 1;
	while (binary[i])
	{
		mantissa[i - 1] = binary[i];
		i++;
	}
	mantissa[i] = '\0';
}
/*
char	power_of_two(char *binary, int exp)
{
	int i;
	i = 0;

	while (binary[i] != '\0')
	{
		if (binary[i])
			exp / ft_power(2, i);
	}
}
*/

/*
** reminder of float limits (float, double and long double) :
** FLT_MAX
** DBL_MAX
** LDBL_MAX
*/
void	print_df(/*t_flags *flags,*/ double x)
{
	char mantissa[23]; //if 80 bits, mantissa[52] and exponent[11]
	char binary[65];
	int exp;
//	char *exp_str;
	int	sign;

	(x < 0) ? (sign = 1) : (sign = 0);
	float_to_binary(x, binary);
	ft_putendl("hello");
	exp = get_exp(binary); //also converts binary to scientific form
	get_mantissa(binary, mantissa);
	(sign == 0) ? (exp += 127) : (exp -= 127);
	ft_putendl(binary);
	ft_putendl(mantissa);
	//if (!(exp_str = ft_itoabase(exp, 2)))
	//	return (NULL);
	
}

/*void	print_ldf(t_flags *flags, long double x)
{

}*/

