/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:05:35 by hyejung           #+#    #+#             */
/*   Updated: 2021/07/19 12:01:56 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_lstlen(t_head *head)
{
	t_li	*li;
	int		i;

	i = 1;
	li = head->fir;
	if (li == NULL)
		return (0);
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

	if (ft_lstlen(head) <= 1)
		return (0);
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

int		sortleft(t_head *head)
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

void	sort(t_head *head, t_head *bhed)
{
	int		len;
	int		lenb;

	len = ft_lstlen(head);
	lenb = ft_lstlen(bhed);
	if (sortright(head) == 0 && lenb == 0)
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
		sorthird(head, bhed, 'a');
	else if (len == 5)
		sortfive(head, bhed);
	else
		sortother(head, bhed);
}
