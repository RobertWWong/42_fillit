/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:09:36 by zwang             #+#    #+#             */
/*   Updated: 2018/07/23 15:10:30 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fillit.h"
#include "../includes/file_ops.h"
#include "../includes/tetro.h"

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
	board = (t_board *)malloc(sizeof(t_board));
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
Will free our board and then increase its size by one.
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

	// printf("Deleting our board\n");
	delete_board_state(board);
	// printf("creating new board\n");
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
	// printf("New state should be available now\n");
	new_state[i] = NULL;
	board->board_state = new_state;
}

/* rob board state
 *
 *	char	**board_state;
	char	**next;
	char	**board_temp;
	int		i;
	int		j;

	board_state = board->board_state;
	board_temp = (char**)malloc(sizeof(char*) * board->sq_len + 2);	//for one more + null
	i = -1;
	while (++i < board->sq_len + 1)
	{
		next = (board_state + 1);	//get next string of board state
		ft_strdel(board_state);	//deletes the current board state
		board_state = next;
		board_temp[i] = ft_strnew(board->sq_len + 2);	//make new str in temp
	}
	free(board->board_state);
	board->board_state = (char**)malloc(sizeof(char*) * board->sq_len + 2);
	board_temp[board->sq_len] = ft_strnew(board->sq_len + 2);
	i = -1;
	while ((++i < board->sq_len + 1) && (j = -1) == -1)
		while (++j < board->sq_len + 1)
			board_temp[i][j] = '.';
	board_temp[board->sq_len] = NULL;
	board->board_state = board_temp;
	board->sq_len += 1;
	return (board);
 */

/*
Don't need * pointer, just the */
int			is_safe(t_board *board, t_tetro *tetro, t_point pos)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((tetro->points)[i].x + pos.x >= board->sq_len ||
				(tetro->points)[i].y + pos.y >= board->sq_len)
			return (0);
		if (board->board_state[(tetro->points)[i].x + pos.x]
				[(tetro->points)[i].y + pos.y] == 'A')
			return (0);
		i++;
	}
	return (1);
}

void		remove_or_add(t_board *board, t_tetro *tetro, t_point pos,
				int	remove_add)
{
	int		i;
	char	c;

	i = 0;
	c = (remove_add == 1) ? 'A' : '.';

	// for (int i = 0; i < board->sq_len; i++) {
	// 	printf("board = %s     and strlen %zu\n", board->board_state[i], ft_strlen(board->board_state[i]));
	// 	//it overridden the null character???
	// }
	while (i < 4)
	{
		board->board_state[(tetro->points)[i].x + pos.x]
			[(tetro->points)[i].y + pos.y] = c;
		i++;
	}
	printf("Done\n\n");

}

int			backtrack_map(t_board *board,  int tetro_index)
{
	int		i;
	int		j;
	t_point	pos;

	// printf("tetro index vs tetro amt %d vs %d\n\n", tetro_index, board->tetro_amt);
	if (tetro_index == board->tetro_amt)
		return (1);
	i = 0;
	while (i < board->sq_len && !(j = 0))
	{
		while (j < board->sq_len)
		{
			pos.x = i;
			pos.y = j;
			printf("sq_len = %d\n",board->sq_len );
			//is safe isn't working correctly?
			if (is_safe(board, (board->tetro_list)[tetro_index], pos))
			{
				printf("Passed is safe %d vs %d \n\n", pos.x, pos.y);
				remove_or_add(board, (board->tetro_list)[tetro_index], pos, 1);
				if (backtrack_map(board, tetro_index + 1))
					return (1);
				else
					remove_or_add(board, (board->tetro_list)[tetro_index], pos, 0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char		**fill_square(char **tetro_strings)
{
	static int		tetro_index;
	t_board	*board;
	t_tetro	**tetro_list;
	int		tetro_cnt;

	tetro_cnt = count_tetroes(tetro_strings);
	tetro_list = create_tetro_list(tetro_strings, tetro_cnt);
	board = create_board(tetro_list);
	tetro_index = 0;
	while (!backtrack_map(board, tetro_index))
	{
		increment_board_state(board);
	}
	return (board->board_state);
	//return (char**)"not done";
}
