/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 19:40:31 by hyejung           #+#    #+#             */
/*   Updated: 2021/01/07 17:58:14 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	str_len;
	size_t	i;
	char	*new;

	i = 0;
	str_len = ft_strlen(str);
	new = (char*)malloc(sizeof(char) * (str_len + 1));
	if (new == NULL)
		return (0);
	while (i < str_len)
	{
		*(new + i) = *(str + i);
		i++;
	}
	*(new + i) = '\0';
	return (new);
}
