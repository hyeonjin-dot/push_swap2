/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:48:44 by hyejung           #+#    #+#             */
/*   Updated: 2021/01/06 15:29:17 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *start, int num, size_t size)
{
	unsigned char	*new;

	new = (unsigned char*)start;
	while (size-- > 0)
		*new++ = num;
	return (start);
}
