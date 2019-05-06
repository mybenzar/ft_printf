/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:09:08 by malavent          #+#    #+#             */
/*   Updated: 2019/05/06 17:31:23 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
#define __PRINTF_H
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <wchar.h>
# define ER_MODIF "warning : non compatible modifier"
# define F_TYPE "diouxXcspf"
# define VALID "0123456789#0.+- hlLdiouxXcspf"

#define DEBUG 0 

#include <stdio.h>

typedef enum	e_modif
{
	n, l, ll, L, h, hh
}				t_modif;

typedef struct	s_flags
{
		int len;
		char *spec;
		int	width;
		int dot;
		int sharp; 
		t_modif modif;
		int minus;	
		int plus; 
		char id_conv; 
		int	space;
		int zero;
}				t_flags;


int	ft_printf(const char *format, ...);

/*
**  Calculator Structure for Floats
*/
typedef struct	s_calc
{
	int 		len1;
	int			len2;
	int			len1_static;
	int			len2_static;
	int			max;
	int 		min;
	int			sum;
	int 		ten_dec;
}				t_calc;
	
/*
**  Print functions
*/

void	print_param(t_flags *flags, va_list va);
void 	int_converter(t_flags *flags, uintmax_t nb);
void 	str_converter(t_flags *flags, char *str);
void	pr_int(t_flags *flags, uintmax_t nb);
void	pr_uint(t_flags *flags, va_list va);
void	char_converter(t_flags *flags, unsigned char c);
void	float_converter(t_flags *flags, double x);
void	lfloat_converter(t_flags *flags, long double x);
void	print_float(t_flags *flags, char **res);

/*
**  	Print Utils functions
*/

void	ft_putnstr(char *str, int size);
char 	*ft_strupper(char *str);
void	print_nchar(int size, char c);
int		no_id_conv(char *format);
int		index_is_special(char *str);

/*
**		Parsing Functions
*/

int 	get_flag_conv(char *format, int *i, t_flags *flags);
int 	is_alt_special(char c);
int 	is_special(char c);
int 	get_size(char *spec, int *i); // chope la size pour la precision ou la width
void	get_flags(t_flags *flags); // chope les flags options
void	free_flags(t_flags *flags);

/*
**		Float Utils Functions
*/
char	*ft_dftoa(double x);
char	*ft_ldftoa(long double x);
char	**ft_frexp(double x);
char	**ft_frexpl(long double x);
void	get_res(char *mantissa, int exp, char **res);
char	*ft_bintowhole(char *vlq);
char	*ft_bintodec(char *vlq);
int		get_exp(char *exp_str);
int		fracdigits(char *dec);
void	res_neg_exp(char *mantissa, int exp, char **res);
void	res_big_exp(char *mantissa, int exp, char **res);
void	res_pos_exp(char *mantissa, int exp, char **res);
void	get_res(char *mantissa, int exp, char **res);


/*
**		String Numbers Manipulation and Calculations Functions
*/
void	calc_info(t_calc *info, char *s1, char *s2);
int		ft_str_isdigt(char *s); //to be added in libft
char 	*vlq_sum(char *s1, char *s2);
char	*vlq_mult(char *s1, char *s2);
char	*vlq_div_float(char *divid, char *divis); //ended up not using
int		ft_max(int a, int b);
int		ft_min(int a, int b);
char	*vlq_divmod(char *divid, char *divis, char *mod); //ended up not using
int		vlq_cmp(char *s1, char *s2); // ended up not using but should be added to libft
char	*vlq_sub(char *s1, char *s2); //ended up not using
char	*vlq_pow_ten(int pow);
char	*vlq_binpow(int n);
char	*vlq_fivepow(int n);
int		pow2(int pow);
const char *tab_pow(int pow);
char	*get_pow_ten(char *vlq, int n);
void	vlq_nshift(char *s, int size, int shifts);
void	vlq_shift_left(char *s, int size);
void	vlq_initialize(char *vlq, int c, int size);
void	vlq_tmp_conv(t_calc *info, char *s1, char *s2);
void	vlq_tmp_conv_rev(char *s, int size);
void	free_calc(t_calc *info);

/*
**		Debug
*/

void	printf_flags(t_flags *flags);
void	put_flags(t_flags *flags);
#endif

