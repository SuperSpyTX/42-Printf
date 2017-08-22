/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 14:37:15 by jkrause           #+#    #+#             */
/*   Updated: 2017/08/22 00:30:36 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int				main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//printf("%d\n", ft_printf("%s %#-0 +.2hhs          %% tert"));
	/*ft_printf("%.2x");
	ft_printf("%#+04.d");
	ft_printf("2 % 2.2d 4");*/
	//int pls = 0x45
	//786987964;
	//long g = -2;
	//char *fmt = "Hello %ho world!%%";
	//long f = ((void*)&g - (void*)&bufferwrite_module_flush);
	//ft_printf(fmt, g, 0x13379001deadbeef, f, f);
	//ft_printf("-----SEP-----\n");
	//printf(fmt, g, 0x13379001deadbeef, f, f);
	//printf("RESULT: %d\n", printf("aaron's passing of printf %S", "test"));
	//int value = -0x2;
	//ft_printf("FT: '%-20.12d' '%-#12.8x'\n", value, 0x222);
	//printf("PF: '%-20.12d' '%-#12.8x'\n", value, 0x222);
	//ft_printf("%%04.2i 42 == |%04.2i|\n", 42);
	//printf("%%04.2i 42 == |%04.2i|\n", 42);
	//ft_printf("%d", 2);
	//ft_printf("%%x 0000042 == |%x|\n", 0000042);
	//ft_printf("%%#o INT_MIN ==  %#o\n", INT_MIN);
	//printf("%%#o INT_MIN ==  %#o\n", INT_MIN);
	//ft_printf("\"%10s\"\n", "My First String, Hello World!");
	//ft_printf("NULL: \"% c\"\n", 0);
	//wchar_t *g = L"¥jhg";
	//char *f = (char*)g;
	//printf("|%*.*s|\n", 8, 5, "Hello World");
	//printf("aaaa%hhn", 0);
	/*int eclipsepls = 0;
	ft_printf("PLS ECLIPSE: %d\n%n", 0, &eclipsepls);
	ft_printf("STOP PUTTING LYRICS OF THE SONG IM LISTENING TO IN MY CODE FFS: %d\n", eclipsepls);
	ft_printf("Kashim a %d histoires à raconter\n%n", 1001, &eclipsepls);
	ft_printf("STOP PUTTING LYRICS OF THE SONG IM LISTENING TO IN MY CODE FFS: %d\n", eclipsepls);*/
	//wchar_t c[3] = L"@@";
	//ft_printf("FT: %S\n", c);
	//ft_printf("%5%");
	//ft_printf("|%5.2x|\n", 5427);
	//printf("|%5.2x|", 5427);
	ft_printf("FT: |%5.2s is a string.|\n", "");
	printf("PF: |%5.2s is a string.|\n", "");
	//int nb2 = 42;
	//ft_printf("LALALALALAL\n%n", &nb2);
	//ft_printf("%d\n", nb2);
	//ft_printf("Kashim a %d histoires à raconter\n%n", 1001, &nb2);
	//ft_printf("%d\n", nb2);
	//ft_printf("%d%n", '\t', &nb2);
	//ft_printf("%d\n", nb2);
	//ft_printf("SIZE: %2.*s\n", 5, "1337");
	//ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	//ft_printf("%%-5.3s |%-5.3s|\n","LYDI");
	//printf("%%-5.3s |%-5.3s|","LYDI");
	//printf("UL:%lld \n-1: %u \nOVERFLOW: %u \nhU: %lu\n", (long long)-9223372036854775808, -1, 4294967296, 4294967295, 4294967296);
	//while (1);
}
