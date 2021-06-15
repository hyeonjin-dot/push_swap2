/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:24:57 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/15 14:33:48 by hyejung          ###   ########.fr       */
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

	zero = (t_li*)malloc(sizeof(t_li));
	one = (t_li*)malloc(sizeof(t_li));
	zero = head->fir;
	one = zero->next;
	ft_swap(&(zero->data), &(one->data));
	if (c == 'a')
		write(1, "sa\n", 4);
	else
		write(1, "sb\n", 4);
}

void	revrotate(t_head *head, char c)
{
	t_li	*tmp;
	t_li	*lst;
	int		i;

	i = 0;
	tmp = (t_li*)malloc(sizeof(t_li));
	lst = (t_li*)malloc(sizeof(t_li));
	tmp = head->fir;
	lst = tmp->next;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	head->fir = lst;
	lst->next = tmp;
	while (i > 0)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 5);
	else
		write(1, "rrb\n", 5);
}

void	rotate(t_head *head, char c)
{
	t_li	*tmp;
	t_li	*lst;
	int		i;

	i = 0;
	tmp = (t_li*)malloc(sizeof(t_li));
	lst = (t_li*)malloc(sizeof(t_li));
	tmp = head->fir;
	lst = tmp->next;
	head->fir = lst;
	tmp->next = NULL;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	lst->next = tmp;
	if (c == 'a')
    write(1, "ra\n", 4);
	else
		write(1, "rb\n", 4);
}

void	push(t_head *head, t_head *bhed, char c)
{
	t_li	*frm;
	t_li	*to;

	frm = (t_li*)malloc(sizeof(t_li));
	to = (t_li*)malloc(sizeof(t_li));
	frm = head->fir;
	if (bhed->fir == NULL)
	{
		bhed->fir = frm;
		head->fir = head->fir->next;
		frm->next = NULL;
	}
	else
	{
		to = bhed->fir;
		head->fir = frm->next;
		bhed->fir = frm;
		frm->next = to;
	}
	if (c == 'a')
    write(1, "pb\n", 4);
	else
		write(1, "pa\n", 4);
}
