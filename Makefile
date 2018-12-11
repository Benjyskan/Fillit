# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 11:06:32 by amalsago          #+#    #+#              #
#    Updated: 2018/12/11 13:27:11 by amalsago         ###   ########.fr        #
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
LIB_NAME	=	libft.a

# **************************************************************************** #
# Directories of source and object files :
SRCDIR		=	./sources
OBJDIR		=	./objects
INCDIR		=	./includes
LIBDIR		=	./libft

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
LIB			=	$(addprefix $(LIBDIR)/, $(LIB_NAME))

# **************************************************************************** #
# Rules :

all: $(NAME)
$(NAME): $(LIB) $(OBJ)
	$(CC) $(LIB) $^ -o $@ 

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(OBJDIR) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIB):
	$(MAKE) $(LIBDIR) fclean && $(MAKE) $(LIBDIR)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJDIR) 2> /dev/null || true

fclean: clean
	@$(MAKE) $(LIBDIR) fclean 
	@$(RM) $(NAME)

re: fclean all

norm:
	norminette $(SRCDIR) $(INCDIR) $(LIBDIR)
