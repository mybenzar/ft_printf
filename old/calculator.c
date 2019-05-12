/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:20:44 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/12 14:07:17 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



char	*do_sub(char *s1, char *s2, char *tmp, char *tmp_diff)
{
	char *diff;
	char 	*one;

	if (!(diff = ft_strdup("0")) || !(one = ft_strdup("1")))
		return (NULL);
	while (vlq_cmp(s1, tmp))
	{
		ft_strdel(&tmp);
		if (!(tmp = vlq_sum(s2, diff)))
			return (NULL);
		ft_strdel(&tmp_diff);
		if (!(tmp_diff = ft_strdup(diff)))
			return (NULL);
		if (!vlq_cmp(s1, tmp))
		{
			ft_strdel(&tmp);
			ft_strdel(&one);
			ft_strdel(&tmp_diff);
			return (diff);
		}
		ft_strdel(&diff);
		if (!(diff = vlq_sum(one, tmp_diff)))
			return (NULL);
	}
	ft_strdel(&one);
	return (diff);
}

char	*vlq_sub(char *s1, char *s2)
{
	char	*tmp;
	char	*diff;
	char	*tmp_diff;

	if (vlq_cmp(s1, s2) < 0)
		return (NULL);
	if (!(tmp = ft_strdup("0")) || !(tmp_diff = ft_strdup("0")))
		return (NULL);
	if (!(diff = do_sub(s1, s2, tmp, tmp_diff)))
		return (NULL);
	ft_strdel(&tmp);
	ft_strdel(&tmp_diff);
	ft_strdel(&diff);
	return ("0");
}

char	*vlq_divmod(char *divid, char *divis, char *mod)
{
	char	*one;
	char	*tmp;
	char	*tmp_sum;
	char	*sum;
	char	*prev;

	if (!(one = ft_strdup("1")) || !(sum = ft_strdup("1"))
		|| !(prev = ft_strdup("0")) || !(tmp = ft_strdup(divis)))
		return (NULL);
	vlq_initialize(mod, 0, 99);
	while (vlq_cmp(divid, tmp) >= 0)
	{
		tmp = ft_strdup(vlq_mult(divis, sum));
		tmp_sum = ft_strdup(sum);
		if (vlq_cmp(divid, tmp) <= 0)
		{
			ft_strdel(&tmp_sum);
			ft_strdel(&one);
			if (vlq_cmp(divid, tmp) < 0)
			{
				tmp_sum = ft_strdup(vlq_mult(prev, divis));
				ft_strcpy(mod, vlq_sub(divid, tmp_sum));
				ft_strdel(&tmp_sum);
				ft_strdel(&tmp);
				return (prev);
			}
			if (vlq_cmp(divid, tmp) == 0)
			{
				ft_strcpy(mod, "0");
				ft_strdel(&tmp);
				return (sum);
			}
		}
		ft_strdel(&prev);
		prev = ft_strdup(sum);
		ft_strdel(&sum);
		sum = ft_strdup(vlq_sum(tmp_sum, one));
		ft_strdel(&tmp_sum);
	}
	ft_strdel(&tmp);
	ft_strdel(&one);
	ft_strcpy(mod, divid);
	return ("0");
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
	ft_strdel(&divid_pow);
	ft_strdel(&pow_ten);
	return (ret);
}

