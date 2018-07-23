#include "../includes/ft_fillit.h"
#include "../includes/tetro.h"

t_tetro		**create_tetro_list(char **tetro_strings, int tetro_cnt)
{
	t_tetro		**tetro_list;
	int			i;

	i = -1;
	if (!(tetro_list = malloc(sizeof(t_tetro*) * tetro_cnt + 1)))
		return (NULL);
	while (++i < tetro_cnt)
		tetro_list[i] = form_tetro(tetro_strings[i]);
	return (tetro_list);
}

t_board		*create_board(t_tetro **tetro_list)
{
	int		i;
	int		j;
	t_board	*board;

	i = 0;
	while (tetro_list[i])
		i++;
	board = malloc(sizeof(t_board));
	board->tetro = tetro_list;
	board->tetro_amt = i;
	board->sq_len = ft_sqrt(i * 4);
	board->board_state = (char**)malloc(sizeof(char*) * board->sq_len + 1);
	board->board_state[i] = NULL;
	while ((i - 1) >= 0)
		board->board_state[i-- - 1] = ft_strnew(board->sq_len);
	while (i < board->sq_len && !(j = 0))
	{
		printf("please work \n");

		while (j < board->sq_len)
		{
			printf("please work \n");
			board->board_state[i++][j++] = '.';
		}
	}
	return (board);

}
// int 		grow_board()
