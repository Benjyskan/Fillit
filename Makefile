# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 11:06:32 by amalsago          #+#    #+#              #
#    Updated: 2018/12/13 11:36:55 by penzo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# Compilator and flags
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g 

# **************************************************************************** #
# System commands :
RM			=	rm -rf
MKDIR		=	mkdir -p
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
				fill_square.c		\
				print_map.c

# **************************************************************************** #
# Automatic variables where are listed the names of sources and objects files :
SRC			=	$(addprefix $(SRCDIR)/, $(SRC_NAME))
OBJ 		=	$(addprefix $(OBJDIR)/, $(SRC_NAME:.c=.o))
LIB			=	$(addprefix $(LIBDIR)/, $(LIB_NAME))

# **************************************************************************** #
# Rules :

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $^ -o $@ 

debug:
	$(CC) $(SRC) -fsanitize=address -g3 $(CPPFLAGS) $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(MKDIR) $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIB):
	$(MAKE) $(LIBDIR) fclean && $(MAKE) $(LIBDIR)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJDIR) 2> /dev/null || true

fclean: clean
	$(MAKE) $(LIBDIR) fclean 
	$(RM) $(NAME)

re: fclean all

norm:
	norminette $(SRCDIR) $(INCDIR) $(LIBDIR)

.PHONY: all clean fclean re norm
