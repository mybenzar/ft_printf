/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:57:47 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/06 12:29:57 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"
#include <float.h>
#include <math.h>
#include <limits.h>

/*
   char *ft_get_stdout(int *pfd, int *save);

   int main(void)
   {
   printf("the real printf returns:%-12c\n", '\n');
   ft_putchar('\n');
   ft_printf("my printf returns      :%-12c\n", '\n');
   printf("the real printf returns:%4c\n", 'U');
   ft_putchar('\n');
   ft_printf("my printf returns      :%4c\n", 'U');
   ft_printf("my printf : hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
   printf("the real one: hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
   ft_printf("my printf returns      :test %-12i et %--2.4s %24s !\n", 0, NULL, "coco");
   printf("the real printf returns:test %-12i et %--2.4s %24s !\n", 0, NULL, "coco");
   ft_printf("my printf returns      :toto %###.0o%#.o et %#.1o !\n", 0, 0, 0);
   printf("the real printf returns:toto %###.0o%#.o et %#.1o !\n", 0, 0, 0);	
   ft_printf("my printf returns      :toto %#.o et %#.1o\n", 0, 0);
   printf("the real printf returns:toto %#.o et %#.1o\n", 0, 0);
   ft_printf("my printf returns      :%o\n", -123654789);
   printf("the real printf returns:%o\n", -123654789);	
   return (0);
   }
   */

// tests de float

int	main(void)
{
//	printf("FLT_MAX = %f\n", FLT_MAX);
//	printf("DBL_MAX = %lf\n", DBL_MAX);
//	printf("LDBL_MAX = %LF\n", LDBL_MAX);
	float f = 0.42;
	double d = 42.0;
	long double ld = 42.42;
//	char **res;
//	f = DBL_MAX;


	printf("return = |%d | |%d|\n", printf("L_double = |%Lf|\n", ld), ft_printf("L_double = |%Lf|\n", ld));
	printf("return = |%d | |%d|\n", printf("-L_double = |%Lf|\n", -ld), ft_printf("-L_double = |%Lf|\n", -ld));
	printf("return = |%d | |%d|\n", printf(".30double = |%.30f|\n", d), ft_printf(".30double = |%.30f|\n", d));
	printf("return = |%d | |%d|\n", printf(".30double = |%.30f|\n", -d), ft_printf(".30double = |%.30f|\n", -d));

	printf("return = |%d | |%d|\n", printf(".15L_double = |%.15Lf|\n", ld), ft_printf(".15L_double = |%.15Lf|\n", ld));
	printf("return = |%d | |%d|\n", printf(".15L_double = |%.15Lf|\n", -ld), ft_printf(".15L_double = |%.15Lf|\n", -ld));
	
	printf("--------PASSED-------------------\n");
	printf("return = |%d | |%d|\n", printf("-15-double = |%-15f|\n", -d), ft_printf("-15-double = |%-15f|\n", -d));
	printf("return = |%d | |%d|\n", printf("double = |%f|\n", d), ft_printf("double = |%f|\n", d));
	printf("return = |%d | |%d|\n", printf("-double = |%f|\n", -d), ft_printf("-double = |%f|\n", -d));
	printf("return = |%d | |%d|\n", printf("float = |%f|\n", f), ft_printf("float = |%f|\n", f));
	printf("return = |%d | |%d|\n", printf("-float = |%f|\n", -f), ft_printf("-float = |%f|\n", -f));
	printf("return = |%d | |%d|\n", printf(".10float = |%.10f|\n", f), ft_printf(".10float = |%.10f|\n", f));
	printf("return = |%d | |%d|\n", printf(".0f = |%.0f|\n", f), ft_printf(".0f = |%.0f|\n", f));
	printf("return = |%d | |%d|\n", printf(".f = |%.f|\n", f), ft_printf(".f = |%.f|\n", f));
	printf("return = |%d | |%d|\n", printf(".10f = |%.10f|\n", f), ft_printf(".10f = |%.10f|\n", f));
	printf("return = |%d | |%d|\n", printf(".10float = |%.10f|\n", -f), ft_printf(".10float = |%.10f|\n", -f));
	printf("return = |%d | |%d|\n", printf(".0f = |%.0f|\n", -f), ft_printf(".0f = |%.0f|\n", -f));
	printf("return = |%d | |%d|\n", printf(".f = |%.f|\n", -f), ft_printf(".f = |%.f|\n", -f));
	printf("return = |%d | |%d|\n", printf(".10f = |%.10f|\n", -f), ft_printf(".10f = |%.10f|\n", -f));
	printf("---------------------------\n");

}



