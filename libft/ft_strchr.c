/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:08:18 by hyejung           #+#    #+#             */
/*   Updated: 2021/01/07 14:49:46 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;
	int	max;

	i = 0;
	max = -1;
	while (*str)
	{
		if (*(str) == (char)c)
			return ((char*)str);
		str++;
	}
	if (c == '\0')
		return ((char*)str);
	else
		return (0);
}
