NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ../../includes
SRC := $(wildcard ./*.c)
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

rt:
	gcc ../main.c -g -L. -lft -o run_test
	./run_test

.PHONY: clean fclean re
