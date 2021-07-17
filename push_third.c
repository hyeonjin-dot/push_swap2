/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_third.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:48:32 by hyejung           #+#    #+#             */
/*   Updated: 2021/07/16 22:39:24 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		checkcontent(t_head *head)
{
	t_li	*li;
	int		a;
	int		b;
	int		c;

	li = head->fir;
	a = li->data;
	b = li->next->data;
	c = li->next->next->data;
	if (a < b && b < c && a < c)
		return (0);
	else if (a < b && a < c && c < b)
		return (1);
	else if (a < c && b < c && b < a)
		return (2);
	else if (a < b && a > c && c < b)
		return (3);
	else if (a > b && a > c && b > c)
		return (4);
	else
		return (5);
}

void	resorthirdb(t_head *bhed, t_head *head, char c)
{
	if (checkcontent(bhed) <= 1)
    {
        swap(bhed, c);
		return (resorthirdb(bhed, head, c));
    }
    else if (checkcontent(bhed) == 2)
    {
        push(&bhed, &head, 'a');
        swap(bhed, c);
        push(&head, &bhed, c);
        swap(bhed, c);
    }
    else if (checkcontent(bhed) == 3)
        swap(bhed, c);
    else
    {
		push(&bhed, &head, 'a');
		swap(bhed, c);
		push(&head, &bhed, c);
    }
    return (re_sort(head, bhed, 'a'));
}

void	sorthirdb(t_head *bhed, t_head *head, char c)
{
	if (ft_lstlen(bhed) != 3)
		return (resorthirdb(bhed, head, c));
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
	return (re_sort(head, bhed, 'a'));
}

void	resorthird(t_head *head, t_head *bhed, char c)
{
	if (checkcontent(head) == 1)
	{
		rotate(&head, c);
		swap(head, c);
		revrotate(&head, c);
	}
	else if (checkcontent(head) == 2)
		swap(head, c);
	else if (checkcontent(head) == 3)
	{
		push(&head, &bhed, 'b');
		swap(head, c);
		push(&bhed, &head, c);
		swap(head, c);
	}
	else
	{
		swap(head, c);
		return (resorthird(head, bhed, c));
	}
	return (re_sort(head, bhed, 'a'));
}

void	sorthird(t_head *head, t_head *bhed, char c)
{
	t_li	*li;

	if (ft_lstlen(head) != 3 && checkcontent(head) != 0)
		return (resorthird(head, bhed, c));
	if (sortright(head) == 0)
		return(re_sort(head, bhed, c));
	li = head->fir;
	if (li->data > li->next->data)
	{
		if (checkcontent(head) == 5)
			rotate(&head, c);
		else
			swap(head, c);
	}	
	else
		revrotate(&head, c);
	return (lastsort(head, bhed));
}
