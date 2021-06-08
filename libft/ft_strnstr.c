/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:44:01 by hyejung           #+#    #+#             */
/*   Updated: 2021/01/15 18:11:29 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;

	i = ft_strlen(lit);
	if (!*lit || !lit)
		return ((char*)big);
	if (!*big || !big)
		return (0);
	while (i <= len && *(big))
	{
		if (!(ft_strncmp(big, lit, i)))
			return ((char*)big);
		big++;
		len--;
	}
	return (0);
}
