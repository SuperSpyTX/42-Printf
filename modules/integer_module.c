/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_module.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:23:49 by jkrause           #+#    #+#             */
/*   Updated: 2017/07/31 23:30:26 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				*magic_convert(t_input *input, void *arg, int sign)
{
	t_magicnum		number;
	void			*casted;

	number = (t_magicnum)arg;
	printf("DEBUG: %ld\n", (long)arg);
	if (CMP(input->length, 'l') || CMP(input->length, 't'))
		casted = (void*)(number.magic);
	else if (CMP(input->length, 'h') && !sign)
		casted = (void*)(input->length_extended
				? (intptr_t)number.uchar : (intptr_t)number.ushort);
	else if (CMP(input->length, 'h'))
		casted = (void*)(input->length_extended
				? (intptr_t)number.schar : (intptr_t)number.sshort);
	else if (CMP(input->length, 'j'))
		casted = (void*)number.intmax;
	else if (CMP(input->length, 'z') && !sign)
		casted = (void*)number.usize_t;
	else if (CMP(input->length, 'z'))
		casted = (void*)number.sssize_t;
	else if (!sign)
		casted = (void*)(intptr_t)number.uint;
	else
		casted = (void*)(intptr_t)number.sint;
	return (casted);
}

int					integer_conv(t_input *input, va_list ptr,
						int base, char *alpha)
{
	char			*buffer;
	void			*cancerfleetmakesmecancer;
	int				sign;

	sign = 1;
	if (input->type != 'd' && input->type != 'i'
			&& input->type != 'D' && input->type != 'I')
		sign = 0;
	cancerfleetmakesmecancer = magic_convert(input, va_arg(ptr, void*), sign);
	printf("DEBUG_CASTED: %lu\n", (unsigned long)cancerfleetmakesmecancer);
	if (CMP(input->type, 'u') || base != 10)
	{
		printf("PLS?\n");
		sign = 0;
	}
	buffer = ft_ltostr_base(cancerfleetmakesmecancer, base, alpha, sign);
	write_module(buffer, 1);
	return (1);
}

int					integer_module(t_input *input, va_list *vaptr)
{
	if (CMP(input->type, 'd') || CMP(input->type, 'D')
			|| CMP(input->type, 'u') || CMP(input->type, 'u')
			|| CMP(input->type, 'i') || CMP(input->type, 'I'))
		return (integer_conv(input, *vaptr, 10, "0123456789abcdef"));
	else if (CMP(input->type, 'x'))
		return (integer_conv(input, *vaptr, 16, "0123456789abcdef"));
	else if (CMP(input->type, 'o'))
		return (integer_conv(input, *vaptr, 8, "0123456789abcdef"));
	return (0);
}
