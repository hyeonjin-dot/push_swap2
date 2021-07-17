# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 13:33:00 by hyejung           #+#    #+#              #
#    Updated: 2021/07/16 22:50:10 by hyejung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
LIBFT	=	libft
LIB		=	libft/libft.a

SRCS	=	./push_swap.c\
			./push_func.c\
			./push_func2.c\
			./push_list.c\
			./push_quicksort.c\
			./push_sort.c\
			./push_sortother.c\
			./push_third.c\
			./push_five.c\
			./push_word.c

OBJS        = $(SRCS:.c=.o)
INCS        = ./libft
RM          = rm -f
LIBC        = ar rc
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $(<:.c=.o)

$(NAME) : $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(LIB)	:
	make -c libft/

all		:	$(NAME)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
