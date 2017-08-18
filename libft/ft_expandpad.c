/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expandpad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:25:52 by jkrause           #+#    #+#             */
/*   Updated: 2017/08/17 22:07:09 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_expandpad(char c, int repeat, char *result, int *bsize)
{
	char				*tmp;

	tmp = ft_strnew(repeat);
	ft_memset(tmp, c, repeat);
	result = ft_expandwrite(tmp, repeat, result, bsize);
	free(tmp);
	return (result);
}
