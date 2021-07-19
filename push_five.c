/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:53:15 by hyejung           #+#    #+#             */
/*   Updated: 2021/07/19 12:19:38 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int 	findnum(t_head *head, char c)
{
	int		*lst;
	int		num;
	int		len;

	lst = mklst(head);
	len = checksort(head, c);
	quicksort(lst, 0, 4);
	if (c == 'a')
		num = lst[1];
	else
		num = lst[3];
	return (num);
}

int		*makestrd(t_head *head, char c)
{
	int		*count;
	int		*lst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = (int *)malloc(sizeof(int) * 3);
	lst = mklst(head);
	while (i++ < 5)
	{
		if (c == 'a')
		{
			if (lst[i] <= findnum(head, c))
				count[j++] = i;
		}
		else
		{
			if (lst[i] >= findnum(head, c))
				count[j++] = i;
		}
	}
	count[j] = '\0';
	return (count);
}

int		makethree(t_head *head, t_head *bhed, char c, int *count)
{
	int		i;
	int		j;
	int		k;
	char	t;

	i = 0;
	j = 0;
	k = 0;
	if (c == 'a')
		t = 'b';
	else
		t = 'a';
	while (j < 2)
	{
		while (i < count[j] && i < 5)
		{
			rotate(&head, c);
			i++;
			k++;
		}
		push(&head, &bhed, t);
		j++;
		i++;
	}
	return (k);
}

void	sortfiveb(t_head *bhed, t_head *head)
{
	int		*count;
	int		k;

	count = makestrd(bhed, 'b');
	k = makethree(bhed, head, 'b', count);
	free(count);
	while (ft_lstlen(bhed) != 3 && k-- > 0)
		revrotate(&bhed, 'b');
	if (head->fir->data > head->fir->next->data)
		swap(head, 'a');
    if (sortleft(bhed) != 0)
        sorthirdb(bhed, head, 'b');
	push(&head, &bhed, 'b');
	push(&head, &bhed, 'b');
	return (re_sort(head, bhed, 'a'));
}

void	sortfive(t_head *head, t_head *bhed)
{
	int		*count;
	int		k;

	count = makestrd(head, 'a');
	k = makethree(head, bhed, 'a', count);
	free(count);
	while (ft_lstlen(head) != 3 && k-- > 0)
		revrotate(&head, 'a');
	if (bhed->fir->data < bhed->fir->next->data)
		swap(bhed, 'b');
	if (sortright(head) != 0)
		sorthird(head, bhed, 'a');
	push(&bhed, &head, 'a');
	push(&bhed, &head, 'a');
	return (lastsort(head, bhed));
}
