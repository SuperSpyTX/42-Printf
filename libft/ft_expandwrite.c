/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expandwrite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 13:28:05 by jkrause           #+#    #+#             */
/*   Updated: 2017/07/14 02:55:28 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_expandwrite(void *new, int newlen, void *src, int *srcsize)
{
	int				length;
	int				newlength;
	char			*newbuf;

	length = newlen;
	newlength = *srcsize + length;
	newbuf = (char*)malloc(newlength);
	ft_memcpy(newbuf, src, *srcsize);
	ft_memcpy(newbuf + *srcsize, new, newlen);
	*srcsize = newlength;
	if (src)
		free(src);
	return (newbuf);
}
