# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaaaaran <aaaaaran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 14:13:24 by arlee             #+#    #+#              #
#    Updated: 2023/08/09 02:57:35 by aaaaaran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
RM = rm -f 
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = ft_toupper.c \
        ft_isalpha.c \
        ft_isdigit.c \
        ft_tolower.c \
        ft_isalnum.c \
        ft_isascii.c \
        ft_strchr.c \
        ft_isprint.c \
        ft_strrchr.c \
        ft_strlen.c \
        ft_strncmp.c \
        ft_memset.c \
        ft_bzero.c \
        ft_memchr.c \
        ft_memcpy.c \
        ft_memcmp.c \
        ft_memmove.c \
        ft_strnstr.c \
        ft_strlcpy.c \
        ft_strlcat.c \
        ft_atoi.c \
        ft_calloc.c \
        ft_strdup.c \
        ft_substr.c \
        ft_striteri.c \
        ft_strjoin.c \
        ft_strtrim.c \
        ft_split.c \
        ft_itoa.c \
        ft_strmapi.c \
        ft_putchar_fd.c \
    	ft_putstr_fd.c \
        ft_putendl_fd.c \
        ft_putnbr_fd.c 

OBJS =	$(SRCS:%.c=%.o)

OBJ_FILES =	$(OBJS)

all:	$(NAME)

$(NAME):	$(OBJ_FILES)
	$(AR) $@ $^


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)


re:	fclean all

.PHONY :	all clean fclean re
