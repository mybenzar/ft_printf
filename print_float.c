/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:44:53 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/10 18:20:08 by mybenzar         ###   ########.fr       */
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
	return (nb);
}

char	*vlq_binpow(int pow)
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
	return ((char *)pow2tab[pow]);
}

char	*vlq_fivepow(int n)
{
	int i;
	char *res;
	char *tmp;
	char *five;

	i = 0;
	if (!(five = ft_strdup("5")) ||!(res = ft_strdup(five)))
		return (NULL);
	while (i < n)
	{
		if (!(tmp = ft_strdup(res)))
			return (NULL);
		ft_strdel(&res);
		if (!(res = vlq_mult(tmp, five)))
			return (NULL);
		ft_strdel(&tmp);
		i++;
	}
	ft_strdel(&five);
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
			if (!(pow = ft_strdup(vlq_binpow(i))) || !(tmp = ft_strdup(ret)))
				return (NULL);
			ft_strdel(&ret);
			if (!(ret = vlq_sum(tmp, pow)))
				return (NULL);
			ft_strdel(&pow);
			ft_strdel(&tmp);
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
	j = ft_strlen(vlq) - 1;
	if (!(ret = ft_strnew(ft_strlen(vlq) + 1)))
		return (NULL);
	vlq_initialize(ret, '0', ft_strlen(vlq));
	while (vlq[i] != '\0')
	{
		if (vlq[i] == '1')
		{
			if (!(pow = vlq_fivepow(i)) || !(tmp_pow = ft_strdup(pow)))
				return (NULL);
			ft_strdel(&pow);
			if (!(pow = get_pow_ten(tmp_pow, j)) || !(tmp = ft_strdup(ret)))
				return (NULL);
			ft_strdel(&tmp_pow);
			ft_strdel(&ret);
			if (!(ret = vlq_sum(tmp, pow)))
				return (NULL);
			ft_strdel(&pow);
			ft_strdel(&tmp);
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
	if (exp == 1023 && !ft_strchr(mantissa, '1'))
		right[i++] = '0';
	else
		right[i++] = '1';
	while (i < 52 + exp)
	{
		if (mantissa[j] == '0' || mantissa[j] == '1')
			right[i++] = mantissa[j++]; 
	}
	right[i] = '\0';
	res[0] = ft_strdup("0");
	res[1] = ft_bintodec(right);
	ft_strdel(&left);
	ft_strdel(&right);
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
	ft_strdel(&left);
}

void	res_pos_exp(char *mantissa, int exp, char **res)
{
	char	*left;
	char	*right;

	if (exp > 52)
		res_big_exp(mantissa, exp, res);
	if (!(left = ft_strnew(exp + 1)))
		return ;
	left[0] = '1';
	if (!(ft_strncat(left, mantissa, exp)))
		return ;
	if (!(right = ft_strdup(mantissa + exp)))
		return ;
	res[0] = ft_bintowhole(left);
	ft_strdel(&left);
	res[1] = ft_bintodec(right);
	ft_strdel(&right);
}

void	get_res(char *mantissa, int exp, char **res)
{
	if (exp < 0)
		res_neg_exp(mantissa, exp, res);
	else
		res_pos_exp(mantissa, exp, res);
}

/*
**	--> check_nan_inf checks if the number entered exists and is not infinite
**	and returns 1 after printing "nan" or "inf" if it is
*/
int		check_nan_inf(char *mantissa, char *exp_str/*, char sign*/)
{
	if (!ft_strcmp("11111111111", exp_str) && ft_strchr(mantissa, '1'))
		return (1);
	if (!ft_strcmp("11111111111", exp_str) && !ft_strchr(mantissa, '1'))
		return (-1);
	return (0);
}

/*
**	--> ft_frexp computes the mantissa and the exponent and stocks them in strings
**	it then calls out other functions (get_exp and get_res) to convert them into 
**	decimal strings
*/
char	**ft_frexp(double x)
{
	char *nb_str;
	char *mantissa;	
	char exp_str[12];
	char **res;
	int i;

	i = 0;
	exp_str[11] = '\0';
	if (!(res = (char **)malloc(sizeof(char *) * 2)) || !(nb_str = ft_dftoa(x))
		|| !(ft_strncpy(exp_str, nb_str + 1, 11))
		|| !(mantissa = ft_strdup(nb_str + 12)))
		return (NULL);
	if (check_nan_inf(mantissa, exp_str) == 1)
	{
		res[0] = ft_strdup("nan");
		res[1] = NULL;
		ft_strdel(&nb_str);
		return (res);
	}
	if (check_nan_inf(mantissa, exp_str) == -1)
	{
		res[0] = ft_strdup("inf");
		res[1] = NULL;
		ft_strdel(&nb_str);
		return (res);
	}
	get_res(mantissa, get_exp(exp_str), res);
	if (ft_strlen(res[0]) != 1 && res[0][0] == '0')
	{
		while (res[0][i] == '0')
			i++;
		res[0] += i;
	}
	ft_strdel(&mantissa);
	ft_strdel(&nb_str);
	return (res);
}
