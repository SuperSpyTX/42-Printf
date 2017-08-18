/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 17:16:16 by jkrause           #+#    #+#             */
/*   Updated: 2017/08/14 23:41:05 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_module				*g_modules;

void					module_init()
{
	if (!g_modules)
	{
		g_modules = (t_module*)ft_memalloc(sizeof(t_module*) * 256);
		g_modules[WRITEMODULE_WRITE] = (t_module)bufferwrite_module_write;
		g_modules[WRITEMODULE_FLUSH] = (t_module)bufferwrite_module_flush;
		g_modules[PARSEMODULE_PARSE] = (t_module)parse_module;
		g_modules[FORMATMODULE_FORMAT] = (t_module)format_module;
		module_init2();
	}
}

void					module_init2()
{
	g_modules['d'] = (t_module)integer_module;
	g_modules['D'] = (t_module)integer_module;
	g_modules['i'] = (t_module)integer_module;
	g_modules['I'] = (t_module)integer_module;
	g_modules['x'] = (t_module)integer_module;
	g_modules['X'] = (t_module)integer_module;
	g_modules['u'] = (t_module)integer_module;
	g_modules['U'] = (t_module)integer_module;
	g_modules['o'] = (t_module)integer_module;
	g_modules['O'] = (t_module)integer_module;
	g_modules['%'] = (t_module)memes_module;
}

int						module_call(char key, t_input *input, void *args)
{
	if (!g_modules[(int)key])
		return (0);
	return (g_modules[(int)key](input, args));
}

int						write_flush(int error)
{
	return (module_call(WRITEMODULE_FLUSH, 0, (error ? (void*)-1 : 0)));
}

void					write_module(char *str, int freeme)
{
	module_call(WRITEMODULE_WRITE, 0, str);
	if (freeme)
		free(str);
}
