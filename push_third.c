/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_third.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:48:32 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/10 21:25:49 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sorthird(t_head *head) // ?
{
	t_li	*li;

	li = (t_li*)malloc(sizeof(t_li*));
	li = head->fir;
	if (sortright(head) == 0)
	{
		free(li);
		printf("here\n"); //
		exit (1);
	}
	else if (li->data > li->next->data)
	{
		if (li->data > li->next->next->data)
		{
			if (li->next->data < li->next->next->data)
				rotate(head);
			else
				swap(head);
		}
		else
			swap(head);
	}
	else
		revrotate(head);
	free(li);
	sorthird(head);
}
