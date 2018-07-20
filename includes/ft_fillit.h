#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_tetrominoes
{
	int				height;
	int				width;
	int				shape[2];
}					t_tetrominoes;

int					solve_smallest_sq();
int					solve_smallest_sq();

#endif
