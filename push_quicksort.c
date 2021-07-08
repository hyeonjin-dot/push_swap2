/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:09:01 by hyejung           #+#    #+#             */
/*   Updated: 2021/07/08 15:42:04 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*mklst(t_head *head)
{
	t_li	*li;
	int		*lst;
	int		i;
	int		j;

	i = ft_lstlen(head);
	j = 0;
	li = head->fir;
	lst = (int *)malloc(sizeof(int) * (i + 1));
	while (j < i)
	{
		lst[j] = li->data;
		li = li->next;
		j++;
	}
	lst[j] = '\0';
	return (lst);
}

void	quicksort(int *arr, int left, int right)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	i = left;
	j = right;
	pivot = arr[(left + right) / 2];
	while (i<= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i<= j)
		{
			temp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = temp;
		}
	}
	if (left < j)
		quicksort(arr, left, j);
	if (i < right)
        quicksort(arr, i, right);
}
