/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 20:17:03 by hyejung           #+#    #+#             */
/*   Updated: 2021/01/11 16:24:10 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (0);
	new = (char*)malloc(len + 1);
	if (new == NULL)
		return (0);
	i = 0;
	while (i < len && *(s + start + i) && !(start > ft_strlen(s)))
	{
		*(new + i) = *(s + start + i);
		i++;
	}
	*(new + i) = '\0';
	return (new);
}
