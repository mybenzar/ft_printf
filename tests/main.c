/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:57:47 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/13 19:33:03 by mybenzar         ###   ########.fr       */
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
	double	doub;
	double	doub2;
	double	doub3;
	double	doub4;
	double	doub5 = 1000000;
	double	doub6;

	doub6 = 0;
	doub5 *= doub5 * doub5;
	doub5 *= doub5 * doub5;
	doub5 *= doub5 * doub5;
	doub5 *= doub5 * doub5;
	doub5 *= doub5 * doub5;
	doub5 *= doub5 * doub5;
	doub4 = -10;
	doub3 = -56461.6551616465;
	doub = -0;
	doub6 /= doub;
	doub4 *= doub;
	doub2 = 165456.561165;
	float f = 0.42;
	double d = 1654.32354;
	long double ld = 42.42;
	int i = 42424242;

	
	ft_printf("-0 = %d\n", -0);
	printf("-0 = %d\n", -0);
	ft_printf("+0 = %d\n", +0);
	printf("+0 = %d\n", +0);

	printf("\nTEST DE f\n");
	ft_printf("-0 = %f\n", -0.0);
	printf("-0 = %f\n", -0.0);
	ft_printf("+0 = %f\n", +0.0);
	printf("+0 = %f\n", +0.0);
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf(".10float = |%.10f|\n", f), ft_printf(".10float = |%.10f|\n", f));
	printf("return = |%d | |%d|\n", printf(".0f = |%.0f|\n", f), ft_printf(".0f = |%.0f|\n", f));
	printf("return = |%d | |%d|\n", printf(".f = |%.f|\n", f), ft_printf(".f = |%.f|\n", f));
	printf("return = |%d | |%d|\n", printf(".10f = |%.10f|\n", f), ft_printf(".10f = |%.10f|\n", f));
	printf("return = |%d | |%d|\n", printf(".10float = |%.10f|\n", -f), ft_printf(".10float = |%.10f|\n", -f));
	printf("return = |%d | |%d|\n", printf(".0f = |%.0f|\n", -f), ft_printf(".0f = |%.0f|\n", -f));
	printf("return = |%d | |%d|\n", printf(".f = |%.f|\n", -f), ft_printf(".f = |%.f|\n", -f));
	printf("return = |%d | |%d|\n", printf(".10f = |%.10f|\n", -f), ft_printf(".10f = |%.10f|\n", -f));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf(".30double = |%.30f|\n", d), ft_printf(".30double = |%.30f|\n", d));
	printf("return = |%d | |%d|\n", printf(".30double = |%.30f|\n", -d), ft_printf(".30double = |%.30f|\n", -d));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf(".15L_double = |%.15Lf|\n", ld), ft_printf(".15L_double = |%.15Lf|\n", ld));
	printf("return = |%d | |%d|\n", printf(".15L_double = |%.15Lf|\n", -ld), ft_printf(".15L_double = |%.15Lf|\n", -ld));
	printf("return = |%d | |%d|\n", printf("10f = |%10f|\n", f), ft_printf("10f = |%10f|\n", f));
	printf("return = |%d | |%d|\n", printf("0f = |%0f|\n", f), ft_printf("0f = |%0f|\n", f));
	printf("return = |%d | |%d|\n", printf("10.10f = |%10.10f|\n", f), ft_printf("10.10f = |%10.10f|\n", f));
	printf("return = |%d | |%d|\n", printf("10.0f = |%10.0f|\n", f), ft_printf("10.0f = |%10.0f|\n", f));
	printf("---------------------------\n");
	printf("%d | %d\n", printf("|% lf|\n", f), ft_printf("|% lf|\n", f));
	printf("%d | %d\n", printf("|% lf|\n", -f), ft_printf("|% lf|\n", -f));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("+f = |%+f|\n", f), ft_printf("+f = |%+f|\n", f));
	printf("return = |%d | |%d|\n", printf("+f = |%+f|\n", -f), ft_printf("+f = |%+f|\n", -f));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("+f(d) = |%+f|\n", d), ft_printf("+f(d) = |%+f|\n", d));
	printf("return = |%d | |%d|\n", printf("+f(d) = |%+f|\n", -d), ft_printf("+f(d) = |%+f|\n", -d));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("+Lf = |%+Lf|\n", ld), ft_printf("+Lf = |%+Lf|\n", ld));
	printf("return = |%d | |%d|\n", printf("+Lf = |%+Lf|\n", -ld), ft_printf("+Lf = |%+Lf|\n", -ld));
	printf("--------------------\n");
	ft_printf("\nFt_Printf : | %1000.505f |", doub);
	printf("\nPrintf :    | %1000.505f |\n", doub);
	ft_printf("\nFt_Printf : | %50.600lf |", doub);
	printf("\nPrintf :    | %50.600lf |\n", doub);
	ft_printf("\nFt_Printf : | %70.600f |", doub3);
	printf("\nPrintf :    | %70.600f |\n", doub3);
	ft_printf("\nFt_Printf : | %70.50lf |", doub2);
	printf("\nPrintf :    | %70.50lf |\n", doub2);
	ft_printf("\nFt_Printf : | %f |", doub);
	printf("\nPrintf :    | %f |\n", doub);
	ft_printf("\nFt_Printf : | %-5.1f |", doub3);
	printf("\nPrintf :    | %-5.1f |\n", doub3);
	ft_printf("\nFt_Printf : | %+012.1f |", doub2);
	printf("\nPrintf :    | %+012.1f |\n", doub2);
	ft_printf("\nFt_Printf : | %012.7lf |", doub);
	printf("\nPrintf :    | %012.7lf |\n", doub);
	ft_printf("\nFt_Printf : | %#.f |", doub);
	printf("\nPrintf :    | %#.f |\n", doub);
	ft_printf("\nFt_Printf : | %027.3f |", doub3);
	printf("\nPrintf :    | %027.3f |\n", doub3);
	ft_printf("\nFt_Printf : | %#60.30f |", doub4);
	printf("\nPrintf :    | %#60.30f |\n", doub4);
	printf("---------------------------\n");
	ft_printf("\nFt_Printf : | %#+60.30f |", doub5);
	printf("\nPrintf :    | %#+60.30f |\n", doub5);
	ft_printf("\nFt_Printf : | %#2f |", doub2);
	printf("\nPrintf :    | %#2f |\n", doub2);
	printf("\nPrintf : | %#2f |\n", d);
	ft_printf("\nFt_Printf : | %#2f |\n", d);
	printf("---------------------------\n");
	printf("\nPrintf : | %#2Lf |\n", ld);
	ft_printf("\nFt_Printf : | %#2Lf |\n", ld);
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

	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("-10float = |%-10f|\n", f), ft_printf("-10float = |%-10f|\n", f));
	printf("return = |%d | |%d|\n", printf("-10-float = |%-10f|\n", -f), ft_printf("-10-float = |%-10f|\n", -f));
	printf("---------------------------\n");
	printf("return = |%d | |%d|\n", printf("-15double = |%-15f|\n", d), ft_printf("-15double = |%-15f|\n", d));
	printf("return = |%d | |%d|\n", printf("-15-double = |%-15f|\n", -d), ft_printf("-15-double = |%-15f|\n", -d));
}

