/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:24:57 by hyejung           #+#    #+#             */
/*   Updated: 2021/07/16 22:10:09 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap(t_head *head, char c)
{
	t_li	*zero;
	t_li	*one;

	zero = head->fir;
	one = zero->next;
	ft_swap(&(zero->data), &(one->data));
	if (c == 'a')
		write(1, "sa", 2);
	else
		write(1, "sb", 2);
	write(1, "\n", 1);
}

void	revrotate(t_head **head, char c) 
{
	t_li	*tmp;
	t_li	*lst;
	int		i;

	if (ft_lstlen(*head) <= 1)
		return ;
	i = 0;
	tmp = (*head)->fir;
	lst = (*head)->fir->next;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	(*head)->fir = lst;
	lst->next = tmp;
	while (i-- > 0)
		tmp = tmp->next;
	tmp->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	rotate(t_head **head, char c)
{
	t_li	*tmp;
	t_li	*lst;
	int		i;

	if (ft_lstlen(*head) <= 1)
		return ;
	i = 0;
	tmp = (*head)->fir;
	lst = tmp->next;
	(*head)->fir = lst;
	tmp->next = NULL;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	lst->next = tmp;
	if (c == 'a')
		write(1, "ra", 2);
	else
		write(1, "rb", 2);
	write(1, "\n", 1);
	return ;
}

void	push(t_head **head, t_head **bhed, char c)
{
	t_li	*frm;
	t_li	*to;
	int		i;

	i = ft_lstlen(*head);
	if (i < 1)
		return ;
	frm = (*head)->fir;
	if ((*bhed)->fir == NULL)
	{
		(*bhed)->fir = frm;
		(*head)->fir = (*head)->fir->next;
		frm->next = NULL;
	}
	else
	{
		to = (*bhed)->fir;
		(*head)->fir = frm->next;
		(*bhed)->fir = frm;
		frm->next = to;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
