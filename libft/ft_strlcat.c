/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:46:57 by hyejung           #+#    #+#             */
/*   Updated: 2021/01/14 16:33:07 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	checklen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return ((size_t)i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	int		i;
	int		j;

	i = 0;
	dstlen = checklen(dst);
	srclen = checklen((char*)src);
	j = dstlen;
	if (size < dstlen)
		return (srclen + size);
	while ((i < (int)(size - dstlen - 1)) && (src[i] != '\0'))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (srclen + dstlen);
}
