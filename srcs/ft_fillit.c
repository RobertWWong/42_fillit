/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:09:36 by zwang             #+#    #+#             */
/*   Updated: 2018/07/23 11:35:00 by zwang            ###   ########.fr       */
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

t_board		*create_board(t_tetro **tetro_list, int tetro_cnt)
{
	int		i;
	int		j;
	t_board	*board;
	char	**board_state;

	board = (t_board *)malloc(sizeof(t_board));
	board->tetro_amt = tetro_cnt; 
	board->sq_len = ft_sqrt(board->tetro_amt * 4);
	board->tetro_list = tetro_list;
	board_state = (char **)malloc(sizeof(char *) * board->sq_len);
	i = -1;
	while (++i < board->sq_len)
	{
		board_state[i] = ft_strnew(board->sq_len + 1);
		j = -1;
		while (++j < board->sq_len)
			board_state[i][j] = '.';
	}
	board->board_state = board_state;
t_tetro		**create_tetro_list(char **tetro_strings, int tetro_cnt)
{
	static t_tetro	**tetro_list;
	int				i;

	i = -1;
	if (!(tetro_list = malloc(sizeof(t_tetro*) * tetro_cnt + 1)))
		return (NULL);
	while (++i < tetro_cnt)
		tetro_list[i] = form_tetro(tetro_strings[i]);
	// printf("%d i value\n", i);;
	tetro_list[i] = NULL;
	return (tetro_list);
}

int		count_tetroes(char **tetro_strings)
{
 	int	i;

 	i = 0;
 	while (tetro_strings[i])
 		i++;
 	return (i);
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
	board->tetroes = tetro_list;
	board->tetro_amt = i;
	board->sq_len = ft_sqrt((i * 4));
	board->board_state = (char**)malloc(sizeof(char*) * board->sq_len + 1);
	board->board_state[i] = NULL;
	while ((i - 1) >= 0)
		board->board_state[i-- - 1] = ft_strnew(board->sq_len);
	while (i < board->sq_len && !(j = 0))
	{
		while (j < board->sq_len)
			board->board_state[i][j++] = '.';
		i++;
	}
	return (board);
}

t_board		*increment_board(t_board *board)
{
	char	**board_state;
	int		i;
	int		j;

	board_state = (char **)malloc(sizeof(char *) * (board->sq_len + 1));
	i = -1;
	while (++i < board->sq_len + 1)
	{
		//need to implement


int			is_safe(t_board *board, t_tetro *tetro, t_point *pos)
{
	int		i;

	i = 0;
	while (i < 4 && (tetro->points)[i].x + pos->x < board->sq_len &&
			(tetro->points)[i].y + pos->y < board->sq_len)
	{
		if (board->board_state[(tetro->points)[i].x + pos->x]
				[(tetro->points)[i].y + pos->y] == '#')
			return (0);
		i++;
	}
	return (1);
}

void		remove_or_add(t_board *board, t_tetro *tetro, t_point *pos,
				int	remove_add)
{
	int		i;
	char	c;

	i = 0;
	c = (remove_add == 1) ? '#' : '.';
	while (i < 4)
	{
		board->board_state[(tetro->points)[i].x + pos->x]
			[(tetro->points)[i].y + pos->y] = c;
		i++;
	}
}

int			backtrack_map(t_board *board,  int tetro_index)
{
	int		i;
	int		j;
	t_point	*pos;

	pos = (t_point*)malloc(sizeof(t_point));
//	pos->x = 0;
//	pos->y = 0;
	if (board->tetro_amt == 0)
		return (1);
	i = 0;
	while (i < board->sq_len)
	{
		j = 0;
		while (j < board->sq_len)
		{
			pos->x = i;
			pos->y = j;
			if (is_safe(board, (board->tetro_list)[tetro_index], pos))
			{
				remove_or_add(board, (board->tetro_list)[tetro_index], pos, 1);
				if (backtrack_map(board, tetro_index + 1))
					return (1);
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
	int		tetro_index;
	t_tetro	**tetro_list;
	t_board	*board;

	tetro_list = create_tetro_list(tetro_strings, tetro_cnt);
/*
	board = create_board(tetro_list, tetro_cnt, 0, 0);
	tetro_index = 0;
	while (!backtrack_map(board, tetro_index))
		board = create_board(tetro_list, tetro_cnt, board->sq_len, 1);
*/
	return (board->board_state);
}

