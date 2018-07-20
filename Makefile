CC =gcc
SRC_DIR =srcs/
INCLUDE=includes
CFLAGS =-I $(INCLUDE) -Wall -Wextra -Werror
NAME = fillit
MAIN_FILE = ./test/test_main.c
SRC := $(filter-out main.c file_io.c ,$(wildcard $(SRC_DIR)*.c))
OBJ = $(patsubst srcs/%.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(MAIN_FILE) -o $(NAME) $(OBJ) ./libft/libft.a

clean:
	rm -f *.o $(SRC_DIR)*.o *~ core

fclean: clean
	rm -f $(NAME)

run: all
	./$(NAME)

re: fclean all

rt:
	gcc $(MAIN_FILE) $(OBJ) -L ./libft -lft
	./$(NAME) ./input_files/invalid_sample.fillit
	./$(NAME) ./input_files/valid_sample.fillit

.PHONY: clean fclean re
