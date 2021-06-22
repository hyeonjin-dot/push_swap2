/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_third.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:48:32 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/22 18:53:19 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	checkcontent(t_head *bhed)
{
	t_li	*li;
	int		a;
	int		b;
	int		c;

	li = bhed->fir;
	a = li->data;
	b = li->next->data;
	c = li->next->next->data;
	if (a < b && a < c && c < b)
		return (1);
	else if (a < c && b < c && b < a)
		return (2);
	else
		return (3);
}

void	sorthirdb(t_head *bhed, t_head *head, char c) // 무엇이 문제? 
{
	if (sortleft(bhed) == 0)
		return (re_sort(head, bhed, 'a'));
	else
	{
		if (checkcontent(bhed) == 1)
			rotate(&bhed, c);
		else if (checkcontent(bhed) == 2)
			revrotate(&bhed, c);
		else
			swap(bhed, c);
	}
	if (sortleft(bhed) == 0)
		return (re_sort(head, bhed, 'a'));
	return (sorthirdb(bhed, head, c));
}

void	sorthird(t_head *head, t_head *bhed, char c)
{
	t_li	*li;

	li = head->fir;
	if (sortright(head) == 0 && ft_lstlen(bhed) != 0)
		return (re_sortb(bhed, head, 'b'));
	if (li->data > li->next->data)
	{
		if (li->data > li->next->next->data && li->next->data < li->next->next->data)
			rotate(&head, c);
		else
			swap(head, c);
	}	
	else
		revrotate(&head, c);
	if (sortright(head) == 0 && ft_lstlen(bhed) == 0)
		return ;
	return (sorthird(head, bhed, c));
}
