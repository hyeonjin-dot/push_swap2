/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:53:15 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/24 16:29:58 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int findnum(t_head *head, char c)
{
	int	*lst;
	int	num;
	int	len;

	lst = mklst(head);
	len = ft_lstlen(head);
	quicksort(lst, 0, len - 1);
	if (c == 'a')
		num = lst[1];
	else
		num = lst[3];
	return (num);
}

void	sortfiveb(t_head *bhed, t_head *head)
{
	t_li	*li;
	int		*lst;
	int		*count;
	int		i;
	int		j;

    i = 0;
    j = 0;
    li = bhed->fir;
    count = (int *)malloc(sizeof(int) * 3);
    lst = mklst(bhed);
    while (lst[i])
    {
        if (lst[i] >= findnum(bhed, 'b'))
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
            rotate(&bhed, 'b');
            li = bhed->fir;
            i++;
        }
        push(&bhed, &head, 'a');
        j++;
        i++;
    }
    if (ft_lstlen(head) == 0 && sortleft(bhed) != 0)
        sorthirdb(bhed, head, 'b');
	   if (head->fir->data < head->fir->next->data)
       swap(head, 'a');
   push(&head, &bhed, 'b');
   push(&head, &bhed, 'b');
   free(count);
   return (re_sortb(head, bhed, 'b'));
}

void	sortfive(t_head *head, t_head *bhed) // b에 아무것도 없고 a 길이가 5인 경우 
{
	t_li	*li;
	int		*lst;
	int		*count;
	int		i;
	int		j;

	printf("sortfive\n");//
	i = 0;
	j = 0;
	li = head->fir;
	count = (int *)malloc(sizeof(int) * 3);
	lst = mklst(head);
	while (lst[i])
	{
		if (lst[i] <= findnum(head, 'a'))
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
	if (ft_lstlen(bhed) == 0 && sortright(head) != 0)
		sorthird(head, bhed, 'a');
	else if (sortright(head) != 0)
		resorthird(head, bhed, 'a');
	if (bhed->fir->data < bhed->fir->next->data)
		swap(bhed, 'b');
	push(&bhed, &head, 'a');
	push(&bhed, &head, 'a');
	free(count);
	return (re_sort(head, bhed, 'a'));
}
