/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:20:44 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/04 15:16:39 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int		ft_min(int a, int b)
{
	if (a >= b)
		return (b);
	return (a);
}

void	vlq_initialize(char *vlq, int c, int size)
{
	int i;

	i = 0;
	while (i < size)
		vlq[i++] = c;
	vlq[i] = '\0';
}

int		ft_str_isdigit(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isdigit(s[i])))
			return (0);
		i++;
	}
	return (1);
}

char	*str_max(char *s1, char *s2, int len1, int len2)
{
	if (ft_max(len1, len2) == len1)
		return (s1);
	else
		return (s2);
}

void	calc_info(t_calc *info, char *s1, char *s2)
{
	int i;

	i = 0;
	info->len1 = ft_strlen(s1);
	info->len2 = ft_strlen(s2);
	info->len1_static = info->len1;
	info->len2_static = info->len2;
	info->max = ft_max(info->len1, info->len2);
	info->min = ft_min(info->len1, info->len2);
	info->sum = info->len1 + info->len2;
	info->ten_dec = 1;
}

void	free_calc(t_calc *info)
{
	ft_bzero(info, sizeof(t_calc));
	free(info);
}

char	*vlq_sum(char *s1, char *s2)
{
	char	*res;
	int		hold;
	int		i;
	t_calc	*info;
	
	if (!ft_str_isdigit(s1) || !ft_str_isdigit(s2))
	{
		ft_putendl("ERROR NOT A DIGIT");
		return (NULL);
	}

	if (!(info = (t_calc *)malloc(sizeof(t_calc))))
		return (NULL);
	calc_info(info, s1, s2);
	info->len1 -= 1;
	info->len2 -= 1;
	i = info->max + 1;
	if (!(res = ft_strnew(i)))
		return (NULL);
	vlq_initialize(res, 0, i);
	i--;
	while (info->len1 >= 0 || info->len2 >= 0 || i >= 0)
	{
		hold = 0;
		if ((info->len1 >= 0 && info->len2 >= 0 && ((s1[info->len1] + s2[info->len2] + res[i] - 48) > 57))
					|| (info->len1 >= 0 && s1[info->len1] + res[i] > 57) 
					|| (info->len2 >= 0 && s2[info->len2] + res[i] > 57))
		{	
			res[i] -= 10;
			hold = 1;
		}
			
			res[i] = res[i] + ((info->len1 >= 0) ? s1[info->len1] : 0);
			res[i] = res[i] + ((info->len2 >= 0) ? s2[info->len2] : 0);
			res[i] = res[i] - ((info->len1 >= 0 && info->len2 >= 0) ? 48 : 0);
		i--;
		if (i >= 0)
			res[i] += hold;
		if (res[0] == 1)
			res[i] += 48;
		info->len1--;
		info->len2--;
	}
	i = 0;
	while (res[i] == 0)
		i++;
	free_calc(info);
	return (res + i);
}

void	vlq_tmp_conv(t_calc *info, char *s1, char *s2)
{
	int i;

	i = 0;
	while (i <= info->len1)
	{
		s1[i] -= 48;
		i++;
	}
	i = 0;
	while (i <= info->len2)
	{	
		s2[i] -= 48;
		i++;
	}
}

void	vlq_tmp_conv_rev(char *s, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		s[i] += 48;
		i++;
	}
}

void	vlq_tmp_conv_rev2(t_calc *info, char *s1, char *s2)
{
	int i;

	i = 0;
	while (i < info->len1_static)
	{
		s1[i] += 48;
		i++;
	}
	i = 0;
	while (i < info->len2_static)
	{
		s2[i] += 48;
		i++;
	}
}

void	vlq_nshift(char *s, int size, int shifts)
{
	int i;

	i = 0;
	if (shifts == 0)
		return ;
	while (++i < shifts)
		vlq_shift_left(s, size);
}

void	vlq_shift_left(char *s, int size)
{
	int		i;
	char	*tmp;

	i = size - 1;
	if (!(tmp = ft_strdup(s)))
		return ;
	s[i--] = '0';
	while (i >= 0)
	{
		s[i] = tmp[i + 1];
		i--;
	}
	free(tmp);
}

char	*vlq_mult(char *s1, char *s2)
{	
	char	*sum;
	char	*res;
	char	*tmp_sum;
	t_calc	*info;
	int		j;
	int		i;
	int		hold;

	if (!ft_str_isdigit(s1) || !ft_str_isdigit(s2))
	{
		ft_putendl("ERROR NOT A DIGIT");
		return (NULL);
	}
	if (!(info = (t_calc *)malloc(sizeof(t_calc))))
		return (NULL);
	calc_info(info, s1, s2);
	info->len1 -= 1;
	info->len2 -= 1;
	i = info->sum;
	if (!(res = ft_strnew(i + 1)))
		return (NULL);
	if (!(sum = ft_strnew(info->max)))
		return (NULL);
	vlq_tmp_conv(info, s1, s2);
	vlq_initialize(sum, 0, info->max);
	while (info->len2 >= 0)
	{
		vlq_initialize(res, 0, info->sum + 1);
		i = info->sum;
		j = info->len1;
		hold = 0;
		while (j >= 0)
		{
			hold = 0;
			if (j >= 0 && info->len2 >= 0 && s1[j] * s2[info->len2] + res[i] >= 10)
			{
				hold = (res[i] + s1[j] * s2[info->len2]) / 10;
				res[i] = (res[i] + s1[j] * s2[info->len2]) % 10;
			}
			else if (info->len2 < 0)
				res[i] = 0;
			else
				res[i] += s1[j] * ((info->len2 >= 0) ? s2[info->len2] : 1);
			i--;
			res[i] += hold;
			j--;
		}
		vlq_tmp_conv_rev(res, info->sum + 1);
		if (info->ten_dec > 1)
			vlq_nshift(res, info->sum + 1, info->ten_dec);
		info->ten_dec++;
		if (!(tmp_sum = ft_strdup(sum)))
			return (NULL);
		free(sum);
		if (!(sum = ft_strdup(vlq_sum(tmp_sum, res))))
			return (NULL);
		free(tmp_sum);
		info->len2--;
	}
	i = 0;
	while (sum[i] == '0')
		i++;
	vlq_tmp_conv_rev2(info, s1, s2);
	free_calc(info);
	free(res);
	return (sum + i);
}

