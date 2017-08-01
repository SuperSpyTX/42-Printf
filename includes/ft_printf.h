/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 10:26:16 by jkrause           #+#    #+#             */
/*   Updated: 2017/07/31 22:51:15 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

/*
** Silly macros, I blame Oleg.
*/

# define CMP(x, y) x == y

/*
** Configuration (yes, you can change this via command line!)
** With -DMACRO=value
** Documented (Changable) Config Options:
** .
** Buffer_Type (String or Direct)
** String - Buffers to string
** Direct - Directly prints (continues to print if there's an error)
*/

# ifndef BUFFER_TYPE
#  define BUFFER_TYPE STRING
# endif

# define WRITEMODULE_WRITE 0
# define WRITEMODULE_FLUSH 1
# define PARSEMODULE_PARSE 2

/*
** Union for magic numbers.  Will make conversion for ft_ltostr_base easy.
*/

typedef union 		u_magicnum
{
	int				sint;
	intptr_t		intptr;
	intmax_t		intmax;
	size_t			usize_t;
	ssize_t			sssize_t;
	unsigned int	uint;
	char			schar;
	short			sshort;
	unsigned char	uchar;
	unsigned short	ushort;
	long			slong;
	long long		slonglong;
	unsigned long	ulong;
	void			*magic;
}					t_magicnum;

/*
** Modules (& Flags)
** TODO: I do not like that I'm having to pass the static pointer
** through the input struct, but it's the only way currently I can
** think of.  I need to come up with a better solution..
*/

typedef struct		s_input
{
	int				error;
	int				input_length;
	char			*original;

	int				flag_left_justify;
	int				flag_alt_mode;
	char			flag_all_signs_char;
	int				flag_zero_pad;
	int				width;
	int				precision;
	char			length;
	int				length_extended;
	char			type;
}					t_input;

int					bufferwrite_module_write(t_input *input, char *write);
int					bufferwrite_module_flush(t_input *input, void *nil);

int					parse_module(t_input *input, void *fmt);
int					integer_module(t_input *input, va_list *vaptr);
int					memes_module(t_input *input, va_list *ptr);

/*
** Module Manager
*/

typedef	int			(*t_module)(t_input *input, void *arg);

void				module_init();
void				module_init2();
int					module_call(char key, t_input *input, void *args);
void				write_module(char *str, int freeme);
int					write_flush(int error);

/*
** Main prototypes
*/

int					ft_printf(const char *fmt, ...);
#endif
