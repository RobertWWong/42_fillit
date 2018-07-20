CC =gcc
SRC_DIR =srcs/
INCLUDE=includes/
CFLAGS =-I $(INCLUDE) -Wall -Wextra -Werror
OUTPUT = fillit
SRC := ./test/test_main.c $(filter-out main.c file_io.c ,$(wildcard $(SRC_DIR)/*.c))
OBJ := $(SRC:.c=.o)

all: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(OUTPUT) -L ./libfta -lft

clean:
	rm -f *.o $(SRC_DIR)*.o *~ core

fclean: clean
	rm -f $(OUTPUT)

run: all
	./$(OUTPUT)

re: fclean all

rt:
	./$(OUTPUT) ./input_files/invalid_sample.fillit

.PHONY: clean fclean re
