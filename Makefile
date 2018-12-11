# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 11:06:32 by amalsago          #+#    #+#              #
#    Updated: 2018/12/11 13:08:03 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# Compilator and flags
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# **************************************************************************** #
# System commands :
RM			=	/bin/rm -rf
MKDIR		=	mkdir
MAKE		=	make -C

# **************************************************************************** #
# General :
NAME		=	fillit
CPPFLAGS	=	-Iincludes
LIB_NAME	=	-lft
LDFLAGS		=	-Llibft

# **************************************************************************** #
# Directories of source and object files :
SRCDIR		=	./sources
OBJDIR		=	./objects
INCDIR		=	./includes

# **************************************************************************** #
# List of source files :
SRC_NAME	=	main.c				\
				checks.c			\
				fill_tetri_coo.c	\
				open_sample.c		\
				create_square.c		\
				ft_sqrt_up.c		\
				fill_square.c

# **************************************************************************** #
# Automatic variables where are listed the names of sources and objects files :
SRC			=	$(addprefix $(SRCDIR)/, $(SRC_NAME))
OBJ 		=	$(addprefix $(OBJDIR)/, $(SRC_NAME:.c=.o))

# **************************************************************************** #
# Rules :

all: $(NAME)
$(NAME): $(LIB_NAME) $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@ 

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(OBJDIR) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIB_NAME):
	$(MAKE) ./libft fclean && $(MAKE) ./libft

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJDIR) 2> /dev/null || true

fclean: clean
	@make -C ./libft fclean 
	@$(RM) $(NAME)

re: fclean all

norm:
	norminette $(SRCDIR) $(INCDIR)
