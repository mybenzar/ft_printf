/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:57:47 by mybenzar          #+#    #+#             */
/*   Updated: 2019/05/10 20:27:18 by mybenzar         ###   ########.fr       */
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
	
	printf("%d | %d\n", printf("cc|%#.4X| et |%#0012x| |%#04hX| !!|\n", 0xaef, 0xe, (unsigned short)0), ft_printf("cc|%#.4X| et |%#0012x| |%#04hX| !!|\n", 0xaef, 0xe, (unsigned short)0));
	printf("%d | %d\n", printf("test|%#.4o|\n", 012), ft_printf("test|%#.4o|\n", 012));

/*	

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

