/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 10:51:02 by zwang             #+#    #+#             */
/*   Updated: 2018/07/22 19:36:49 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetro.h"

void		shift_all_points(t_tetro *item, int min_row, int min_col)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		(item->points[i]).x -= min_row;
		(item->points[i]).y -= min_col;
		// //printf("our points row=%d  col=%d\n",(item->points[i]).x,
		// (item->points[i]).y);
	}
}

void		create_points(t_tetro *item, char **tetro)
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
t_tetro		*form_tetro(char *tetro)
{
	char		**tetro_split;
	int			i;
	t_tetro		*item;

	item = (t_tetro *)malloc(sizeof(t_tetro));
	i = -1;
	while (++i < 4)
	{
		item->points[i].x = 0;
		item->points[i].y = 0;
	}

	tetro_split = ft_strsplit(tetro, '\n');
	// //printf("our tetrio \n%s\n", tetro);
	create_points(item, tetro_split);
	return (item);
}

int			free_tetro(t_tetro *tetro)
{
	if (!tetro)
		return (0);
	free(tetro);
	tetro = NULL;
	return (1);
}

void		print_tetro(t_tetro *tetro)
{
	int i;


	i = -1;
	while (++i < 4)
	{
		ft_putstr(ft_itoa((tetro->points[i]).x));
		ft_putchar(':');
		ft_putstr(ft_itoa((tetro->points[i]).y));
		ft_putstr("\n\n");
	}
	ft_putchar('\n');
}
