/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sortother.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:37:21 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/28 22:01:30 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		checksort(t_head *head, char c)
{
	int		*lst;
	int		*sort;
	int		len;
	int		i;

//	printf("checksort\n"); //
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

//	printf("makepivot\n"); //
	len = checksort(head, c);
	lst = mklst(head);
	quicksort(lst, 0, len);
	if (idx == 'b') // ㅁ원래 a₩
		len = (len / 3);
	else//
		len = 2 *  (len / 3);//
	x = lst[len];
	return (x);
}

void	lastsort(t_head *head, t_head *bhed)
{
	t_li	*li;
	int		len;

//	printf("lastsort\n");//
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
			{
			/*	li = head->fir; //
				while (li != NULL)
				{
					printf("%d\n", li->data);
					li = li->next;
				} */
				exit (0);
			}
			else
				re_sort(head, bhed, 'a');
		}
		else
			re_sortb(bhed, head, 'b');
	}
	else
		re_sort(head, bhed, 'a');
}

void    re_sortb(t_head *bhed, t_head *head, char c)
{
	int		len;
	t_li	*li;//

//	printf("re_sortb\n"); //
	if (sortleft(bhed) == 0)
		return (lastsort(head, bhed));
	len = checksort(bhed, 'b') + 1;
	li = bhed->fir; //
	if (len == 5)//
	{
		while (len > 0)
		{
		//	printf("%d\n", li->data);
			li = li->next;
			len--;
		}
		len = 5;//
	}//
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
			if (lst[i] <= x)
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

void	sortotherb(t_head *bhed, t_head *head)
{
    int		len;
    int		x;
	int		y;
	int		z;
	int		i;
	int		j;

//	printf("sortotherb\n"); //
	x = makepivot(bhed, 'b', 'b'); // 원래는 b b 
	len = checksort(bhed, 'b') + 1;
	i = 0;
	j = ft_lstlen(bhed) - checksort(bhed, 'b');
	while (len > 0)
	{
		if (bhed->fir->data > x)
		{
			push(&bhed, &head, 'a');
			if (checksort(head, 'a')  == 5)
				sortfive(head, bhed);
			if (checksort(head, 'a') == 2)
				sorthird(head, bhed, 'a');
			/*if (revchecksort(head, 'a') == 5)
			{
				y = ft_lstlen(head);
				z = y;
				while (y-- > 5)
					push(&head, &bhed, 'b');
				sortfive(head, bhed); //
			//	while (y++ <= z)
			//		push(&bhed, &head, 'a');
			}*/
			if (revchecksort(head, 'a') == 3)
			{
				y = ft_lstlen(head);
				z = y;
				while (y-- > 3)
					push(&head, &bhed, 'b');
				sorthird(head, bhed, 'a'); //
			//	while (y++ <= z)
			//		push(&bhed, &head, 'a');
			}
		}
		else
		{
			if (breakrotate(bhed, 'b', x) >= len)
				break;
			rotate(&bhed, 'b');
			i++;
		}
		len--;
	}
	while (j != 1 && i-- > 0)
	{
		if (sortleft(bhed) == 0)
			break ;
		revrotate(&bhed, 'b');
	}
//	if (bhed->fir->data < bhed->fir->next->data)
//		swap(bhed, 'b');//
	if (sortleft(bhed) == 0)
	{
		if (sortright(head) == 0)
			lastsort(head, bhed);
		else
			re_sort(head, bhed, 'a');
	}
	else
		re_sortb(bhed, head, 'b');
}

void	sortother(t_head *head, t_head *bhed)
{
	int		len;
	int		i;
	int		j;
	int		x;
	int		y;
	int		z;

//	printf("sortother\n"); //
//	printf("checksort : %d\n", ft_lstlen(head) - checksort(head, 'a') + 1); //
	x = makepivot(head, 'a', 'b');
	len = checksort(head, 'a') + 1;	// 원래는 ft_lstlen
	i = 0;
	j = ft_lstlen(head) - checksort(head, 'a') - 1;
	while (len > 0)
	{
		/*if (j == 0 && y > (head->fir->data))
		{
			push(&head, &bhed, 'b');
			rotate(&bhed, 'b');
			if (checksort(bhed, 'b') + 1 == 5)
				sortfiveb(bhed, head);
			if (checksort(bhed, 'b') == 2)
				sorthirdb(bhed, head, 'b');
		}*/
		if (head->fir->data < x)
		{
			push(&head, &bhed, 'b');
			if (checksort(bhed, 'b') == 4)
				sortfiveb(bhed, head);
			if (checksort(bhed, 'b') == 2)
				sorthirdb(bhed, head, 'b');
			/*if (revchecksort(bhed, 'b') == 5)
			{
				y = ft_lstlen(bhed);
				z = y;
				while (y-- > 5)
					push(&bhed, &head, 'a');
				sortfiveb(bhed, head); //
			//	while (y++ <= z)
				//	push(&head, &bhed, 'b');
			}*/
			if (revchecksort(bhed, 'b') == 3)
			{
				y = ft_lstlen(bhed);
				z = y;
				while (y-- > 3)
					push(&bhed, &head, 'a');
				sorthirdb(bhed, head, 'b'); //
			//	while (y++ <= z)
			//		push(&head, &bhed, 'b');
			}
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
//	if (head->fir->data > head->fir->next->data)
//		swap(head, 'a');//
	lastsort(head, bhed);
}
