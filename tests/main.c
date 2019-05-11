/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:57:47 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/11 16:15:10 by mybenzar         ###   ########.fr       */
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
	float f = 0.42;
	//double d = 42.0;
	long double ld = 42.42;

	printf("%45f\n", f);
	printf("return = |%d | |%d|\n", printf("15L_double = |%15Lf|\n", ld), ft_printf("15L_double = |%15Lf|\n", ld));
	printf("return = |%d | |%d|\n", printf("15L_double = |%15Lf|\n", -ld), ft_printf("15L_double = |%15Lf|\n", -ld));
	printf("return = |%d | |%d|\n", printf("' '.10f = |% .10f|\n", f), ft_printf("' '.10f = |% .10f|\n", f));
	printf("return = |%d | |%d|\n", printf("10f = |%10f|\n", f), ft_printf("10f = |%10f|\n", f));
/*	
 *

	char *s1;
	char *s2;
	char *res;

	s1 = ft_strdup("99");
	s2 = ft_strdup("3");
	res = vlq_sum(s1, s2);
	ft_putendl(res);
	ft_strdel(&s1);
	ft_strdel(&s2);
	ft_strdel(&res);

*/
}

