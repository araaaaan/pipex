# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arlee <arlee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 16:14:53 by arlee             #+#    #+#              #
#    Updated: 2023/11/23 16:14:58 by arlee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Werror -Wall -Wextra
RM = rm -rf
LIB = libft/libft.a

SRCS = 	pipex.c\
		pipex_utils.c

OBJS =	$(SRCS:%.c=%.o)

all:	$(NAME)

lib: 
	@make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): lib $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re:	fclean all

.PHONY:	all clean fclean re


