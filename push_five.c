/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:53:15 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/22 17:36:58 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int findnum(t_head *head)
{
	int	*lst;
	int	num;
	int	len;

	lst = mklst(head);
	len = ft_lstlen(head);
	quicksort(lst, 0, len - 1);
	num = lst[1];
	return (num);
}

void	sortfive(t_head *head, t_head *bhed) // b에 아무것도 없고 a 길이가 5인 경우 
{
	t_li	*li;
	int		*lst;
	int		*count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	li = head->fir;
	count = (int *)malloc(sizeof(int) * 3);
	lst = mklst(head);
	while (lst[i])
	{
		if (lst[i] <= findnum(head))
			count[j++] = i;
		i++;
	}
	count[j] = '\0';
	i = 0;
	j = 0;
	while (j < 2)
	{
		while (i < count[j] && i < 5)
		{
			rotate(&head, 'a');
			li = head->fir;
			i++;
		}
		push(&head, &bhed, 'b');
		j++;
		i++;
	}
	if (sortright(head) != 0)
		sorthird(head, bhed, 'a');
	if (bhed->fir->data < bhed->fir->next->data)
		swap(bhed, 'b');
	push(&bhed, &head, 'a');
	push(&bhed, &head, 'a');
	free(count);
	return ;
}
