/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 22:36:11 by jkrause           #+#    #+#             */
/*   Updated: 2017/07/31 19:09:01 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

typedef union 	u_magic_number
{
	int				i;
	char			c;
	short			s;
	long			slong;
	long long		slonglong;
	unsigned int	uint;
	unsigned long	ulong;
	unsigned long long ulonglong;
	void			*magic;
}				t_magic_number;

long				ft_pow(long a, long b)
{
	long					res;

	res = a;
	while (b-- > 0)
		res *= a;
	return (res);
}

void				*interpret_mulcast(void *ptr, long base,
						long mul, int sign)
{
	long					ln;

	if (!sign)
		return ((void*)((unsigned long)ptr / ft_pow(base, mul) % base));
	else
	{
		ln = ((long)ptr / ft_pow(base, mul) % base);
		if (ln < 0)
			return ((void*)(ln *= -1));
	}
	return ((void*)ln);
}

long				mulsize(void *value, int base, int sign)
{
	long					size;
	long					cpy;
	unsigned long			ucpy;

	cpy = (long)value;
	ucpy = (unsigned long)value;
	size = 0;
	if (!sign)
	{
		while (ucpy >= (unsigned long)base)
		{
			ucpy /= base;
			size++;
		}
	}
	else
	{
		while (cpy >= (long)base || cpy <= (long)-base)
		{
			cpy /= base;
			size++;
		}
	}
	return (size);
}

char				*ft_ltostr(void *value, int base, char *alpha, int sign)
{
	char					*buffer;
	int						buffsize;
	unsigned long			ucpy;
	long					cpy;
	long					mul;

	buffsize = 0;
	printf("DEBUG: %ld\n", (long)value);
	ucpy = (unsigned long)value;
	cpy = (long)value;
	mul = mulsize(value, base, sign);
	buffer = (char*)malloc(sizeof(char) * mul + 3);
	if (cpy < 0 && sign)
		buffer[buffsize++] = '-';
	while (mul-- > 0)
		buffer[buffsize++] = alpha[(long)interpret_mulcast(value, base, mul, sign)];
	buffer[buffsize++] = alpha[((sign && cpy < 0 ? -cpy : ucpy) % base)];
	buffer[buffsize++] = '\0';
	return (buffer);
}

char				*ulong_to_str(unsigned long long v, int base)
{
	return (ft_ltostr((void*)v, base, "0123456789abcdefghijklmnopqrstuvwxyz", 0));
}

char				*test(t_magic_number pls, int base, char *alpha)
{
	return (ft_ltostr(pls.magic, base, alpha, 1));
}

int					main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	t_magic_number number = (t_magic_number)(void*)ULLONG_MAX;
	number = (t_magic_number)(void*)-2;
	//char *buf = "gfo9d8sugo98ufd";
	//printf("PF:%llu\nFT:%s\n", ULLONG_MAX, ft_ltostr((void*)(long)ULLONG_MAX, 10, "0123456789abcdefghijklmnopqrstuvwxyz"));
	printf("PF:%d\nFT:%s\nPF_MN: %ld",
			(char)ULLONG_MAX,
			ft_ltostr((void*)(intptr_t)number.i, 10, "0123456789abcdef", 1),
			(unsigned long)number.uint);
	//printf("PF:%u\nFT:%s\n", "323232", ulong_to_str(-0x32, 16));
}
