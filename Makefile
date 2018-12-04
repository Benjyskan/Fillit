# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 11:06:32 by amalsago          #+#    #+#              #
#    Updated: 2018/12/04 16:58:27 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC=fillit/main.c		\
	fillit/checks.c	
OBJ=$(SRC:.c=.o) 
NAME=fillit.out
HEADER=fillit/fillit.h
LIBFT=libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/ re && make -C libft/ clean
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIBFT)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC) $(HEADER) 
