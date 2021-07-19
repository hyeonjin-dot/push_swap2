/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:23:57 by hyejung           #+#    #+#             */
/*   Updated: 2021/07/19 12:20:27 by hyejung          ###   ########.fr       */
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
	str = ft_strtrim(str, " ");
	while (str[i])
	{
		if (str[i] == ' ')
			j++;
		i++;
	}
    if (!(str[0] >= '0' && str[0] <= '9') && !(str[0] == '-'))
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

	while (i > 0)
	{
		k = 0;
		str = ft_strtrim(str, " ");
		tmp = str;
		num = ft_atoi(tmp);
		if (tmp[k] == '-')
			k++;
		while (tmp[k] >= '0' && tmp[k] <= '9' && tmp[k])
			k++;
		li_insert(head, num);
		str = str + k;
		i--;
	}
	return (str);
}

void	checksame(t_head *head)
{
	int		i;
	int		j;
	int		len;
	int		*lst;

	i = 0;
	len = ft_lstlen(head);
	lst = mklst(head);
	while (i < ft_lstlen(head))
	{
		j = 0;
		len = 0;
		while (len < ft_lstlen(head))
		{
			if (lst[i] == lst[len])
				j++;
			if (j > 1)
				ft_error();
			len++;
		}
		i++;
	}
	free(lst);
	return ;
}

int		main(int argc, char *argv[])
{
	t_head	*head;
	t_head	*bhed;
	int		i;
	int		j;
	int		num;

	i = 1;
	head = (t_head*)malloc(sizeof(t_head*));
	bhed = (t_head*)malloc(sizeof(t_head*));
	li_init(head, bhed);
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
	li_free(head);
	li_free(bhed);
	return (0);
}
