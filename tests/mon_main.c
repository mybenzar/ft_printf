#include <stdio.h>
#include "../ft_printf.h"
#include <stdlib.h>

int		main(void)
{
	char *str;
	int i = 0;
	unsigned long long int lon = 1234567890123456789;
	double	doub;
	double	doub2;
	double	doub3;
	double	doub4;
	double	doub5 = 1000000;
	char *str2 = NULL;
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
	if (!(str = (char*)malloc(sizeof(char) * 50)))
		return (0);
	while (i < 49)
		str[i++] = 'A';
	str[i] = 0;
	/*
	**TEST DE %c et %p
	*/
	printf("\nTEST DE C ET P\n");
	ft_printf("\nFt_Printf : | %c |", str[0]);
	printf("\nPrintf :    | %c |\n", str[0]);
	ft_printf("\nFt_Printf : | %25c |", str[0]);
	printf("\nPrintf :    | %25c |\n", str[0]);
	ft_printf("\nFt_Printf : | %-12c |", str[0]);
	printf("\nPrintf :    | %-12c |\n", str[0]);
	ft_printf("\nFt_Printf : | %-5c |", str[0]);
	printf("\nPrintf :    | %-5c |\n", str[0]);
	ft_printf("\nFt_Printf : | %p |", &str[0]);
	printf("\nPrintf :    | %p |\n", &str[0]);
	ft_printf("\nFt_Printf : | %25p |", &str[0]);
	printf("\nPrintf :    | %25p |\n", &str[0]);
	ft_printf("\nFt_Printf : | %-12p |", &str[0]);
	printf("\nPrintf :    | %-12p |\n", &str[0]);
	ft_printf("\nFt_Printf : | %-5p |", &str[0]);
	printf("\nPrintf :    | %-5p |\n", &str[0]);
	ft_printf("\nFt_Printf : %p\n", str2);
	/*
	** TEST DE %s
	*/
	printf("\nTEST DE S\n");
	ft_printf("\nFt_Printf : | %s", str);
	printf("\nPrintf :    | %s\n", str);
	ft_printf("\nFt_Printf : | %*.*s |",15,8, str);
	printf("\nPrintf :    | %*.*s |\n",15,8, str);
	ft_printf("\nFt_Printf : | %5.s |", str);
	printf("\nPrintf :    | %5.s |\n", str);
	ft_printf("\nFt_Printf : | %*.*s |",-25,7, str);
	printf("\nPrintf :    | %*.*s |\n",-25,7, str);
	ft_printf("\nFt_Printf : | %*.*s |",2,-12, str);
	printf("\nPrintf :    | %*.*s |\n",2,-12, str);
	ft_printf("\nFt_Printf : | %*.*s |",-76,54, str);
	printf("\nPrintf :    | %*.*s |\n",-76,54, str);
	ft_printf("\nFt_Printf : | %*.*s |",37,0, str);
	printf("\nPrintf :    | %*.*s |\n",37,0, str);
	ft_printf("\nFt_Printf : | %*.*s |",37,5, str2);
	/*
	** TEST DE %d
	*/
	printf("\nTEST DE D ET I\n");
	ft_printf("\nFt_Printf : | %.30d |", 15);
	printf("\nPrintf :    | %.30d |\n", 15);
	ft_printf("\nFt_Printf : | %70.30d |", -15);
	printf("\nPrintf :    | %70.30d |\n", -15);
	ft_printf("\nFt_Printf : | %.0d |", 0);
	printf("\nPrintf :    | %.0d |\n", 0);
	ft_printf("\nFt_Printf : | %.1d |", 0);
	printf("\nPrintf :    | %.1d |\n", 0);
	ft_printf("\nFt_Printf : | %-5.1d |", -50);
	printf("\nPrintf :    | %-5.1d |\n", -50);
	ft_printf("\nFt_Printf : | %+12.1d |", 0);
	printf("\nPrintf :    | %+12.1d |\n", 0);
	ft_printf("\nFt_Printf : | % 12.7lld |", lon);
	printf("\nPrintf :    | % 12.7lld |\n", lon);
	ft_printf("\nFt_Printf : | %018.4hhd |", str[5]);
	printf("\nPrintf :    | %018.4hhd |\n", str[5]);
	ft_printf("\nFt_Printf : | %+27.3d |", 65740);
	printf("\nPrintf :    | %+27.3d |\n", 65740);
	/*
	** TEST DE %o
	*/
	printf("\nTEST DE O\n");
	ft_printf("\nFt_Printf : | %.30o |", 15);
	printf("\nPrintf :    | %.30o |\n", 15);
	ft_printf("\nFt_Printf : | %70.30o |", -15);
	printf("\nPrintf :    | %70.30o |\n", -15);
	ft_printf("\nFt_Printf : | %70.0o |", 0);
	printf("\nPrintf :    | %70.0o |\n", 0);
	ft_printf("\nFt_Printf : | %.1o |", 0);
	printf("\nPrintf :    | %.1o |\n", 0);
	ft_printf("\nFt_Printf : | %-5.1o |", 50);
	printf("\nPrintf :    | %-5.1o |\n", 50);
	ft_printf("\nFt_Printf : | %#12.1o |", 0);
	printf("\nPrintf :    | %#12.1o |\n", 0);
	ft_printf("\nFt_Printf : | %012.7llo |", lon);
	printf("\nPrintf :    | %012.7llo |\n", lon);
	ft_printf("\nFt_Printf : | %18.4hho |", str[5]);
	printf("\nPrintf :    | %18.4hho |\n", str[5]);
	ft_printf("\nFt_Printf : | %#27.3o |", 65740);
	printf("\nPrintf :    | %#27.3o |\n", 65740);
	ft_printf("\nFt_Printf : | %#02o |", 0);
	printf("\nPrintf :    | %#02o |\n", 0);
	/*
	** TEST DE %x
	*/
	printf("\nTEST DE x\n");
	ft_printf("\nFt_Printf : | %.30x |", 15);
	printf("\nPrintf :    | %.30x |\n", 15);
	ft_printf("\nFt_Printf : | %70.30x |", -15);
	printf("\nPrintf :    | %70.30x |\n", -15);
	ft_printf("\nFt_Printf : | %70.0x |", 0);
	printf("\nPrintf :    | %70.0x |\n", 0);
	ft_printf("\nFt_Printf : | %.1x |", 0);
	printf("\nPrintf :    | %.1x |\n", 0);
	ft_printf("\nFt_Printf : | %-5.1x |", 50);
	printf("\nPrintf :    | %-5.1x |\n", 50);
	ft_printf("\nFt_Printf : | %#12.1x |", 0);
	printf("\nPrintf :    | %#12.1x |\n", 0);
	ft_printf("\nFt_Printf : | %012.7llx |", lon);
	printf("\nPrintf :    | %012.7llx |\n", lon);
	ft_printf("\nFt_Printf : | %18.4hhx |", str[5]);
	printf("\nPrintf :    | %18.4hhx |\n", str[5]);
	ft_printf("\nFt_Printf : | %#27.3x |", 65740);
	printf("\nPrintf :    | %#27.3x |\n", 65740);
	ft_printf("\nFt_Printf : | %#02x |", 0);
	printf("\nPrintf :    | %#02x |\n", 0);
	/*
	** TEST DE %X
	*/
	printf("\nTEST DE X\n");
	ft_printf("\nFt_Printf : | %.30X |", 15);
	printf("\nPrintf :    | %.30X |\n", 15);
	ft_printf("\nFt_Printf : | %70.30X |", -15);
	printf("\nPrintf :    | %70.30X |\n", -15);
	ft_printf("\nFt_Printf : | %70.0X |", 0);
	printf("\nPrintf :    | %70.0X |\n", 0);
	ft_printf("\nFt_Printf : | %.1X |", 0);
	printf("\nPrintf :    | %.1X |\n", 0);
	ft_printf("\nFt_Printf : | %-5.1X |", 50);
	printf("\nPrintf :    | %-5.1X |\n", 50);
	ft_printf("\nFt_Printf : | %#12.1X |", 0);
	printf("\nPrintf :    | %#12.1X |\n", 0);
	ft_printf("\nFt_Printf : | %012.7llX |", lon);
	printf("\nPrintf :    | %012.7llX |\n", lon);
	ft_printf("\nFt_Printf : | %18.4hhX |", str[5]);
	printf("\nPrintf :    | %18.4hhX |\n", str[5]);
	ft_printf("\nFt_Printf : | %#27.3X |", 65740);
	printf("\nPrintf :    | %#27.3X |\n", 65740);
	ft_printf("\nFt_Printf : | %#02X |", 0);
	printf("\nPrintf :    | %#02X |\n", 0);
	/*
	** TEST DE %u
	*/
	printf("\nTEST DE U\n");
	ft_printf("\nFt_Printf : | %.30u |", 15);
	printf("\nPrintf :    | %.30u |\n", 15);
	ft_printf("\nFt_Printf : | %70.30u |", -15);
	printf("\nPrintf :    | %70.30u |\n", -15);
	ft_printf("\nFt_Printf : | %70.0u |", 0);
	printf("\nPrintf :    | %70.0u |\n", 0);
	ft_printf("\nFt_Printf : | %.1u |", 0);
	printf("\nPrintf :    | %.1u |\n", 0);
	ft_printf("\nFt_Printf : | %-5.1u |", 50);
	printf("\nPrintf :    | %-5.1u |\n", 50);
	ft_printf("\nFt_Printf : | %12.1u |", 0);
	printf("\nPrintf :    | %12.1u |\n", 0);
	ft_printf("\nFt_Printf : | %012.7llu |", lon);
	printf("\nPrintf :    | %012.7llu |\n", lon);
	ft_printf("\nFt_Printf : | %18.4hhu |", str[5]);
	printf("\nPrintf :    | %18.4hhu |\n", str[5]);
	ft_printf("\nFt_Printf : | %27.3u |", 65740);
	printf("\nPrintf :    | %27.3u |\n", 65740);
	ft_printf("\nFt_Printf : | %02u |", 0);
	printf("\nPrintf :    | %02u |\n", 0);
	/*
	** TEST DE %f
	*/
	printf("\nTEST DE f\n");
	ft_printf("\nFt_Printf : | %1000.505lf |", doub);
	printf("\nPrintf :    | %1000.505lf |\n", doub);
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
	ft_printf("\nFt_Printf : | %#2f |", doub2);
	printf("\nPrintf :    | %#2f |\n", doub2);
	ft_printf("\nFt_Printf : | %#60.30f |", doub4);
	printf("\nPrintf :    | %#60.30f |\n", doub4);
	ft_printf("\nFt_Printf : | %#+60.30f |", doub5);
	printf("\nPrintf :    | %#+60.30f |\n", doub5);
	ft_printf("\nFt_Printf : | %#.30F |", doub6);
	printf("\nPrintf :    | %#.30F |\n", doub6);
	doub2 *= doub2 * doub2 *doub2 *doub2;
	ft_printf("\nFt_Printf : | %#.30F |", doub2);
	printf("\nPrintf :    | %#.30F |\n", doub2);
	ft_printf("\nft_printf : %50v\n");
	ft_printf("\nft_printf : %50d\n", 50);
	free(str);
	return (0);
}
