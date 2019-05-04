/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:44:53 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/04 16:38:37 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
 **	reminder of float limits (float, double and long double) :
 **	FLT_MAX
 **	DBL_MAX
 **	LDBL_MAX
 */

/*
 **	---> ft_dftoa extracts the binary value of the float into a string
 */
char	*ft_dftoa(double x)
{
	int					i;
	unsigned long		tmp;
	char				*nb_str;

	i = 0;
	if (!(nb_str = (char *)malloc(sizeof(char) * 65)))
		return (NULL);
	tmp = *(unsigned long *)(&x);
	while (i <= 63)
	{
		if (tmp & 1)
			nb_str[i] = '1';
		else
			nb_str[i] = '0';
		tmp >>= 1;
		i++;
	}
	nb_str[i] = '\0';
	ft_strrev(nb_str);
	if (DEBUG)
		ft_printf("at the end of dftoa, nb_str = %s & len = %d\n", nb_str, (int)ft_strlen(nb_str));
	return (nb_str);
}

int pow2(int pow)
{
	const int pow2tab[15] =
	{
		1, 2, 4, 8, 16, 32, 64, 128, 
		256, 512, 1024, 2048, 4096, 8192,
		16384
	};
	return (pow2tab[pow]);
}

/*
 **	---> get_exp computes the decimal value of the exponent and
 **	returns an int. 1023 is the bias for 64 bits (float convention)
 */
int	get_exp(char *exp_str)
{
	int nb;
	int i;
	int j;

	j = 10;
	i = 0;
	nb = 0;
	while (exp_str[i] != '\0')
	{
		if (exp_str[i] == '1')
			nb = nb + pow2(j);
		i++;
		j--;
	}
	nb -= 1023;
	//(sign = 0) ? (nb -= 1023) : (nb += 1023);
	return (nb);
}

const char	*tab_pow(int pow)
{
	const char *pow2tab[64] =
	{
		"1", "2", "4", "8", "16", "32", "64", "128", "256", "512", "1024",
		"2048", "4096", "8192", "16384", "32768", "65536", "131072", "262144",
		"524288", "1048576", "2097152", "4194304", "8388608", "16777216", 
		"33554432", "67108864", "134217728", "268435456", "536870912",
		"1073741824", "2147483648", "4294967296", "8589934592", "17179869184",
		"34359738368", "68719476736", "137438953472", "274877906944", "549755813888", 
		"1099511627776", "2199023255552", "4398046511104", "8796093022208",
		"17592186044416", "35184372088832", "70368744177664", "140737488355328",
		"281474976710656", "562949953421312", "1125899906842624",
		"2251799813685248", "4503599627370496", "9007199254740992", "18014398509481984",
		"36028797018963968", "72057594037927936", "144115188075855872",
		"288230376151711744", "576460752303423488", "1152921504606846976",
		"2305843009213693952", "4611686018427387904", 0
	};
	return (pow2tab[pow]);
}

char	*vlq_binpow(int n)
{
/*	int i;
	char *res;
	char *tmp;
	char *two;

	i = 0;
	if (!(two = ft_strdup("2")))
		return (NULL);
	if (n <= 62)
		return ((char *)tab_pow(n));
	else
	{
		i = 62;
		if (!(res = ft_strdup(((char *)tab_pow(i)))))
			return (NULL);
		while (i < n)
		{
			if (!(tmp = ft_strdup(res)))
				return (NULL);
			free(res);
			if (!(res = ft_strdup(vlq_mult(tmp, two))))
				return (NULL);
			free(tmp);
			i++;
		}
	}
	free(two);*/
	return ((char *)tab_pow(n));
}

char	*vlq_fivepow(int n)
{
	int i;
	char *res;
	char *tmp;
	char *five;

	i = 0;
	if (!(five = ft_strdup("5")))
		return (NULL);
	if (!(res = ft_strdup(five)))
		return (NULL);
	while (i < n)
	{
		if (!(tmp = ft_strdup(res)))
			return (NULL);
		free(res);
		if (!(res = ft_strdup(vlq_mult(tmp, five))))
			return (NULL);
		free(tmp);
		i++;
	}
	free(five);
	return (res);
}

/*
 **	---> bintowhole converts the exponent binary string into a decimal string
 **	by multiplying corresponding powers of two by '1' bits
 */
char	*ft_bintowhole(char *vlq)
{
	int i;
	char *ret;
	char *tmp;
	char *pow;

	i = 0;
	if (!(ret = ft_strnew(ft_strlen(vlq) + 1)))
		return (NULL);
	ft_strrev(vlq);
	while (vlq[i] != 0)
	{
		if (vlq[i] == '1')
		{
			if (!(pow = ft_strdup(vlq_binpow(i))))
				return (NULL);
			if (!(tmp = ft_strdup(ret)))
				return (NULL);
			free(ret);
			if (!(ret = ft_strdup(vlq_sum(tmp, pow))))
				return (NULL);
			free(pow);
			free(tmp);
		}
		i++;
	}
	return (ret);
}

/*
 **	---> fracdigits gets the least significant bit which corresponds
 **	to the biggest power of ten that the first '1' bit of right is going
 **	to be multiplied by
 */
int		fracdigits(char *dec)
{
	int i;

	i = ft_strlen(dec) - 1;
	printf("dec = %s\n", dec);
	while (dec[i] != '\0' && dec[i] != '1')
	{
		printf("dec[%d] = %c\n", i, dec[i]);
		i--;
	}
	return (i);
}

