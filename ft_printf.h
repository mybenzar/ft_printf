/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:09:08 by malavent          #+#    #+#             */
/*   Updated: 2019/05/12 14:09:30 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>
# define F_TYPE "diouxXcspf"
# define VALID "0123456789#0.+- hlLdiouxXcspf"
# define DEBUG 0

#include <stdio.h>

typedef enum	e_modif
{
	n, l, ll, L, h, hh
}				t_modif;
typedef struct	s_flags
{
	int			len;
	char		*spec;
	int			width;
	int			dot;
	int			sharp;
	t_modif		modif;
	int			minus;
	int			plus;
	char		id_conv;
	int			space;
	int			zero;
}				t_flags;

int				ft_printf(const char *format, ...);

/*
**  Calculator Structure for Floats
*/

typedef struct	s_calc
{
	int			len1;
	int			len2;
	int			len1_static;
	int			len2_static;
	int			max;
	int			min;
	int			sum;
	int			ten_dec;
}				t_calc;

/*
**		Print functions
*/

void			print_param(t_flags *flags, va_list va);
void			int_converter(t_flags *flags, uintmax_t nb);
void			str_converter(t_flags *flags, char *str);
void			char_converter(t_flags *flags, unsigned char c);
void			float_converter(t_flags *flags, double x);
void			lfloat_converter(t_flags *flags, long double x);
void			print_float(t_flags *flags, char **res);

/*
**  	Print Utils functions
*/

int				index_is_special(char *str);
int				get_min_width(t_flags *flag, int len);
void			fill_zero_space(t_flags *flag, int len);
int				get_base(char conv);
void			print_nb(t_flags *flag, char *nb_str);
void			print_nb_padding(t_flags *flag, char *nb_str);
void			handle_neg(t_flags *flags);

/*
**		Arg Parsing Functions
*/

intmax_t		conv_signed(t_flags *flags, va_list va);
void			pr_uint(t_flags *flags, va_list va);
void			other_conv(t_flags *flags, va_list va);

/*
**		Flag Parsing Functions
*/

int				get_flag_conv(char *format, int *i, t_flags *flags);
int				get_size(char *spec, int *i);
void			get_flags(t_flags *flags);
void			get_opt(t_flags *flags, int *i);
void			get_modif(t_flags *flags);
int				get_flag_no_id(char *format, int *i, t_flags *flags);
void			parsing_flags(t_flags *flags);

/*
**		Parsing Utils Functions
*/

int				is_fconv(char c);
int				is_alt_special(char c);
int				is_special(char c);
int				no_id_conv(char *format);
int				is_integer(char id_conv);

/*
**		Free Functions
*/

void			free_flags(t_flags *flags);
void			free_calc(t_calc *info);
void			free_res(char **res);

/*
**		Float Utils Functions
*/

char			*ft_dftoa(double x);
char			*ft_ldftoa(long double x);
char			*ft_bintowhole(char *vlq);
char			*ft_bintodec(char *vlq);
void			get_res(char *mantissa, int exp, char **res);
void			get_res_l(char *mantissa, int exp, char **res);
int				get_exp(char *exp_str);
int				get_exp_l(char *exp_str);
char			**ft_frexp(double x);
char			**ft_frexpl(long double x);
char			*ft_round(char *str, int prec);

/*
**		String Numbers Manipulation and Calculations Functions
*/

void			calc_info(t_calc *info, char *s1, char *s2);
char 			*vlq_sum(char *s1, char *s2);
char			*vlq_mult(char *s1, char *s2);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
char			*vlq_pow_ten(int pow);
char			*vlq_binpow(int n);
char			*vlq_fivepow(int n);
int				pow2(int pow);
char			*get_pow_ten(char *vlq, int n);
void			vlq_nshift(char *s, int size, int shifts);
void			vlq_shift_left(char *s, int size);
void			vlq_initialize(char *vlq, int c, int size);
void			vlq_tmp_conv(t_calc *info, char *s1, char *s2);
void			vlq_tmp_conv_rev(char *s, int size);
void			vlq_tmp_conv_rev2(t_calc *info, char *s1, char *s2);

/*
**		Debug
*/

void	printf_flags(t_flags *flags);
void	put_flags(t_flags *flags);
#endif
