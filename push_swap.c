/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:23:57 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/10 21:00:33 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_num(char  *str)
{
    long long   num;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			j++;
		i++;
	}
    if (str[0] != '-' && !(str[0] >= '0' && str[0] <= '9'))
		ft_error();
    num = ft_atoi2(str);
    if (num > 2147483647 || num < -2147483648)
		ft_error();
	return (j);
}

char	*inspace(t_head *head, char *str, int i)
{
	char	*tmp;
	int		num;
	int		k;

	k = 0;
	while (i > 0)
	{
		tmp = str;
		num = ft_atoi(tmp);
		while (tmp[k] >= '0' && tmp[k] <= '9')
			k++;
		k++;
		if (!(tmp[k] >= '0' && tmp[k] <= '9') && !(tmp[k] == '-'))
			ft_error();
		i--;
		li_insert(head, num);
		tmp = tmp + k - 1;
		str = str + k - 1;
	}
	return (str);
}

void	checksame(t_head *head)
{
	t_li	*tmp;
	int		i;
	int		j;
	int		len;
	int		*lst;

	i = 0;
	tmp = (t_li*)malloc(sizeof(t_li));
	lst = (int *)malloc(sizeof(int) * len);
	tmp = head->fir;
	while (tmp->next != NULL)
	{
		lst[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	lst[i] = tmp->data;
	i = 0;
	while (i < ft_lstlen(head))
	{
		j = 0;
		len = 0;
		while (len < i)
		{
			if (lst[i] == lst[len])
				j++;
			if (j > 1)
				ft_error();
			len++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_head	*head;
	t_head	*bhed;
	int		i;
	int		j;
	int		num;

	i = 1;
	head = (t_head*)malloc(sizeof(t_head*));
	bhed = (t_head*)malloc(sizeof(t_head*));
	li_init(head);
	li_init(bhed);
	if (argc <= 1)
		return (0);
	while (i < argc)
	{
		j = check_num(argv[i]);
		if (j > 0)
			argv[i] = inspace(head, argv[i], j);
		num = ft_atoi(argv[i]);
		li_insert(head, num);
		i++;
	}
	checksame(head);
	sort(head, bhed);
	//li_print(head); //
}
