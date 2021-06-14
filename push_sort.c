/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:05:35 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/14 22:50:01 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_lstlen(t_head *head)
{
	t_li	*li;
	int		i;
	
	i = 1;
	li = head->fir;
	while (li->next != NULL)
	{
		li = li->next;
		i++;
	}
	return (i);
}

int		sortright(t_head *head)
{
	t_li	*li;
	int		len;

	//li = (t_li*)malloc(sizeof(t_li*));
	li = head->fir;
	len = ft_lstlen(head) - 1;
	while (len > 0)
	{
		if (li->data < li->next->data)
			len--;
		else
		{
			//free(li);
			return (len);
		}
		li = li->next;
	}
	//free(li);
	return (0);
}

void	sort(t_head *head, t_head *bhed)
{
	int		len;

	len = ft_lstlen(head);
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if (sortright(head) == 0)
			return ;
		else
		{
			swap(head);
			return ;
		}
	}
	else if (len == 3)
		sorthird(head);
	else
		// 새로운 함수?
}
