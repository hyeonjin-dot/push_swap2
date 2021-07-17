/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sortother.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:37:21 by hyejung           #+#    #+#             */
/*   Updated: 2021/07/17 17:10:00 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		forbreak(t_head *head, char c, int x, int y, int len)
{
	int		bk;

	bk = breakrotate(head, c, x);
	if (y <= 0)
	{
		if (bk >= len)
			return (0);
		rotate(&head, c);
	}
	else
	{
		if (bk >= ft_lstlen(head))
			return (0);
		revrotate(&head, c);
	}
	return (1);
}

void	rerotate(t_head *head, char c, int i, int j, int y)
{
	if (j < i)
		i = j;
	while (j != 0 && i-- > 0)
	{
		if (checksort(head, c) + 1 == 0)
			break ;
		if ((j >= i && y <= 0) || (j < i && y > 0))
			revrotate(&head, c);
		else
			rotate(&head, c);
	}
	return ;
}

void	sortotherb(t_head *bhed, t_head *head)
{
    int		len;
    int		x;
	int		y;
	int		i;

	x = makepivot(bhed, 'b', 'b');
	len = checksort(bhed, 'b') + 1;
	i = 0;
	y = checkrotate(bhed, 'b', x) - ((ft_lstlen(bhed) - 1) / 2);
	while (len-- > 0)
	{
		if (bhed->fir->data >= x)
			push(&bhed, &head, 'a');
		else
		{
			if (forbreak(bhed, 'b', x, y, len) == 0)
				break ;
			i++;
		}
		if (checksort(head, 'a') == 2 || checksort(head, 'a') == 4)
			re_sort(head, bhed, 'a');
	}
	rerotate(bhed, 'b', i, 0, y);
	lastsort(head, bhed);
}

int		makex(t_head *head, t_head *bhed)
{
	if (ft_lstlen(bhed) == 0)
		return (makepivot(head, 'a', 'b'));
	else
		return (makepivot(head, 'a', 'a'));
}

void	sortother(t_head *head, t_head *bhed)
{
	int		len;
	int		i;
	int		j;
	int		x;
	int		y;

	x = makex(head, bhed);
	len = checksort(head, 'a') + 1;
	i = 0;
	j = ft_lstlen(head) - checksort(head, 'a') - 1;
	y = checkrotate(head, 'a', x) - ((ft_lstlen(head) - 1) / 2);
	while (len > 0)
	{
		if (head->fir->data < x)
			push(&head, &bhed, 'b');
		else
		{
			if (forbreak(head, 'a', x, y, len) == 0)
				break ;
			i++;
		}
		len--;
	}
	rerotate(head, 'a', i, j, y);
	re_sort(head, bhed, 'a');
}
