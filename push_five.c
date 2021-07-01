/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:53:15 by hyejung           #+#    #+#             */
/*   Updated: 2021/07/01 21:16:05 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int findnum(t_head *head, char c)
{
	int	*lst;
	int	num;
	int	len;

	lst = mklst(head);
	len = checksort(head, c);
	quicksort(lst, 0, len);
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
	int		k;

//	printf("sortfiveb\n");//
    i = 0;
    j = 0;
    li = bhed->fir;
	count = (int *)malloc(sizeof(int) * 3);
    lst = mklst(bhed);
    while (i < 5)
    {
        if (lst[i] >= findnum(bhed, 'b'))
            count[j++] = i;
        i++;
    }
    count[j] = '\0';
    i = 0;
    j = 0;
	k = 0;
    while (j < 2)
    {
        while (i < count[j] && i < 5)
        {
            rotate(&bhed, 'b');
            li = bhed->fir;
            i++;
			k++;
        }
        push(&bhed, &head, 'a');
		j++;
        i++;
    }
	while (ft_lstlen(bhed) != 3 && k-- > 0)
		revrotate(&bhed, 'b');
	if (head->fir->data > head->fir->next->data)
		swap(head, 'a');
	free(count);//
    if (ft_lstlen(bhed) == 3 && sortleft(bhed) != 0)
        sorthirdb(bhed, head, 'b');
	else if (sortleft(bhed) != 0)
		resorthirdb(bhed, head, 'b');
	push(&head, &bhed, 'b');
	push(&head, &bhed, 'b');
	if (sortleft(bhed) == 0)
		return (re_sort(head, bhed, 'a'));
	else
		return (re_sortb(bhed, head, 'b'));
}

void	sortfive(t_head *head, t_head *bhed) // b에 아무것도 없고 a 길이가 5인 경우 
{
	t_li	*li;
	int		*lst;
	int		*count;
	int		i;
	int		j;
	int		k;

//	printf("sortfive\n");//
	i = 0;
	j = 0;
	li = head->fir;
	count = (int *)malloc(sizeof(int) * 3);
	lst = mklst(head);
	while (i < 5)
	{
		if (lst[i] <= findnum(head, 'a'))
			count[j++] = i;
		i++;
	}
	count[j] = '\0';
	i = 0;
	j = 0;
	k = 0;
	while (j < 2)
	{
		while (i < count[j] && i < 5)
		{
			rotate(&head, 'a');
			li = head->fir;
			i++;
			k++;
		}
		push(&head, &bhed, 'b');
		j++;
		i++;
	}
	while (ft_lstlen(head) != 3 && k-- > 0)
		revrotate(&head, 'a');
	if (bhed->fir->data < bhed->fir->next->data)
		swap(bhed, 'b');
	free(count);
	if (ft_lstlen(head) == 3 && sortright(head) != 0)
		sorthird(head, bhed, 'a');
	else if (sortright(head) != 0)
		resorthird(head, bhed, 'a');
	push(&bhed, &head, 'a');
	push(&bhed, &head, 'a');
	if (sortright(head) == 0 && ft_lstlen(bhed) != 0)
		return (re_sortb(bhed, head, 'b'));
	else
		return (re_sort(head, bhed, 'a'));
}
