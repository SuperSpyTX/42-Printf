/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_module.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 16:20:41 by jkrause           #+#    #+#             */
/*   Updated: 2017/08/15 00:52:52 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** TODO: Determine the value of this function later..
*/
char				*prepend(char *orig, char *prepend, int opposite)
{
	char 				*result;

	if (opposite)
		result = ft_strjoin(orig, prepend);
	else
		result = ft_strjoin(prepend, orig);
	if (orig)
		free(orig);
	if (prepend)
		free(prepend);
	return (result);
}

char				*ppadding(t_input *input, char *result, int isnum)
{
	int					precision;
	char				*tmp;

	precision = (input->precision == -1 && isnum ? 1 : input->precision);
	if (precision == 0 && ((isnum && *result == '0') || !isnum))
	{
		free(result);
		return (0);
	}
	if (precision == -1 || (precision == 1 && isnum))
		return (result);
	precision = input->precision - ft_strlen(result);
	if (!isnum && precision < 0)
		result[precision] = '\0';
	else if (precision > 0)
	{
		tmp = ft_memalloc(precision);
		ft_memset(tmp, '0', precision);
		result = prepend(result, tmp, 0);
	}
	return (result);
}

char				*wpadding(t_input *input, char *result, int isnum)
{
	char				*tmp;
	int					len;
	int					width;

	if (!result)
		return (0);
	len = ft_strlen(result);
	width = input->width - len;
	if (len == 0)
		return (result);
	if (width > 0)
	{
		tmp = ft_memalloc(width);
		if (!input->flag_left_justify && isnum && input->flag_zero_pad
				&& input->precision == -1)
			ft_memset(tmp, '0', width);
		else
			ft_memset(tmp, ' ', width);
		result = prepend(result, tmp, (input->flag_left_justify ? 1 : 0));
	}
	return (result);
}

/*
char				*prefix(t_input *input, char *result)
{

}*/

int					format_module(t_input *input, char *str)
{
	char				*result;
	int					isnum;

	result = str;
	isnum = 0;
	if (LC(input->type, 'd') || LC(input->type, 'i') || LC(input->type, 'x') ||
			LC(input->type, 'u') || LC(input->type, 'o'))
		isnum = 1;
	
	if (!(LC(input->type, 'c')))
		result = ppadding(input, result, isnum);
	result = wpadding(input, result, isnum);
	if (result)
		write_module(result, 1);
	return (1);
}
