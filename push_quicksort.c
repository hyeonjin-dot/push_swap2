/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:09:01 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/14 22:43:50 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*mklst(t_head head)
{
	t_li	*li;
	int		*lst;
	int		i;
	int		j;

	i = ft_lstlen(head);
	j = 0;
	li = head->fir;
	lst = (int *)malloc(sizeof(int) * (i + 1));
	while (li->next != NULL)
	{
		lst[j++] = li->data;
		li = li->next;
	}
	lst[j++] = li->data;
	lst[j] = '\0';
	return (lst);
}

int	partion(int *lst, int i, int j)
{
	int	x;
	int	a;
	int	b;
	int	tmp;

	x = lst[j];
	a = i - 1;
	b = i;
	while (b < j)
	{
		if (lst[b] <= x)
		{
			tmp = lst[++a];
			lst[a] = lst[b];
			lst[b] = tmp;
		}
	}
	tmp = lst[a + 1];
	lst[a + 1] = lst[j];
	lst[j] = tmp;
	return (a + 1);
}

int	quicksort(int *lst, int i, int j)
{
	if (i < j)
	{
		pb = partion(lst, i, j);
		quicksort(lst, i, pb - 1);
		quicksort(lst, pb, j);
	}
}
