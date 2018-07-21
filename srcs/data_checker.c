/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:41:25 by zwang             #+#    #+#             */
/*   Updated: 2018/07/21 13:56:59 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetrimino.h"

int		check_block(char *data, int *i)
{
	int		j;
	int		k;
	int		sharps;

	j = 0;
	sharps = 0;
	while (j++ < 4)
	{
		k = 0;
		while (k++ < 4)
		{
			if (data[*i] == '#')
				sharps++;
			else if (data[*i] != '.')
				return (0);
			(*i)++;
		}
		if (data[(*i)++] != '\n')
			return (0);
	}
	if (sharps != 4)
		return (0);
	return (1);
}

int		basic_validate(char *data)
{
	int		i;

	i = 0;
	while (data[i])
	{
		if (!check_block(data, &i))
			return (0);
		if (!data[i])
			return (1);
		if (data[i++] != '\n')
			return (0);
	}
	return (1);
}

/*
** Not working at the moment
** i doesn't increment, we will benefit from a dfs with 2d array boolean count
*/
int		check_tetrimino(char **tetrimino)
{
	int		i;
	int		j;
	int		map[4][4];
	int 	*list;
	i = 0;
	j = 0;
	list = (int *)malloc(sizeof(int) * 4);
	while (j < 4 && tetrimino[i])
	{
		if (tetrimino[i] == '#' && i - 5 >= 0)
			list[j] += (tetrimino[i - 5] == '#') ? 1 : 0;
		if (tetrimino[i] == '#' && i + 5 <= 19)
			list[j] += (tetrimino[i + 5] == '#') ? 1 : 0;
		if (tetrimino[i] == '#' && i > 0)
			list[j] += (tetrimino[i - 1] == '#') ? 1 : 0;
		if (tetrimino[i] == '#' && i < 19)
			list[j] += (tetrimino[i + 1] == '#') ? 1 : 0;
		if (tetrimino[i] == '#')
			j++;
		i++;
	}

	return (0);
}

int		advanced_validate(char **tetriminoes)
{
	int		i;
	int		j;
	int		sides;
	char	**tetri;

	sides = 0;
	i = 0;
	while (tetriminoes[i])
	{
		printf("%s\n", tetriminoes[i]);
		tetri = ft_strsplit(tetriminoes[i], '\n');
		if (!check_tetrimino(tetri))
			return (0);
		ft_strdel(tetri);
		i++;
	}
	printf("we're golden!\n");
	return (1);
}
