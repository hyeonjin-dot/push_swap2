/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sortother.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:37:21 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/22 18:52:36 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		makepivot(t_head *head, char c)
{
	int		*lst;
	int		x;
	int		len;

	len = ft_lstlen(head);
	lst = mklst(head);
	quicksort(lst, 0, len - 1);
	if (c == 'a')
		len = len / 3;
	else
		len = (len / 3) * 2;
	x = lst[len];
	return (x);
}

void	lastsort(t_head *head, t_head *bhed)
{
	int		len;

	if (sortright(head) == 0)
	{
		if (sortleft(bhed) == 0)
		{
			len = ft_lstlen(bhed);
			while (len > 0)
			{
				push(&bhed, &head, 'a');
				len--;
			}
		}
		else
			re_sortb(bhed, head, 'b');
	}
	else
		re_sort(head, bhed, 'a');
}

void    re_sortb(t_head *bhed, t_head *head, char c)
{
	int		len;

	len = ft_lstlen(bhed);
	if (sortleft(bhed) == 0)
		return (lastsort(head, bhed));
	if (len == 1)
		return (lastsort(head, bhed));
	else if (len == 2)
	{
		if (sortleft(bhed) == 0)
			return (lastsort(head, bhed));
		else
		{
			swap(bhed, c);
			return (lastsort(head, bhed));
		}
	}
	else if (len == 3)
		sorthirdb(bhed, head, c);
	else
		sortotherb(bhed, head);
	return ;
}

void	re_sort(t_head *head, t_head *bhed, char c)
{
	int		len;

	if (c == 'b')
		return (re_sortb(head, bhed, c));
	if (sortright(head) == 0)
		return (lastsort(head, bhed));
	len = ft_lstlen(head);
    if (len  == 1)
		return (lastsort(head, bhed));
    else if (len == 2)
    {
        if (sortright(head) == 0)
            return (lastsort(head, bhed));
        else
        {
            swap(head, c);
			return (lastsort(head, bhed));
        }
    }
    else if (len == 3)
        sorthird(head, bhed, c);
	else
		sortother(head, bhed);
	return ;
}

void	sortotherb(t_head *bhed, t_head *head)
{
	t_li	*li;
    int		len;
    int		x;

	li = bhed->fir;
	x = makepivot(bhed, 'b');
	len = ft_lstlen(bhed);
	while (len > 0)
	{
		if (li->data > x)
			push(&bhed, &head, 'a');
		else
			rotate(&bhed, 'b');
		li = bhed->fir;
		len--;
	}
	if (sortleft(bhed) == 0)
	{
		if (sortright(head) == 0)
		{
			li = bhed->fir;
			while (len > 0)
			{
				push(&bhed, &head, 'a');
				li = bhed->fir;
				len--;
			}
			return ;
		}
		else
			re_sort(head, bhed, 'a');
	}
	else
		re_sortb(bhed, head, 'b');
}

void	sortother(t_head *head, t_head *bhed)
{
	t_li	*li;
	int		len;
	int		x;

	li = head->fir;
	x = makepivot(head, 'a');
	len = ft_lstlen(head);
	while (len > 0)
	{
		if (li->data <= x)
			push(&head, &bhed, 'b');
		else
			rotate(&head, 'a');
		li = head->fir;
		len--;
	}
	if (sortright(head) == 0)
	{
		if (sortleft(bhed) == 0)
		{
			li = bhed->fir;
			len = ft_lstlen(bhed);
			while (len > 0)
			{
				push(&bhed, &head, 'a');
				li = bhed->fir;
				len--;
			}
			exit (0);
		}
		else
			re_sortb(bhed, head, 'b');
	}
	else
		re_sort(head, bhed, 'a');
}
