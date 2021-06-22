/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:24:45 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/22 14:49:14 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	li_init(t_head *head)
{
	head->fir = NULL;
}

void	li_insert(t_head *head, int data)
{
	t_li	*new;
	t_li	*last;

	new = (t_li*)malloc(sizeof(t_li*));
	new->data = data;
	new->next = NULL;
	if (head->fir == NULL)
	{
		head->fir = new;
		return ;
	}
	last = head->fir;
	while (last->next != NULL)
		last= last->next;
	last->next = new;
}