char	*get_pow_ten(char *vlq, int n)
{
	char	*ret;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(vlq) + n;
	if (!(ret = ft_memalloc(size + 1)))
		return (NULL);
	vlq_initialize(ret, '0', size);
	while (vlq[i] != '\0')
	{
		ret[i] = vlq[i];
		i++;
	}

	return (ret);
}

/*
 **	---> bintodec computes the following sum : (sum 5^(frac_digits - i) 
 **	which isequal to the decimal part (in base 10)
 */
char	*ft_bintodec(char *vlq)
{
	int i;
	int j;
	char *ret;
	char *tmp;
	char *pow;
	char *tmp_pow;

	i = 0;
//	j = fracdigits(vlq);
	j = ft_strlen(vlq) - 1;
	if (!(ret = ft_strnew(ft_strlen(vlq) + 1)))
		return (NULL);
	vlq_initialize(ret, '0', ft_strlen(vlq));
	while (vlq[i] != '\0')
	{
		if (vlq[i] == '1')
		{
			if (!(pow = ft_strdup(vlq_fivepow(i))))
				return (NULL);
			tmp_pow = ft_strdup(pow);
			free(pow);
			pow = get_pow_ten(tmp_pow, j);
			free(tmp_pow);
			tmp = ft_strdup(ret);
			free(ret);
			ret = ft_strdup(vlq_sum(tmp, pow));
			free(pow);
			free(tmp);
		}
		i++;
		j--;
	}
	return (ret);
}

/*
 **	---> get_res converts the binary char into left & right
 **	left[0] = '1': multiply by 2^52 to get MSB
 **	left is the part on the left of the floating point
 **	right is the part on the right of the floating point
 */
void	res_neg_exp(char *mantissa, int exp, char **res)
{

	char	*left;
	char	*right;
	int		i;
	int		j;

	i = 0;
	j = 0;
	exp = -exp;
	if (!(left = ft_strnew(exp + 1)))
		return ;
	if (!(right = ft_strnew(52 + exp)))
		return ;
	left[0] = '0';
	while (i < exp - 1)
		right[i++] = '0';
	right[i++] = '1';
	while (i < 52 + exp)
	{
		if (mantissa[j] == '0' || mantissa[j] == '1')
			right[i++] = mantissa[j++]; 
	}
	right[i] = '\0';
	//res[0] = ft_bintowhole(left);
	res[0] = ft_strdup("0");
	res[1] = ft_bintodec(right);
}

void	res_big_exp(char *mantissa, int exp, char **res)
{
	char	*left;
	int		i;

	i = 0;
	if (!(left = ft_strnew(exp + 1)))
		return ;
	left[0] = '1';
	if (!(ft_strncat(left, mantissa, exp)))
		return ;
	while (left[i] == '0' || left[i] == '1')
		i++;
	printf("i = %d\n", i);
	while (i < exp + 1)
		left[i++] = '0';
	res[0] = ft_bintowhole(left);
	res[1] = ft_strdup("0");
}

void	res_pos_exp(char *mantissa, int exp, char **res)
{
	char	*left;
	char	*right;

	if (exp > 52)
		res_big_exp(mantissa, exp, res);
	if (!(left = ft_strnew(exp + 1)))
		return ;
	if (!(right = ft_strnew(52 - exp)))
		return ;
	left[0] = '1';
	if (!(ft_strncat(left, mantissa, exp)))
		return ;
	mantissa += exp;
	if (!(ft_strcpy(right, mantissa)))
		return ;
	res[0] = ft_bintowhole(left);
	free(left);
	left = NULL;
	res[1] = ft_bintodec(right);
	free(right);
	right = NULL;
}

void	get_res(char *mantissa, int exp, char **res)
{
	res[2] = 0;
	if (exp < 0)
		res_neg_exp(mantissa, exp, res);
	else
		res_pos_exp(mantissa, exp, res);
}

/*
 **	--> ft_frexp computes the mantissa and the exponent and stocks them in strings
 **	it then calls out other functions (get_exp and get_res) to convert them into 
 **	decimal strings
 */
char	**ft_frexp(double x/*, int *exp*/)
{
	char *nb_str;
	char mantissa[54]; //if 64 bits, mantissa[23] else if 80 bits, mantissa[52] and exponent[11]
	char exp_str[12];
	int	sign;
	char **res;
	int i;

	i = 0;
	(x < 0) ? (sign = 1) : (sign = 0);
	mantissa[53] = '\0';
	exp_str[11] = '\0';
	if (!(res = (char **)malloc(sizeof(char *) * 3)))
		return (NULL);
	if (!(nb_str = (ft_dftoa(x))))
		return (NULL);
	nb_str += 1;
	if (!(ft_strncpy(exp_str, nb_str, 11)))
		return (NULL);
	nb_str += 11;
	if (!(ft_strncpy(mantissa, nb_str, 52)))
		return (NULL);
	get_res(mantissa, get_exp(exp_str), res);
	if (DEBUG)
	{
		printf("res 0 = %s \n", res[0]);
		printf("res 1 = %s \n", res[1]);
	}
	if (ft_strlen(res[0]) != 1 && res[0][0] == '0')
	{
		while (res[0][i] == '0')
			i++;
		res[0] += i;
	}
	return (res);
}

