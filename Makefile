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
	cd ./srcs/libft && make -f Makefile
	mv ./srcs/libft/libft.a .
	$(CC) $(CFLAGS) -c $(SRC)
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

rt:
	gcc $(MAIN_FILE) $(OBJ) -L. -lft
	#./$(NAME) ./input_files/invalid_sample.fillit
	./$(NAME) ./input_files/valid_sample.fillit

.PHONY: clean fclean re
