/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:24:45 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/10 18:28:12 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	li_init(t_head *head)
{
	head->fir = NULL;
}

void	li_insert(t_head *head, int data)
{
	t_li	*new;
	t_li	*last;

	new = (t_li*)malloc(sizeof(t_li));
	new->data = data;
	new->next = NULL;
	if (head->fir == NULL)
	{
		head->fir = new;
		return ;
	}
	last = head->fir;
	while (last->next != NULL)
		last= last->next;
	last->next = new;
}

void	li_print(t_head *head)
{
	t_li	*new;
	char	*tmp;
	int		len;

	new = (t_li*)malloc(sizeof(t_li));
	new = head->fir;
	while (new->next != NULL)
	{
		tmp = ft_itoa(new->data);
		len = ft_strlen(tmp);
		write(1, tmp, len);
		write(1, "\n", 2);
		new = new->next;
	}
	tmp = ft_itoa(new->data);
	len = ft_strlen(tmp);
	write(1, tmp, len);
	write(1, "\n", 2);
}
