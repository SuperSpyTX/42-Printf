/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_module.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 22:43:59 by jkrause           #+#    #+#             */
/*   Updated: 2017/08/17 23:38:19 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*prefix(t_input *in, char *result, int *bsize)
{
	char				*tmp;

	tmp = 0;
	if (in->length_extended == 4)
		result = ft_expandwrite("-", 1, result, bsize);
	else if (in->module == 'i' && in->flag_all_signs_char != 0)
	{
		tmp = ft_strnew(1);
		tmp[0] = in->flag_all_signs_char;
		result = ft_expandwrite(tmp, 1, result, bsize);
	}
	else if (in->module == 'i' && in->flag_alt_mode && LC(in->type, 'x'))
		result = ft_expandwrite("0x", 2, result, bsize);
	if (tmp)
		free(tmp);
	return (result);
}

int					prefixstr(t_input *in)
{
	int					rsize;
	char				*result;

	result = 0;
	rsize = 0;
	result = prefix(in, result, &rsize);
	free(result);
	return (rsize);
}

char				*precise(t_input *in, char *str, char *result, int *bsize)
{
	int					precision;
	int					length;

	length = ft_strlen(str);
	precision = (in->precision == INT_MIN ? INT_MIN : in->precision);
	if (precision != INT_MIN)
	{
		if (precision <= 0 && in->module != 'i')
		{
		//	printf("Condition 1\n");
			result = prefix(in, result, bsize);
			length = precision + length;
		}
		else if (precision > 0 && in->module == 'i')
		{
		//	printf("Condition 2\n");
			result = prefix(in, result, bsize);
			result = ft_expandpad('0', precision, result, bsize);
		}
		else
			result = prefix(in, result, bsize);
	}
	else
		result = prefix(in, result, bsize);
	result = ft_expandwrite(str, length, result, bsize);
	return (result);
}

char				*width(t_input *in, char *str, char *result, int *bsize)
{
	int					width;
	int					length;

	length = prefixstr(in) + (in->precision > 0 ? in->precision : 0)
			+ ft_strlen(str);
	width = in->width - length;
	if (width > 0 && !in->flag_left_justify
			&& in->precision == INT_MIN
			&& in->flag_zero_pad && in->module == 'i')
		result = ft_expandpad('0', width, result, bsize);
	else if (width > 0)
		result = ft_expandpad(' ', width, result, bsize);
	return (result);
}

int					format_module(t_input *input, char *str)
{
	char				*result;
	int					bsize;

	result = 0;
	bsize = 0;
	if (input->precision != INT_MIN)
		input->precision -= ft_strlen(str);
	if (input->flag_left_justify)
	{
		result = precise(input, str, result, &bsize);
		result = width(input, str, result, &bsize);
	}
	else
	{
		result = width(input, str, result, &bsize);
		result = precise(input, str, result, &bsize);
	}
	result = ft_expandwrite("\0", 1, result, &bsize);
	write_module(result, 1);
	return (1);
}
