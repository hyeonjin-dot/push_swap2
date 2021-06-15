/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:24:11 by hyejung           #+#    #+#             */
/*   Updated: 2021/06/15 15:20:19 by hyejung          ###   ########.fr       */
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
void		li_print(t_head *head);
void		swap(t_head *head, char c);
void		rotate(t_head *head, char c);
void		push(t_head *head, t_head *bhed, char c);
void		revrotate(t_head *head, char c);
void		sort(t_head *head, t_head *bhed);
void		sortother(t_head *head, t_head *bhed);
int			sortright(t_head *head);
int			sortleft(t_head *head);
int			sorthird(t_head *head, char c);
void		ft_error();
int			ft_lstlen(t_head *head);
int			partion(int *lst, int i, int j);
void		quicksort(int *lst, int i, int j);
int			*mklst(t_head *head);
long long	ft_atoi2(const char *str);

#endif
