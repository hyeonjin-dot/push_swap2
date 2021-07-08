/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sortother.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:37:21 by hyejung           #+#    #+#             */
/*   Updated: 2021/07/08 16:50:45 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		checksort(t_head *head, char c)
{
	int		*lst;
	int		*sort;
	int		len;
	int		i;

	if (ft_lstlen(head) == 0)
		return (0);
	i = 1;
	lst = mklst(head);
	sort = mklst(head);
	len = ft_lstlen(head);
	quicksort(sort, 0, len - 1);
	if (c == 'a')
	{
		while (i <= len)
		{
			if (sort[len - i] == lst[len - i])
				i++;
			else
				break ;
		}
	}
	else
	{
		while (i <= len)
		{
			if (lst[len - i] == sort[i - 1])
				i++;
			else
				break ;
		}
	}
	return (len - i);
}

int		revchecksort(t_head *head, char c)
{
	int		i;
	int		len;
	int		*lst;
	int		*tmp;

	lst = mklst(head);
	tmp = mklst(head);
	len = ft_lstlen(head);
	quicksort(lst, 0, len - 1);
	i = 0;
	while (i < len)
	{
		if (c == 'a')
		{
			if (lst[i] == tmp[i])
				i++;
			else
				break;
		}
		else
		{
			if (lst[i] == tmp[len - i - 1])
				i++;
			else
				break;
		}
	}
	return (len - i);
}

int		makepivot(t_head *head, char c, char idx)
{
	int		*lst;
	int		x;
	int		len;

	len = checksort(head, c);
	lst = mklst(head);
	quicksort(lst, 0, len);
	if (idx == 'a')
		len = (len / 2);
//	else
//		len = 2 * (len / 3);
	x = lst[len];
	return (x);
}

void	lastsort(t_head *head, t_head *bhed)
{
	t_li	*li;
	int		len;

//	printf("lastsort\n");//
//	printf("%d\n", checksort(head, 'a') + 1); //
//	printf("%d\n", sortleft(bhed));//
	if (sortright(head) == 0)
	{
		if (sortleft(bhed) == 0 || ft_lstlen(bhed) == 0)
		{
			li = bhed->fir;
			len = ft_lstlen(bhed);
			while (len > 0)
			{
				push(&bhed, &head, 'a');
				li = bhed->fir;
				len--;
			}
			if (sortright(head) == 0 && ft_lstlen(bhed) == 0)
				exit (0);
			else
				re_sort(head, bhed, 'a');
		}
		else if (sortleft(bhed) != 0)
			re_sortb(bhed, head, 'b');
		else
			re_sort(head, bhed, 'a');
	}
	else
		re_sort(head, bhed, 'a');
}

void    re_sortb(t_head *bhed, t_head *head, char c)
{
	int		len;

//	printf("re_sortb\n"); //	
//	printf("%d\n", checksort(bhed, 'b') + 1);//
//	printf("%d\n", sortleft(bhed));//
	if (sortleft(bhed) == 0)
		return (lastsort(head, bhed));
	len = checksort(bhed, 'b') + 1;
	if (len <= 1)
		return (lastsort(head, bhed));
	else if (len == 2)
	{
		if (sortleft(bhed) == 0)
			return (lastsort(head, bhed));
		else
		{
			swap(bhed, c);
			return (lastsort(head, bhed));
		}
	}
	else if (len == 3)
		sorthirdb(bhed, head, c);
	else if (len == 5) // 
		sortfiveb(bhed, head);
	else
		sortotherb(bhed, head);
}

void	re_sort(t_head *head, t_head *bhed, char c)
{
	int		len;

//	printf("re_sort\n"); //
//	printf("%d\n", checksort(head, 'a') + 1); //
	if (c == 'b')
		return (re_sortb(head, bhed, c));
	if (sortright(head) == 0)
		return (lastsort(head, bhed));
	len = checksort(head, 'a') + 1;
    if (len <= 1)
		return (lastsort(head, bhed));
    else if (len == 2)
    {
        if (sortright(head) != 0)
			swap(head, c);
		return (lastsort(head, bhed));
    }
	else if (len == 3)
		sorthird(head, bhed, c);
	else if (len == 5)
		sortfive(head, bhed);
	else
		sortother(head, bhed);
}

int		breakrotate(t_head *head, char c, int x)
{
	int		*lst;
	int		i;
	int		num;

	lst = mklst(head);
	i = 0;
	num = 0;
	while (lst[i])
	{
		if (c == 'b')
		{
			if (lst[i] < x)
				num++;
			else
				break ;
		}
		else
		{
			if (lst[i] >= x)
				num++;
			else
				break ;
		}
		i++;
	}
	return (num);
}

void	sortotherb(t_head *bhed, t_head *head) // 정렬 필요 아래처럼 하면 될 듯
{
    int		len;

//	printf("sortotherb\n"); //
	if (head->num != 0)
		len = head->num;
	else
		len = ft_lstlen(head);
	head->num = 0;
//	printf("%d\n", lenb); //
	while (len-- > 0)
	{
		if (len > 1 && ft_lstlen(bhed) > 1 && bhed->fir->data < bhed->fir->next->data)
			swap(bhed, 'b');
		push(&bhed, &head, 'a');
		if (checksort(head, 'a') == 4)
			sortfive(head, bhed);
		if (checksort(head, 'a') == 2)
			sorthird(head, bhed, 'a');
		if (checksort(head, 'a') == 1)
			swap(head, 'a');
	}
	return (re_sort(head, bhed, 'a'));
}

void	sortother(t_head *head, t_head *bhed)
{
	int		len;
	int		i;
	int		j;
	int		x;

//	printf("sortother\n"); //
//	printf("%d\n", ft_lstlen(head));//
//	printf("sorted : %d\n", ft_lstlen(head) - checksort(head, 'a') - 1); //
	head->num = 0;
	x = makepivot(head, 'a', 'a'); // 원래 aa
	len = checksort(head, 'a') + 1;
	i = 0;
	j = ft_lstlen(head) - checksort(head, 'a') - 1;
	while (len > 0)
	{
		if (head->fir->data <= x)
		{
			push(&head, &bhed, 'b');
			head->num++;
		}
		else
		{
			if (breakrotate(head, 'a', x) >= len)
				break ;
			rotate(&head, 'a');
			i++;
		}
		len--;
	}
	while (j != 0 && i-- > 0)
	{
		if (sortright(head) == 0)
			break ;
		revrotate(&head, 'a');
	}
	if (checksort(head, 'a') + 1 <= 5)
		re_sort(head, bhed, 'a');
	else
		sortother(head, bhed);
}
