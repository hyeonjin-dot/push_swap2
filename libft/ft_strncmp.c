/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:20:26 by hyejung           #+#    #+#             */
/*   Updated: 2021/01/14 18:05:33 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && str1[k] && str2[k])
	{
		if ((unsigned char)str1[k] == (unsigned char)str2[k])
		{
			i++;
			k++;
		}
		else
			break ;
	}
	return ((unsigned char)str1[k] - (unsigned char)str2[k]);
}
