/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:09:36 by zwang             #+#    #+#             */
/*   Updated: 2018/07/24 15:28:51 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fillit.h"
#include "../includes/file_ops.h"
#include "../includes/tetro.h"

void 	print_board(t_board *board)
{
	int i;

	i = 0;
	while (i < board->sq_len)
	{
		ft_putstr(board->board_state[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

int		count_tetroes(char **tetro_strings)
{
	int	i;

	i = 0;
	while (tetro_strings[i])
		i++;
	return (i);
}

t_tetro			**create_tetro_list(char **tetro_strings, int tetro_cnt)
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
	char	**board_state;

	i = 0;
	while (tetro_list[i])
		i++;
	if (!(board = (t_board *)malloc(sizeof(t_board))))
		return (NULL);
	board->tetro_amt = i;
	board->sq_len = ft_sqrt(board->tetro_amt * 4);
	board->tetro_list = tetro_list;
	board_state = (char **)malloc(sizeof(char *) * board->sq_len + 1);
	i = -1;
	while (++i < board->sq_len)
	{
		board_state[i] = ft_strnew(board->sq_len + 1);
		j = -1;
		while (++j < board->sq_len)
			board_state[i][j] = '.';
	}
	board_state[i] = NULL;
	board->board_state = board_state;
	return (board);
}


/*
Will free our board.
*/

void		delete_board_state(t_board *board)
{
	char	**prev;
	char	**curr;

	prev = board->board_state;
	while (*prev)
	{
		curr = prev + 1;
		ft_strdel(prev);
		prev = curr;
	}
	free(board->board_state);
	board->board_state = NULL;
}

void		increment_board_state(t_board *board)
{
	char	**new_state;
	int		i;
	int		j;

	//printf("Deleting our board\n");
	delete_board_state(board);
	//printf("creating new board\n");

	board->sq_len += 1;
	new_state = (char **)malloc(sizeof(char *) * (board->sq_len + 1));
	i = 0;
	while (i < board->sq_len)
	{
		new_state[i] = ft_strnew(board->sq_len + 1);
		j = 0;
		while (j < board->sq_len)
			new_state[i][j++] = '.';
		i++;
	}
	// //printf("New state should be available now\n");
	new_state[i] = NULL;
	board->board_state = new_state;
}

/*
Don't need * pointer, just the */
int			is_safe(t_board *board, t_tetro *tetro, t_point pos)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((tetro->points)[i].x + pos.x >= board->sq_len ||(tetro->points)[i].y + pos.y >= board->sq_len)
			return (0);
		if (board->board_state[(tetro->points)[i].x + pos.x][(tetro->points)[i].y + pos.y] != '.')
			return (0);
		i++;
	}
	return (1);
}

void		remove_or_add(t_board *board, int tetro_index, t_point pos,
				int add_rem)
{
	int		i;
	char	c;
	t_tetro *tetro;

	//added the tetro piece given a tetro index, easier to manage this way.
	tetro = board->tetro_list[tetro_index];
	i = 0;
	c = (add_rem == 1) ? 'A' + tetro_index : '.';
	while (i < 4)
	{
		board->board_state[(tetro->points)[i].x + pos.x]
			[(tetro->points)[i].y + pos.y] = c;
		i++;
	}
	//printf("Done\n\n");

}

int			backtrack_map(t_board *board,  int tetro_index)
{
	int		i;
	int		j;
	t_point	pos;

	//printf("sq_len = %d\n",board->sq_len );
	// //printf("tetro index vs tetro amt %d vs %d\n\n", tetro_index, board->tetro_amt);
	if (tetro_index >= board->tetro_amt)
		return (1);
	i = 0;
	while (i < board->sq_len && !(j = 0))
	{
		while (j < board->sq_len)
		{
			pos.x = i;
			pos.y = j;
			//is safe isn't working correctly?
			if (is_safe(board, (board->tetro_list)[tetro_index], pos))
			{

				//printf("Passed is safe %d vs %d \n\n", pos.x, pos.y);
				remove_or_add(board, tetro_index, pos, 1);
				// print_board(board);
				if (backtrack_map(board, tetro_index + 1))
					return (1);
				remove_or_add(board, tetro_index, pos, 0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void 	free_all_data(t_board *board)
{
	int i;

	i = 0;
	delete_board_state(board);
	while (i < board->tetro_amt)
		free_tetro(board->tetro_list[i++]);
	free(board->tetro_list);
	board->tetro_list = NULL;
	free(board);
	board = NULL;
}


t_board		*fill_square(char **tetro_strings)
{
	static int		tetro_index;
	t_board	*board;
	t_tetro	**tetro_list;
	int		tetro_cnt;

	tetro_cnt = count_tetroes(tetro_strings);
	if (!(tetro_list = create_tetro_list(tetro_strings, tetro_cnt)))
		return (NULL);

	//printf("what is our tetro list?\n%d\n\n", tetro_list[0]->points->x);

	board = create_board(tetro_list);
	tetro_index = 0;
	while (!backtrack_map(board, tetro_index))
	{
		increment_board_state(board);
	}
	// free_all_data(board);
	// //printf("%s comeon \n\n", res[0]);
	return (board);
	//return (char**)"not done";
}
