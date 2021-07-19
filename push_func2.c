/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:44:17 by hyejung           #+#    #+#             */
/*   Updated: 2021/07/19 12:20:45 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		checksort(t_head *head, char c)
{
	int		*lst;
	int		*sort;
	int		len;
	int		i;

	if (ft_lstlen(head) == 0)
		return (0);
	i = 1;
	lst = mklst(head);
	sort = mklst(head);
	len = ft_lstlen(head);
	quicksort(sort, 0, len - 1);
	while (i <= len)
	{
		if (c == 'a' && sort[len - i] == lst[len - i])
			i++;
		else if (c == 'b' && lst[len - i] == sort[i - 1])
			i++;
		else
			break ;
	}
	return (len - i);
}

int		makepivot(t_head *head, char c, char idx)
{
	int		*lst;
	int		x;
	int		len;

	len = checksort(head, c);
	lst = mklst(head);
	quicksort(lst, 0, len);
	if (idx == 'a')
		len = (len / 3);
	else
		len = 2 * (len / 3);
	x = lst[len];
	return (x);
}

void	lastsort(t_head *head, t_head *bhed)
{
	int		len;

	if (sortright(head) == 0)
	{
		if (ft_lstlen(bhed) == 0 || sortleft(bhed) == 0)
		{
			len = ft_lstlen(bhed);
			while (len-- > 0)
				push(&bhed, &head, 'a');
			if (sortright(head) == 0 && ft_lstlen(bhed) == 0)
				return ;
			else
				re_sort(head, bhed, 'a');
		}
		else
			re_sortb(bhed, head, 'b');
	}
	else
		re_sort(head, bhed, 'a');
}

void	re_sortb(t_head *bhed, t_head *head, char c)
{
	int		len;

	len = checksort(bhed, 'b') + 1;
	if (len < 2)
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
}

void	re_sort(t_head *head, t_head *bhed, char c)
{
	int		len;

	if (c == 'b')
		return (re_sortb(head, bhed, c));
	if (sortright(head) == 0)
		return (lastsort(head, bhed));
	len = checksort(head, 'a') + 1;
	if (len <= 1)
		return (lastsort(head, bhed));
	else if (len == 2)
	{
		if (sortright(head) != 0)
			swap(head, c);
		return (lastsort(head, bhed));
	}
	else if (len == 3)
		sorthird(head, bhed, c);
	else if (len == 5)
		sortfive(head, bhed);
	else
		sortother(head, bhed);
}
