/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_third.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:48:32 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/23 21:08:50 by hyejung          ###   ########.fr       */
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
		return (0); //1 2 3
	else if (a < b && a < c && c < b)
		return (1); // 1 3 2
	else if (a < c && b < c && b < a)
		return (2); // 2 1 3
	else if (a < b && a > c && c < b)
		return (3); // 2 3 1
	else if (a > b && a > c && b > c)
		return (4); // 3 2 1
	else // 3 1 2
		return (5);
}

void	resorthirdb(t_head *head, t_head *bhed, char c)
{
    if (checkcontent(bhed) == 0)
    {
        swap(bhed, c);
		return (resorthirdb(head, bhed, c));
    }
    else if (checkcontent(head) == 1)
	{
        swap(bhed, c);
		push(&bhed, &head, 'a');
		swap(bhed, c);
		push(&head, &bhed, c);
	}
    else if (checkcontent(head) == 2)
    {
        push(&bhed, &head, c);
        swap(bhed, c);
        push(&head, &bhed, 'b');
        swap(bhed, c);
    }
    else if (checkcontent(head) == 3)
        swap(bhed, c);
    else
    {
		push(&bhed, &head, 'a');
		swap(bhed, c);
		push(&head, &bhed, c);
    }
    if (sortleft(bhed) == 0)
        return (re_sort(head, bhed, 'a'));
    return (re_sortb(bhed, head, c));
}

void	sorthirdb(t_head *bhed, t_head *head, char c) // 무엇이 문제? 
{
//	printf("sorthirdb\n");//
	if (ft_lstlen(bhed) != checksort(bhed, 'b') + 1)
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
	if (sortleft(bhed) == 0)
		return (re_sort(head, bhed, 'a'));
	return (sorthirdb(bhed, head, c));
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
	else if (checkcontent(head) == 4)
	{
		swap(head, c);
		return (resorthird(head, bhed, c));
	}
	else
	{
		swap(head, c);
		rotate(&head, c);
		swap(head, c);
		revrotate(&head, c);
	}
	if (sortright(head) == 0)
		return (re_sortb(bhed, head, 'b'));
	return (re_sort(head, bhed, c));
}

void	sorthird(t_head *head, t_head *bhed, char c)
{
	t_li	*li;

//	printf("sorthird\n");
	if (ft_lstlen(head) != checksort(head, 'a') + 1)
		return (resorthird(head, bhed, c));
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
	return (re_sort(head, bhed, c));
}
