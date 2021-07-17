/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:24:33 by hyejung           #+#    #+#             */
/*   Updated: 2021/07/17 16:20:08 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int checkspace2(char c)
{
    if (c == ' ' || (c >= '\t' && c <= '\r'))
        return (1);
	else if (c == '\"')
		return (1);
    else
        return (0);
}

long long   ft_atoi2(const char *str)
{
    int         i;
    int         minus;
    long long   num;
    int         count;

    i = 0;
    num = 0;
    count = 0;
    while ((str[i] != '\0') && (checkspace2((char)str[i]) == 1))
        i++;
    minus = ((char)str[i] == '-') ? -1 : 1;
    if ((char)str[i] == '+' || minus == -1)
        i++;
    while ((char)str[i] >= '0' && (char)str[i] <= '9' && str[i])
        num = (num * 10) + ((char)str[i++] - '0');
    return (minus * num);
}

void	ft_error()
{
	write(1, "Error\n", 7);
	exit (1);
}

int		breakrotate(t_head *head, char c, int x)
{
	int		*lst;
	int		i;
    int		num;

	lst = mklst(head);
	i = 0;
	num = 0;
	while (lst[i])
	{
		if (c == 'b' && lst[i] <= x)
			num++;
		else if (c == 'a' && lst[i] >= x)
			num++;
		else
			break ;
		i++;
	}
	return (num);
}

int		checkrotate(t_head *head, char c, int pv)
{
	int		*lst;
	int		i;

	i = 0;
	lst = mklst(head);
	if (c == 'a')
	{
		while (lst[i])
		{
			if (lst[i] <= pv)
				return (i);
			i++;
		}
	}
	else
	{
		while (lst[i])
		{
			if (lst[i] > pv)
				return (i);
			i++;
		}
	}
	return (0);
}
