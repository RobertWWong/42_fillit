CC =gcc
SRC_DIR =srcs/
INCLUDE=includes/
CFLAGS =-I $(INCLUDE) -Wall -Wextra -Werror
OUTPUT = fillit
MAIN = ./test/test_main.c
SRC := $(MAIN) $(filter-out main.c file_io.c ,$(wildcard $(SRC_DIR)/*.c))	#this will exclude main for now
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
