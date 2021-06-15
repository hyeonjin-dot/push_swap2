/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:05:35 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/15 15:07:39 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_lstlen(t_head *head)
{
	t_li	*li;
	int		i;
	
	i = 1;
	li = head->fir;
	while (li->next != NULL)
	{
		li = li->next;
		i++;
	}
	return (i);
}

int		sortright(t_head *head)
{
	t_li	*li;
	int		len;

	li = head->fir;
	len = ft_lstlen(head) - 1;
	while (len > 0)
	{
		if (li->data < li->next->data)
			len--;
		else
			return (len);
		li = li->next;
	}
	return (0);
}

int	sortleft(t_head *head)
{
	t_li	*li;
	int		len;

	li = head->fir;
	len = ft_lstlen(head) - 1;
	while (len > 0)
	{
		if (li->data > li->next->data)
			len--;
		else
			return (len);
		li = li->next;
	}
	return (0);
}

void	sortother(t_head *head, t_head *bhed)
{
	t_li	*li;
	int		len;
	int		*lst;
	int		x;

	li = head->fir;
	len = ft_lstlen(head);
	//if (len == 5)
		//sort_five(head);
	lst = mklst(head);
	quicksort(lst, 0, len - 1);
	len = len / 3;
	x = lst[len - 1];
	len = ft_lstlen(head);
	while (len > 0)
	{
		if (li->data <= x)
		{
			push(head, bhed, 'a');
			li = head ->fir;
		}
		else
			rotate(head, 'a');
		len--;
	}
	revrotate(bhed , 'b');
	if (sortright(head) == 0 && sortleft(bhed) == 0)
	{
		li = bhed->fir;
		len = ft_lstlen(bhed);
		while (len > 0)
		{
			push(bhed, head, 'b');
			li = bhed->fir;
			len--;
		}
		return ;
	}
	sort(head, bhed);
}

void	sort(t_head *head, t_head *bhed)
{
	int		len;
	int		lenb;

	len = ft_lstlen(head);
	lenb = ft_lstlen(bhead);
	if (len == 1 && lenb == 0)
		return ;
	else if (len == 2 && lenb == 0)
	{
		if (sortright(head) == 0)
			return ;
		else
		{
			swap(head, 'a');
			return ;
		}
	}
	else if (len == 3 && lenb == 0)
		sorthird(head);
	else
		sortother(head, bhed);
}
