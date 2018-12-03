NAME=fillit
CC=gcc
CFLAGS=-Werror -Wextra -Wall
CFILES=tetri_checker.c \

OFILES=${CFILES:.c=.o}

%.o: %.c
	$(CC) -o $@ -c $< -I../libft


$(NAME): $(OFILES)
	$(CC) -o $(NAME) $(OFILES) libft.a -I../libft

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

do: $(NAME)
	./$(NAME) maps/valid.map
