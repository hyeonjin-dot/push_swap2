/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:10:41 by hyejung           #+#    #+#             */
/*   Updated: 2021/01/07 23:12:49 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_strtrim(char c, char const *set1, size_t setlen)
{
	size_t	num;

	num = 0;
	while (num < setlen)
	{
		if (c == set1[num])
			return (1);
		num++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	end;
	size_t	i;
	size_t	k;
	char	*new;

	k = 0;
	i = 0;
	if (!s1)
		return ((char*)s1);
	end = ft_strlen(s1) - 1;
	set_len = ft_strlen(set);
	while (s1[i] != '\0' && (check_strtrim(s1[i], set, set_len) == 1))
		i++;
	while (end > i && (check_strtrim(s1[end], set, set_len) == 1))
		end--;
	if (!(new = (char*)malloc(sizeof(*s1) * (end - i + 2))))
		return (0);
	while (i <= end && s1[i])
	{
		*(new + k) = s1[i++];
		k++;
	}
	*(new + k) = '\0';
	return (new);
}
