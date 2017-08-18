/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 14:37:15 by jkrause           #+#    #+#             */
/*   Updated: 2017/08/17 23:36:50 by jkrause          ###   ########.fr       */
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
	ft_printf("%%x 0000042 == |%x|\n", 0000042);
	//printf("UL:%lld \n-1: %u \nOVERFLOW: %u \nhU: %lu\n", (long long)-9223372036854775808, -1, 4294967296, 4294967295, 4294967296);
	//while (1);
}
