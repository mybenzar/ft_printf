/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:57:47 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/10 12:31:36 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"
#include <float.h>
#include <math.h>
#include <limits.h>


// tests de float

int	main(void)
{
	//float f;
	//f = 42.01;
	//ft_printf("\nFt_Printf : | %f |", f);
	//printf("\nPrintf :    | %f |", f);
	
	char *s1;
	char *s2;
	char *res;

	s1 = ft_strdup("1");
	s2 = ft_strdup("3");
	res = vlq_sum(s1, s2);
	printf("res = %s\n", res);
	ft_strdel(&s1);
	ft_strdel(&s2);
	ft_strdel(&res);
}

