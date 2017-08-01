/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:15:43 by jkrause           #+#    #+#             */
/*   Updated: 2017/08/01 00:15:20 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_input				*search(char *fmt)
{
	char				*search;
	t_input				*parsed;

	search = fmt;
	parsed = 0;
	while (*search != '\0')
	{
		search = ft_strchr(fmt, '%');
		if (search == 0)
			break ;
		parsed = (t_input*)ft_memalloc(sizeof(t_input));
		module_call(PARSEMODULE_PARSE, parsed, search);
		parsed->original = search;
		return (parsed);
	}
	return (0);
}

void				onpoint_isa_debug(t_input *iflag)
{
	printf("========= FLAG PARSE ==========\n");
	printf("original: %s\n", ft_strsub(iflag->original, 0, iflag->input_length + 1));
	printf("input_length: %d\n", iflag->input_length);
	printf("error: %d\n", iflag->error);
	printf("flag_left_justify: %d\n", iflag->flag_left_justify);
	printf("flag_alt_mode: %d\n", iflag->flag_alt_mode);
	printf("flag_all_signs_char: \"%c\"\n", iflag->flag_all_signs_char);
	printf("flag_zero_pad: %d\n", iflag->flag_zero_pad);
	printf("width: %d\n", iflag->width);
	printf("precision: %d\n", iflag->precision);
	printf("length: %c\n", iflag->length);
	printf("length_extended: %d\n", iflag->length_extended);
	printf("type: %c\n", iflag->type);
	printf("======= End Flag Parse ========\n");
}

int					ft_printf(const char *fmt, ...)
{
	va_list				start;
	t_input				*iflag;
	char				*current;

	current = (char*)fmt;
	module_init();
	va_start(start, fmt);
	while ((iflag = search(current)) != 0)
	{
		onpoint_isa_debug(iflag);
		write_module(ft_strsub(current, 0, (iflag->original - current)), 1);
		if (iflag->error || !module_call(iflag->type, iflag, &start))
		{
			write_flush(1);
			free(iflag);
			return (-1);
		}
		current += (iflag->original - current) + iflag->input_length + 1;
		free(iflag);
	}
	write_module(current, 0);
	va_end(start);
	return (write_flush(0));
}
