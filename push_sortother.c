/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sortother.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:37:21 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/24 17:01:28 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		checksort(t_head *head, char c)
{
	int		*lst;
	int		*sort;
	int		len;
	int		i;

	i = 1;
	lst = mklst(head);
	sort = mklst(head);
	len = ft_lstlen(head);
	quicksort(sort, 0, len - 1);
	if (c == 'a')
	{
		while (i <= len)
		{
			if (sort[len - i] == lst[len - i])
				i++;
			else
				break ;
		}
	}
	else
	{
		while (i <= len)
		{
			if (sort[len - i] == lst[i - 1])
				i++;
			else
				break ;
		}
	}
	return (len - i);
}

int		makepivot(t_head *head, char c)
{
	int		*lst;
	int		x;
	int		len;

	len = checksort(head, c);
	lst = mklst(head);
	quicksort(lst, 0, len);
	if (c == 'a')
		len = (len / 3) * 2;
	else
		len = (len / 3);
	x = lst[len];
	return (x);
}

void	lastsort(t_head *head, t_head *bhed)
{
	int		len;

	printf("lastsort\n");//
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
			return ;
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

	printf("re_sortb\n"); //
	if (sortleft(bhed) == 0)
		return (lastsort(head, bhed));
	len = checksort(bhed, 'b') + 1;
	printf("<%d>\n", len);
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
	else if (len == 5)
		sortfiveb(bhed, head);
	else
		sortotherb(bhed, head);
	return ;
}

void	re_sort(t_head *head, t_head *bhed, char c)
{
	int		len;

	printf("re_sort\n"); //
	if (c == 'b')
		return (re_sortb(head, bhed, c));
	if (sortright(head) == 0)
		return (lastsort(head, bhed));
	len = checksort(head, 'a') + 1;
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
	else if (len == 5 && ft_lstlen(bhed) == 0)
		sortfive(head, bhed);
	else
		sortother(head, bhed);
	return ;
}

void	sortotherb(t_head *bhed, t_head *head)
{
	t_li	*li;
    int		len;
    int		x;
	int		y;
	int		i;
	int		j;

	printf("sortotherb\n"); //
	li = bhed->fir;
	x = makepivot(bhed, 'b');
	y = makepivot(bhed, 'a');//
	len = checksort(bhed, 'b');
	i = 0;
	j = ft_lstlen(bhed) - checksort(bhed, 'b') - 1;
	while (len > 0)
	{
		if (bhed->fir->data > x)
		{
			push(&bhed, &head, 'a');
//			printf("here\n");
			if (head->fir->data >= y)
				rotate(&head, 'a');
		}
		else
		{
			rotate(&bhed, 'b');
			i++;
		}
		li = bhed->fir;
		len--;
	}
	while (j != 0 && i-- > 0)
	{
		if (sortleft(bhed) == 0)
			break ;
		revrotate(&bhed, 'b');
	}
	if (sortleft(bhed) == 0)
	{
		if (sortright(head) == 0)
			lastsort(head, bhed);
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
	int		i;
	int		j;
	int		x;
	int		y;

	printf("sortother\n"); //
	li = head->fir;
	x = makepivot(head, 'a');
	y = makepivot(head, 'b'); //
	len = checksort(head, 'a');	// 원래는 ft_lstlen
	i = 0;
	j = ft_lstlen(head) - checksort(head, 'a') - 1;
	while (len > 0)
	{
		if (head->fir->data <= x)
		{
			push(&head, &bhed, 'b');
			if (bhed->fir->data <= y)
				rotate(&bhed, 'b');
		}
		else
		{
			rotate(&head, 'a');
			i++;
		}
		li = head->fir;
		len--;
	}
	while (j != 0 && i-- > 0)
	{
		if (sortright(head) == 0)
			break ;
		revrotate(&head, 'a');
	}
	if (sortright(head) == 0)
	{
		if (sortleft(bhed) == 0)
			lastsort(head, bhed);
		else
			re_sortb(bhed, head, 'b');
	}
	else
		re_sort(head, bhed, 'a');
}
