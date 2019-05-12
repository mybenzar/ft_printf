/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:57:47 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/12 13:20:27 by mybenzar         ###   ########.fr       */
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
//	float f = 0.42;
	double d = 1654.32354;
	long double ld = 42.42;
//	int i = 42424242;

	printf("\nPrintf : | %#2f |\n", d);
	ft_printf("\nFt_Printf : | %#2f |\n", d);
	printf("---------------------------\n");
	printf("\nPrintf : | %#2Lf |\n", ld);
	ft_printf("\nFt_Printf : | %#2Lf |\n", ld);
/*	
	printf("\nPrintf :    | %#2f |\n", doub2);
	printf("return = |%d | |%d|\n", printf("#.0f = |%#.0f|\n", d), ft_printf("#.0f = |%#.0f|\n", d));
	printf("return = |%d | |%d|\n", printf("#.0f = |%#.0f|\n", -d), ft_printf("#.0f = |%#.0f|\n", -d));

	printf("return = |%d | |%d|\n", printf("#.0Lf = |%#.0Lf|\n", ld), ft_printf("#.0Lf = |%#.0Lf|\n", ld));
	printf("return = |%d | |%d|\n", printf("#.-0Lf = |%#.0Lf|\n", -ld), ft_printf("#.-0Lf = |%#.0Lf|\n", -ld));
	printf("---------------------------\n");

	printf("return = |%d | |%d|\n", printf(" 010int = |% 010d|\n", -i), ft_printf(" 010int = |% 010d|\n", -i));
	printf("return = |%d | |%d|\n", printf("15L_double = |%15Lf|\n", ld), ft_printf("15L_double = |%15Lf|\n", ld));
	printf("return = |%d | |%d|\n", printf("15L_double = |%15Lf|\n", -ld), ft_printf("15L_double = |%15Lf|\n", -ld));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("' '.10f = |% .10f|\n", f), ft_printf("' '.10f = |% .10f|\n", f));
	printf("return = |%d | |%d|\n", printf("10f = |%10f|\n", f), ft_printf("10f = |%10f|\n", f));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("-10float = |%-10f|\n", f), ft_printf("-10float = |%-10f|\n", f));
	printf("return = |%d | |%d|\n", printf("-10-float = |%-10f|\n", -f), ft_printf("-10-float = |%-10f|\n", -f));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("-15double = |%-15f|\n", d), ft_printf("-15double = |%-15f|\n", d));
	printf("return = |%d | |%d|\n", printf("-15-double = |%-15f|\n", -d), ft_printf("-15-double = |%-15f|\n", -d));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("' '.10f = |% .10f|\n", f), ft_printf("' '.10f = |% .10f|\n", f));
	printf("return = |%d | |%d|\n", printf("' '.10-f = |% .10f|\n", -f), ft_printf("' '.10-f = |% .10f|\n", -f));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("' '.10d = |% .10f|\n", d), ft_printf("' '.10d = |% .10f|\n", d));
	printf("return = |%d | |%d|\n", printf("' '.10-d = |% .10f|\n", -d), ft_printf("' '.10-d = |% .10f|\n", -d));
*/
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

