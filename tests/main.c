/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:57:47 by mybenzar          #+#    #+#             */
/*   Updated: 2019/04/27 22:27:40 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"
#include <float.h>
#include <math.h>

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
/*
int	main(void)
{
//	printf("FLT_MAX = %f\n", FLT_MAX);
//	printf("DBL_MAX = %lf\n", DBL_MAX);
//	printf("LDBL_MAX = %LF\n", LDBL_MAX);
//	double f;
//	int		exp;
	char *s1 = ft_strdup("1");
	char *s2 = ft_strdup("128");
//	char mod[100];

//	char *right = ft_strdup("01001100110011001100110011001100110011001100110");
//	int		n;

//	n = 513;
//	f = -25.3;
//	printf("frexp = %f\n, *exp = %d\n", frexp(f, &exp), exp);
//	printf("__________________________________\n\n");
//	printf("vlq_sum = %s\n", vlq_sum(s1, s2));
//	printf("__________________________________\n\n");
//	printf("vlq_mult = %s\n", vlq_mult(s1, s2));
//	printf("__________________________________\n\n");
//	print_df(f);
//	printf("__________________________________\n\n");
//	printf("ft_bintovlq right returns %s\n", ft_bintovlq(right));
//	printf("real printf for 25.3%.30f\n", f);
//	printf("my frexp returns %s\n", ft_frexp(f, &exp));
//	printf("vlq_cmp = %d\n", vlq_cmp(s1, s2));
//	printf("vlq_divmod = %s\n", vlq_divmod(s1, s2, mod));
//	printf("mod = %s\n", mod);
//	printf("vlq_sub = %s\n", vlq_sub(s1, s2));
	printf("vlq_div_float = %s\n", vlq_div_float(s1, s2));
//	printf("vlq_pow_ten = %s\n", vlq_pow_ten(1));
}
*/

//tests basiques
int main (void)
{
	printf("|%023.d|", 2147483647);
	printf("\n\n");
	ft_printf("|%023.d|", 2147483647);
	printf("\n\n");
	printf("\n\n");
/*	printf("|%- 23d|", 0);
	printf("\n\n");
	ft_printf("|%- 23d|", 0);*/
}
