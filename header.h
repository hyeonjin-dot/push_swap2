/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:24:11 by hyejung           #+#    #+#             */
/*   Updated: 2021/07/01 17:53:40 by jeonghyeo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include "./libft/libft.h"
#include <stdlib.h> //malloc,exit
#include <unistd.h> //write,read
#include <stdio.h> //

typedef struct		s_li
{
	int				data;
	struct s_li*	next;
}					t_li;

typedef struct		s_head
{
	struct s_li*	fir;
}					t_head;

void		li_init(t_head *head);
void		li_insert(t_head *head, int data);
void		li_free(t_head *head);
void		swap(t_head *head, char c);
void		rotate(t_head **head, char c);
void		push(t_head **head, t_head **bhed, char c);
void		revrotate(t_head **head, char c);
void		sort(t_head *head, t_head *bhed);
void		re_sort(t_head *head, t_head *bhed, char c);
void		re_sortb(t_head *bhed, t_head *head, char c);
void		sortother(t_head *head, t_head *bhed);
void		sortotherb(t_head *bhed, t_head *head);
int			sortright(t_head *head);
int			sortleft(t_head *head);
int			checksort(t_head *head, char c);
int			checkcontent(t_head *head);
void		sorthird(t_head *head, t_head *bhed, char c);
void		sorthirdb(t_head *bhed, t_head *head, char c);
void		resorthird(t_head *head, t_head *bhed, char c);
void		resorthirdb(t_head *head, t_head *bhed, char c);
void		sortfive(t_head *head, t_head *bhed);
void		sortfiveb(t_head *bhed, t_head *head);
void		lastsort(t_head *head, t_head *bhed);
void		ft_error();
int			ft_lstlen(t_head *head);
void		quicksort(int *lst, int i, int j);
int			*mklst(t_head *head);
long long	ft_atoi2(const char *str);

#endif
