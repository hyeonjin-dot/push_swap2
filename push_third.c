/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_third.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:48:32 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/15 15:20:09 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	sorthird(t_head *head, char c)
{
	t_li	*li;

	li = head->fir;
	if (sortright(head) == 0)
		return (0);
	else if (li->data > li->next->data)
	{
		if (li->data > li->next->next->data && li->next->data < li->next->next->data)
				rotate(head, c);
		else
			swap(head, c);
	}	
	else
		revrotate(head, c);
	return (sorthird(head, c));
}
