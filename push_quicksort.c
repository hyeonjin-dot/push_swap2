/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:09:01 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/15 16:56:52 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*mklst(t_head *head)
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

void	lstswap(int *lst, int i, int j)
{
	int		tmp;

	tmp = lst[i];
	lst[i] = lst[j];
	lst[j] = tmp;
}

int	partion(int *lst, int i, int j)
{
	int		x;
	int		a;
	int		b;

	x = lst[i];
	a = i + 1;
	b = j;
	while (a <= b)
	{
		while (lst[a] <= x && a <= j)
			a++;
		while (b >= (i + 1) && x <= lst[b])
			b--;
		if (a <= b)
			lstswap(lst, a, b);
	}
	lstswap(lst, a, b);
	return (b);
}

void	quicksort(int *lst, int i, int j)
{
	int		pv;

	if (i <= j)
	{
		pv = partion(lst, i, j);
		quicksort(lst, i, pv - 1);
		quicksort(lst, pv + 1, j);
	}
}
