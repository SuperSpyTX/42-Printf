/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer-print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 14:08:19 by jkrause           #+#    #+#             */
/*   Updated: 2017/08/01 00:14:23 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "math.h"
#include "limits.h"

char			*ft_putnum36_up(int num, int base, char *buf, int *size)
{
	char			*alpha;
	int				max;
	char			pls;

	alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	pls = 0;
	max = base - 1;
	if (num < 0)
		num *= -1;
	if (num > max)
		pls = alpha[0];
	else
	{
		pls = alpha[num];
		buf = (char*)ft_expandwrite(&pls, 1, buf, size);
	}
	return (buf);
}

char			*ft_putnum36_low(int num, int base, char *buf, int *size)
{
	char			*alpha;
	int				max;
	char			pls;

	alpha = "0123456789abcdefghijklmnopqrstuvwxyz";
	pls = 0;
	max = base - 1;
	if (num < 0)
		num *= -1;
	if (num > max)
		pls = alpha[0];
	else
	{
		pls = alpha[num];
		buf = (char*)ft_expandwrite(&pls, 1, buf, size);
	}
	return (buf);
}


long				ft_pow(long a, long b)
{
	long	res;

	res = a;
	while (b-- > 0)
		res *= a;
	return (res);
}

char			*ft_ltostr(long value, int base, char *alpha)
{
	char				*buffer;
	int 				buffsize;
	long 				cpy;
	long 				mul;

	buffsize = 0;
	cpy = value;
	mul = 0;
	while (cpy >= (long)base || cpy <= (long)-base)
	{
		cpy /= base;
		mul++;
	}
	buffer = (char*)ft_memalloc(sizeof(char) * mul + 3);
	if (value < 0 && base == 10)
		buffer[buffsize++] = '-';
	while (mul-- > 0)
	{
		cpy = (value / ft_pow(base, mul) % base);
		buffer[buffsize++] = alpha[cpy < 0 ? -cpy : cpy];
	}
	buffer[buffsize++] = alpha[(value < 0 ? -value : value) % base];
	buffer[buffsize++] = '\0';
	return (buffer);
}

/*
char			*ft_ltostr(long value, int base)
{
	return (ltostr_base(value, base, &ft_putnum_low));
}*/

char			*ft_itoa_basev2(int value, int base)
{
	return (ft_ltostr(value, base, "0123456789ABCDEF"));
}

int				fround(double x)
{
	if (x < 0)
		return (int)(x - 0.005);
	else
		return (int)(x + 0.005);
}
/*
char			*ft_ftoa(double f, int size)
{
	int integer = (int)f;
	double flt = f - (double)integer;
	char *buff = ft_itoa(integer);
	char *newbuff = 0;
	int length = 0;
	newbuff = ft_expandwrite(buff, ft_strlen(buff), newbuff, &length);
	free(buff);
	if (size > 0)
	{
		newbuff = ft_expandwrite(".", 1, newbuff, &length);
		flt *= ft_pow(10, size - 1);
		buff = ft_ltostr(fround(flt), 10, "0123456789");
		newbuff = ft_expandwrite(buff, ft_strlen(buff) + 1, newbuff, &length);
	}
	return (newbuff);
}
*/

typedef union {
  double n;
  uint64_t u64;
  struct {
    uint32_t lo;
    uint32_t hi;
  } u32;
} TValue;

char *decode(double n) {
  TValue t;
  t.n = n;
  if ((t.u32.hi << 1) >= 0xffe00000) {
    if (((t.u32.hi & 0x000fffff) | t.u32.lo) != 0) {
      return ("NaN");
    } else {
      return ("Infinity");
    }
  } else {
    int32_t e = (t.u32.hi >> 20) & 0x7ff;
    uint64_t m = t.u32.hi & 0xfffff;
    if (e == 0) {
      e++;
    } else {
      m |= 0x100000;
    }
    e -= 1043;
    if (t.u32.lo) {
      e -= 32;
      m = (m << 32) | t.u32.lo;
    }
    printf("%llu * 2^%d\n", (long long unsigned)m, (int)e);
	return (ft_ltostr_base((void*)(long long unsigned)m, 10, "0123456789abcdefghijklmnopqrstuvwxyz", 0));
  }
  return (0);
}

char			*ft_ftoa(double f, long size)
{
	char				*buff;
	char				*tmp;
	char				*calc;
	long				val;

	buff = ft_itoa((int)f);
	if (size > 0)
	{
		val = (intptr_t)(fround((f - (double)(int)f) * ft_pow(10, size)));
		ft_printf("%d\n", val);
		calc = ft_ltostr_base((void*)val, 10, "0123456789", 1);
		tmp = buff;
		buff = ft_strjoin(buff, ".");
		free(tmp);
		tmp = calc;
		calc = ft_strjoin(buff, calc);
		free(tmp);
		free(buff);
		buff = calc;
	}
	return (buff);
}

int				main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	//printf("%C\n", 'c');
	//printf("FTOA: %s\n", ft_ftoa(, 5));
	/*
	printf("DECODE: %s\n", decode(12.34));
	ft_printf("%lld %u %u\n", g.f, (g.t_ints.winnable >> 20) & 0x7ff, 0);
	printf("%lld %u %u\n", g.f, g.t_ints.un, g.t_ints.winnable);*/
	wchar_t *pls = L"PLS KMS";
	char *no = "NO KTHX";
	char *buffer = 0;
	int size = 0;
	while (*pls != '\0')
	{
		buffer = ft_expandwrite(pls++, 1, buffer, &size);
	}
	buffer = ft_expandwrite("\0", 1, buffer, &size);
	printf("W->C: %s\n", (char*)buffer);
	printf("%d\n", ft_printf("C->W: %S\n", no));
//	long val = (long)g;
	/*
	char *g = "gidufosiuh";
	double gs = 389.2040548352794876329876;
	int size = 6;
	printf("%s\n", ft_ftoav2(gs, size));
	printf("%.*f\n", size, gs);
	printf("%ld\n",

	printf("myfunc 0x%s\n", ft_ltostr((long)g, 16, "0123456789abcdef"));

	printf("0x%lx\n", (long)g);
	printf("%p", g);*/
}
