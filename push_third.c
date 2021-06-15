/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_third.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:48:32 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/15 14:35:12 by hyejung          ###   ########.fr       */
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
				rotate(head, 'a');
		else
			swap(head, 'a');
	}	
	else
		revrotate(head, 'a');
	return (sorthird(head));
}
