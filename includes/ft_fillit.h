#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "tetro.h"
# include "libft.h"

typedef struct		s_board
{
	t_tetro			**tetro_list;
	char			**board_state;
	int				sq_len;
	int				tetro_amt;
}					t_board;

int					backtrack_map(t_board *board, int tetro_index);
t_board				*create_board(t_tetro **tetro_list);
void				free_all_data(t_board *board);
t_tetro				**create_tetro_list(char **tetro_strings, int tetro_cnt);
void				increment_board_state(t_board *board);
t_board				*fill_square(char **tetro_strings);
void 				print_board(t_board *board);

#endif
