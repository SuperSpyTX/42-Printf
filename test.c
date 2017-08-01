/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 14:37:15 by jkrause           #+#    #+#             */
/*   Updated: 2017/07/31 23:30:50 by jkrause          ###   ########.fr       */
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
	long g = -2;
	char *fmt = "Hello %ho world!%%";
	long f = ((void*)&g - (void*)&bufferwrite_module_flush);
	ft_printf(fmt, g, 0x13379001deadbeef, f, f);
	ft_printf("-----SEP-----\n");
	printf(fmt, g, 0x13379001deadbeef, f, f);
	//while (1);
}
