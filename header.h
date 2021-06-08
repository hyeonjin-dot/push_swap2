
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

void		li_insert(t_head *head, int data);
void		li_print(t_head *head);
long long	ft_atoi2(const char *str);

#endif
