/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sortother.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:37:21 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/15 16:57:06 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sortother(t_head *head, t_head *bhed) // 적은 수에서 정렬됨 -> a의 수가 큰 경우 확인 필요
{
	t_li	*li;
	int		len;
	int		*lst;
	int		x;

	li = head->fir;
	len = ft_lstlen(head);
	//if (len == 5)
		//sort_five(head);
	lst = mklst(head);
	quicksort(lst, 0, len - 1);
	len = len / 3;
	x = lst[len];
	len = ft_lstlen(head);
	while (len > 0)
	{
		if (li->data <= x)
			push(head, bhed, 'a');
		else
			rotate(head, 'a');
		li = head->fir;
		len--;
	}
	revrotate(bhed , 'b');
	if (sortright(head) == 0 && sortleft(bhed) == 0)
	{
		li = bhed->fir;
		len = ft_lstlen(bhed);
		while (len > 0)
		{
			push(bhed, head, 'b');
			li = bhed->fir;
			len--;
		}
		return ;
	}
	//else
		//sort(head, NULL);
	//sort(head, bhed); // 마지막 처리를 다르게 해야할 듯.
	li_print(head);
	printf("---\n");
	li_print(bhed);
}
