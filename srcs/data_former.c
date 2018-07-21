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

t_point	*find_upper_point(char **tetro, t_point *upper)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 5)
	{
		while (j < 5)
		{
			if (tetro[i][j] == '#')
			{
				upper = (t_point *)malloc(sizeof(t_point));
				upper->x = j;
				upper->y = i;
			}
			j++;
		}
		i++;
	}
	return (upper);
}

t_point	*find_lower_point(char **tetro, t_point *lower)
{
	int		i;
	int		j;

	i = 4;
	j = 0;
	while (i >= 0)
	{
		while (j < 5)
		{
			if (tetro[i][j] == '#')
			{
				lower = (t_point *)malloc(sizeof(t_point));
				lower->x = j;
				lower->y = i;
			}
			j++;
		}
		i--;
	}
	return (lower);
}

t_point	*find_left_point(char **tetro, t_point *left)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 5)
	{
		while (i < 5)
		{
			if (tetro[i][j] == '#')
			{
				left = (t_point *)malloc(sizeof(t_point));
				left->x = j;
				left->y = i;
			}
			i++;
		}
		j++;
	}
	return (left);
}

t_point	*find_right_point(char **tetro, t_point *right)
{
	int		i;
	int		j;

	i = 0;
	j = 4;
	while (j >= 4)
	{
		while (i < 5)
		{
			if (tetro[i][j] == '#')
			{
				right = (t_point *)malloc(sizeof(t_point));
				right->x = j;
				right->y = i;
			}
			i++;
		}
		j--;
	}
	return (right);
}

t_tetrimino	*form_tetrimino(char *tetrimino)
{
	char		**tetro;
	// int			height;		//never used
	// int			width;
	t_tetrimino	*item;

	tetro = ft_strsplit(tetrimino, '\n');
	item = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	item->upper = find_upper_point(tetro, item->upper);
	item->lower = find_lower_point(tetro, item->lower);
	item->left = find_left_point(tetro, item->left);
	item->right = find_left_point(tetro, item->right);
	item->height = item->lower->y - item->upper->y;
	item->width = item->right->x - item->left->x;
	return (item);
}