int		is_div_by_two(char *nb)
{
	ft_strrev(nb);
	if (nb[ft_strlen(nb) - 1] % 2)
		return (1);
	else
		return (0);
}


/*
 ** Returns 0 if equal, positive int if s1 > s2, neg int if s2 > s1
*/

int		vlq_cmp(char *s1, char *s2)
{
	int len1;
	int len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
		return (1);
	else if (len1 < len2)
		return (-1);
	else
		return (ft_strcmp(s1, s2));
}

char	*vlq_sub(char *s1, char *s2)
{
	char	*tmp;
	char 	*one;
	char	*diff;
	char	*tmp_diff;

	if (vlq_cmp(s1, s2) < 0)
	{
		ft_putendl("incorrect input : s2 is bigger than s1");
		return (NULL);
	}
	if (!(diff = ft_strdup("0")) || !(tmp = ft_strdup("0"))
		|| !(one = ft_strdup("1")) || !(tmp_diff = ft_strdup("0")))
		return (NULL);
	while (vlq_cmp(s1, tmp))
	{
		free(tmp);
		tmp = ft_strdup(vlq_sum(s2, diff));
		free(tmp_diff);
		tmp_diff = ft_strdup(diff);
		if (!vlq_cmp(s1, tmp))
		{
			free(tmp);
			return (diff);
		}
		free(diff);
		diff = ft_strdup(vlq_sum(one, tmp_diff));
	}
	free(tmp);
	return ("0");
}



char	*vlq_divmod(char *divid, char *divis, char *mod)
{
	char	*one;
	char	*tmp;
	char	*tmp_sum;
	char	*sum;
	char	*prev;

	if (!(one = ft_strdup("1")) || !(sum = ft_strdup("1")) || !(prev = ft_strdup("0")) || !(tmp = ft_strdup(divis)))
		return (NULL);
	vlq_initialize(mod, 0, 99);
	while (vlq_cmp(divid, tmp) >= 0)
	{
		tmp = ft_strdup(vlq_mult(divis, sum));
		tmp_sum = ft_strdup(sum);
		if (vlq_cmp(divid, tmp) <= 0)
		{
			free(tmp_sum);
			free(one);
			if (vlq_cmp(divid, tmp) < 0)
			{
				tmp_sum = ft_strdup(vlq_mult(prev, divis));
				ft_strcpy(mod, vlq_sub(divid, tmp_sum));
				free(tmp_sum);
				free(tmp);
				return (prev);
			}
			if (vlq_cmp(divid, tmp) == 0)
			{
				ft_strcpy(mod, "0");
				free(tmp);
				return (sum);
			}
		}
		free(prev);
		prev = ft_strdup(sum);
		free(sum);
		sum = ft_strdup(vlq_sum(tmp_sum, one));
		free(tmp_sum);
	}
	free(tmp);
	free(one);
	ft_strcpy(mod, divid);
	return ("0");
}

char	*vlq_pow_ten(int pow)
{
	int		i;
	char	*pow_ten;
	char	*zero;

	i = 0;
	if (!(pow_ten = ft_strdup("1")))
		return (NULL);
	zero = ft_strdup("00000000000000000");
	while (i < pow)
	{
		free(pow_ten);
		if (!(pow_ten = ft_strnew(i + 1)))
			return (NULL);
		pow_ten[0] = '1';
		ft_strncat(pow_ten, zero, i);
		i++;
	}
	free(zero);
	return (pow_ten);
}

char	*vlq_div_float(char *divid, char *divis)
{
	char 	mod[100];
	char	*pow_ten;
	char	*divid_pow;
	int		i;
	char	*ret;
	char	*zero;

	i = 0;
	if (!(pow_ten = ft_strdup("1")) || !(divid_pow = ft_strdup("1")) || !(ret = ft_strdup("1")))
		return (NULL);
	if (!(pow_ten = ft_strdup("1")))
		return (NULL);
	zero = ft_strdup("00000000000000000");
	while (mod[0] != '0')
	{
		free(pow_ten);
		if (!(pow_ten = ft_strnew(i + 1)))
			return (NULL);
		pow_ten[0] = '1';
		ft_strncat(pow_ten, zero, i);
		i++;
		free(divid_pow);
		divid_pow = ft_strdup(vlq_mult(pow_ten, divid));
		free(ret);
		ret = ft_strdup(vlq_divmod(divid_pow, divis, mod));
	}
	free(divid_pow);
	free(pow_ten);
	return (ret);
}

