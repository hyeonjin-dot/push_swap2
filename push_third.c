/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_third.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:48:32 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/14 21:08:12 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	sorthird(t_head *head)
{
	t_li	*li;

	li = head->fir;
	if (sortright(head) == 0)
		return (0);
	else if (li->data > li->next->data)
	{
		if (li->data > li->next->next->data && li->next->data < li->next->next->data)
				rotate(head);
		else
			swap(head);
	}	
	else
		revrotate(head);
	return (sorthird(head));
}
