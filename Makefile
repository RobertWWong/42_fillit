CC =gcc
SRC_DIR =srcs/
INCLUDE=includes
CFLAGS =-I $(INCLUDE) -Wall -Wextra -Werror
NAME = fillit
MAIN_FILE = ./test/test_main.c
SRC := $(filter-out main.c ,$(wildcard $(SRC_DIR)*.c))
OBJ = $(patsubst srcs/%.c, %.o, $(SRC))
BAD = $(wildcard input_files/errors/err*)
GOOD = $(wildcard input_files/correct/val*)

all: $(NAME)

$(NAME): $(SRC)
	cd ./srcs/libft && make -f Makefile
	mv ./srcs/libft/libft.a .
	$(CC) -g $(CFLAGS) -c $(SRC)
	$(CC) $(MAIN_FILE) -o $(NAME) $(OBJ) ./libft.a

clean:
	cd ./srcs/libft && make clean
	rm -f *.o $(SRC_DIR)*.o test/*.o

fclean: clean
	cd srcs/libft && make fclean
	rm -f $(NAME)
	rm -f ./libft.a

run: all
	./$(NAME)

re: fclean all

rerr:
	gcc -g $(MAIN_FILE) $(OBJ) -L. -lft
	./$(NAME) $(BAD)
	./$(NAME) $(GOOD)

rt:
	gcc -g $(MAIN_FILE) $(OBJ) -o $(NAME) -L. -lft
	./$(NAME) input_files/errors/error_9
	./$(NAME)	input_files/correct/valid_12
.PHONY: clean fclean re
