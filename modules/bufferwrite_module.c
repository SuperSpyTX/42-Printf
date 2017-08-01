/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufferwrite_module.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 16:42:25 by jkrause           #+#    #+#             */
/*   Updated: 2017/07/28 15:33:12 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*g_buffer;
int					g_buffersize;

int					bufferwrite_module_write(t_input *input, char *write)
{
	(void)input;
	if (g_buffersize < 1)
		g_buffer = ft_strnew(0);
	g_buffer = ft_expandwrite(write, ft_strlen(write),
			g_buffer, &g_buffersize);
	return (1);
}

int					bufferwrite_module_flush(t_input *input, void *nil)
{
	int size = 0;

	(void)input;
	(void)nil;
	g_buffer = ft_expandwrite("\0", 1, g_buffer, &g_buffersize);
	if ((int)nil != -1)
		write(1, g_buffer, g_buffersize);
	size = g_buffersize;
	g_buffersize = 0;
	if (size > 2)
		free(g_buffer);
	return (size);
}
