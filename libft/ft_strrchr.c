/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:34:33 by hyejung           #+#    #+#             */
/*   Updated: 2021/01/07 15:02:52 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int	i;
	int	max;

	i = 0;
	max = -1;
	while (str[i] != '\0')
	{
		if ((char)str[i] == (char)n)
			max = i;
		i++;
	}
	if (max != -1)
		return ((char*)(str + max));
	else if (n == '\0')
		return ((char*)(str + i));
	else
		return (0);
}
