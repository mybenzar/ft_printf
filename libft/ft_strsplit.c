/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:41:38 by malavent          #+#    #+#             */
/*   Updated: 2019/01/31 11:22:50 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_split(char c, char split)
{
	return (c == split);
}

static int		ft_countsplit(char const *s, char split)
{
	unsigned int	i;
	int				size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (!(is_split(s[i], split)) && (is_split(s[i + 1], split)
		|| s[i + 1] == '\0'))
			size++;
		i++;
	}
	return (size);
}

static int		ft_wordsize(char const *s, char split, unsigned int *i)
{
	unsigned int word_size;

	word_size = 0;
	while (is_split(s[*i], split))
		*i += 1;
	while (s[*i] != '\0' && !is_split(s[*i], split))
	{
		word_size++;
		*i += 1;
	}
	return (word_size);
}

static void		ft_fill_strsplit(char const *s, char **str_split, char split)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	j = 0;
	i = 0;
	k = 0;
	while (str_split[j] != 0)
	{
		k = 0;
		while (is_split(s[i], split))
			i++;
		while (!is_split(s[i], split))
		{
			str_split[j][k] = s[i];
			i++;
			k++;
		}
		str_split[j][k] = '\0';
		j++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char			**str_split;
	unsigned int	size;
	int				word_size;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = -1;
	if (!s || (!(str_split = (char **)malloc(sizeof(char *)
	* (ft_countsplit(s, c) + 1)))))
		return (NULL);
	size = ft_countsplit(s, c);
	while (++j < size)
	{
		word_size = ft_wordsize(s, c, &i) + 1;
		if (!(str_split[j] = (char *)malloc(sizeof(char) * word_size)))
		{
			free(str_split);
			return (NULL);
		}
		word_size = 0;
	}
	str_split[size] = 0;
	ft_fill_strsplit(s, str_split, c);
	return (str_split);
}
