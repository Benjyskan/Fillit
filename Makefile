# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 11:06:32 by amalsago          #+#    #+#              #
#    Updated: 2018/12/07 17:01:42 by penzo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
#delete -g plz
#CFLAGS=-Wall -Wextra -Werror -g
CFLAGS=-Wall -Wextra -g
SRC=src/main.c				\
	src/checks.c			\
	src/fill_tetri_coo.c	\
	src/open_sample.c		\
	src/create_square.c		\
	src/fill_table.c
OBJ=$(SRC:.c=.o) 
NAME=fillit
HEADER=fillit/fillit.h
LIBFT=libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIBFT)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC) $(HEADER)
