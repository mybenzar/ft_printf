/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:57:47 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/06 17:31:23 by mybenzar         ###   ########.fr       */
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
//	printf("FLT_MAX = %f\n", FLT_MAX);
//	printf("DBL_MAX = %lf\n", DBL_MAX);
//	printf("LDBL_MAX = %LF\n", LDBL_MAX);
//	f = DBL_MAX;
//	double d = 42.0;
	
	float f = 0.42;
	long double ld = 42.42;
	int i = 42424242;
	char *str = "42 42 42 42 42 42 42 42 42 42 42 42";


	printf("%d | %d\n", printf("test|%#.4o| et |%02o| |%0#14.0o|!!|\n", 012, 036, 12587499), ft_printf("test|%#.4o| et |%02o| |%0#14.0o|!!|\n", 012, 036, 12587499));
	printf("return = |%d | |%d|\n", printf("10.0f = |%10.0f|\n", f), ft_printf("10.0f = |%10.0f|\n", f));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("10f = |%10f|\n", f), ft_printf("10f = |%10f|\n", f));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("15L_double = |%15Lf|\n", ld), ft_printf("15L_double = |%15Lf|\n", ld));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("#f = |%#f|\n", f), ft_printf("#f = |%#f|\n", f));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("#f = |%#f|\n", -f), ft_printf("#f = |%#f|\n", -f));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("15L_double = |%15Lf|\n", -ld), ft_printf("15L_double = |%15Lf|\n", -ld));
	printf("----------PASSED-----------------\n");
	printf("%d | %d\n", printf("|%#-8.3o|\n", 0), ft_printf("|%#-8.3o|\n", 0));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("test|%-8p |%---32p |%#5.3x|%#024X|\n", &i, &str, 0x25, 50), ft_printf("test|%-8p |%---32p |%#5.3x|%#024X|\n", &i, &str, 0x25, 50));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("t|%04.2o|%#2oet |%#-8.3o titi|\n", 0, 0, 0), ft_printf("t|%04.2o|%#2oet |%#-8.3o titi|\n", 0, 0, 0));
	printf("---------------------------\n");
	printf("\n%d | %d\n", printf("titi % +---12.5% et%%%0004% et %+1%\n"), ft_printf("titi % +---12.5% et%%%0004% et %+1%\n"));
	printf("---------------------------\n");
	printf("\n%d | %d\n", printf("titi % +---12.5% et%%%0004% et %+1%\n"), ft_printf("titi % +---12.5% et%%%0004% et %+1%\n"));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("10%% = %10%\n"), ft_printf("10%% = %10%\n"));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("-5%% = %-5%\n"), ft_printf("-5%% = %-5%\n"));
	printf("---------------------------\n");
}



