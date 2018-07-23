/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 19:09:36 by zwang             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/07/23 10:14:24 by zwang            ###   ########.fr       */
=======
/*   Updated: 2018/07/22 19:16:34 by zwang            ###   ########.fr       */
>>>>>>> 62eb049b5a25d4d0f8d8013364456fa25bfa5ebc
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fillit.h"
#include "../includes/file_ops.h"
#include "../includes/tetro.h"

<<<<<<< HEAD
t_tetro		**create_tetro_list(char **tetro_strings, int tetro_cnt)
=======
t_tetro			**create_tetro_list(char **tetro_strings, int tetro_cnt)
>>>>>>> 62eb049b5a25d4d0f8d8013364456fa25bfa5ebc
{
	static t_tetro	**tetro_list;
	int				i;

	i = -1;
	if (!(tetro_list = malloc(sizeof(t_tetro*) * tetro_cnt + 1)))
		return (NULL);
	while (++i < tetro_cnt)
		tetro_list[i] = form_tetro(tetro_strings[i]);
	return (tetro_list);
}

<<<<<<< HEAD
int		count_tetroes(char **tetro_strings)
{
	int	i;

	i = 0;
	while (tetroes[i])
		i++;
	return (i);
}

int			ft_sqrt(int	num)
{
	float	x;
	float	y;
	float	e;

	x = n;
	y = 1;
	e = 0.000001;
	while (x - y > e)
	{
		x = (x + y) / 2;
		y = n / x;
	}
	return ((int)x);
}

t_board		*create_board(char **tetroes, int size, int size_increase)
{
	int		num;
	t_board	*board;
	char	**board_state;

	board = (t_board *)malloc(sizeof(t_board));
	board->tetro_amt = count_tetroes(tetroes);
	if (size_increase)
		board->sq_len = size + 1;
	else
		board->sq_len = ft_sqrt(board->tetro_amt * 4);
	board_state = (char **)malloc(size(char *) * board->sq_len);
	board->board_state = board_state;
	return (board);
}

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

int			backtrack_map(t_board *board, int tetro_index)
{
	int		i;
	int		j;
	t_point	*pos;
	
	if (board->tetro_amot == 0)
		return (1);
	i = 0;
	while (i < board->sq_len)
	{
		j = 0;
		while (j < board->sq_len)
		{
			pos->x = i;
			pos->y = j;
			if (is_safe(board, tetroes[tetro_index], pos))
			{
				remove_or_add(board, tetroes[tetro_index], pos, 1);
				if (backtrack_map(board, tetro_index + 1))
					return (1);
				remove_or_add(board, tetroes[tetro_index], pos, 0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			fill_square(char **tetro_strings)
{
=======
>>>>>>> 62eb049b5a25d4d0f8d8013364456fa25bfa5ebc

