/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_former.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 10:51:02 by zwang             #+#    #+#             */
/*   Updated: 2018/07/21 11:50:10 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetrimino.h"

void		shift_all_points(t_tetrimino *item, int min, int max)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		(item->points[i]).x -= min;
		(item->points[i]).y -= max;
		printf("our points row=%d  col=%d\n",(item->points[i]).x, (item->points[i]).y);
	}
}

void		create_points(t_tetrimino *item, char **tetro)
{
	int i;
	int j;
	int min_row;
	int min_col;
	int point;

	i = -1;
	min_row = 10;
	min_col = 10;
	point = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetro[i][j] == '#')
			{
				(item->points[point]).x = i;
				(item->points[point++]).y = j;
				min_row = i < min_row ? i : min_row;
				min_col = j < min_col ? j : min_col;
			}
		}
	}
	shift_all_points(item, min_row, min_col);
}
/*
Algorithm for moving pieces to top left corner
find first contact with a # block and make a point struct for it
mark its row and col index
check rest of block to determine min row and col indexs
also assign coordinates to these blocks
subtract min row and col value from each point
*/
t_tetrimino	*form_tetrimino(char *tetrimino)
{
	char		**tetro;
	int			i;
	// int			height;		//never used
	// int			width;
	t_tetrimino	*item;

	item = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	i = -1;
	while (++i < 4)
	{
		item->points[i].x = 0;
		item->points[i].y = 0;
	}

	tetro = ft_strsplit(tetrimino, '\n');
	printf("our tetrio \n%s\n", tetrimino);
	create_points(item, tetro);
	return (item);
}
