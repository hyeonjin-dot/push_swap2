/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:40:24 by hyejung           #+#    #+#             */
/*   Updated: 2021/01/06 18:09:33 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t	i;

	i = 0;
	while ((int)i < (int)n)
	{
		if (*(unsigned char *)ptr1 == *(unsigned char *)ptr2)
		{
			i++;
			ptr1++;
			ptr2++;
		}
		else
			return (*(unsigned char*)ptr1 - *(unsigned char*)ptr2);
	}
	return (0);
}
