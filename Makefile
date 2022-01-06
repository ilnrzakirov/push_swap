# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 10:27:28 by bcarlee           #+#    #+#              #
#    Updated: 2022/01/02 17:01:08 by bcarlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	src/push_swap.c			src/utils.c			src/error.c\
			src/ft_split.c			src/valid.c			src/push_swap_func.c\
			src/swap.c				src/sort.c			src/rotate.c\
			src/push.c				src/div.c			src/sort_stack.c\
			src/utils2.c


SRCS_B	= 	\


HEADER	=	includes/push_swap.h

OBJS	=	$(SRCS:%.c=%.o)

OBJSB	=	$(SRCS_B:%.c=%.o)

CC		=	gcc -g

INC		=	-I includes 

CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

$(NAME)	:	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY	:	all clean fclean re

all		:	$(NAME)

bonus	:	$(OBJSB) $(HEADER)
	$(CC) $(CFLAGS) $(INC) $(OBJSB) -o $(NAME)

clean	:
	@rm -f $(OBJS) $(OBJSB)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all
