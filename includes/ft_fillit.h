#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "tetro.h"

typedef struct		s_board
{
	t_tetro			**tetro;
	char			**board_state;
	int				dimension[2];
	int				area;
}					t_board;

int					solve_smallest_sq();
int					backtrack_map();
int					create_board();
int					free_all_data(t_board *board);


#endif
