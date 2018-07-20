CC =gcc
SRC_DIR =srcs/
INCLUDE=includes/
CFLAGS =-I$(INCLUDE) -Wall -Wextra -Werror
OUTPUT = fillit
SRC := ./test/test_main.c $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:.c=.o)

all: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(OUTPUT) -L ./libft -lft

clean:
	rm -f *.o $(SRC_DIR)*.o *~ core

fclean: clean
	rm -f $(OUTPUT)

run: all
	./$(OUTPUT)

re: fclean all

rt:
	gcc ./test/test_main.c -L ./libft -lft -o $(OUTPUT)

.PHONY: clean fclean re
