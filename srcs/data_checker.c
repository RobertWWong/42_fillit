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

#include "../includes/tetro.h"

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
*/
int		check_tetro(char *tetro)
{
	int		i;
	int		j;
	int 	list[4];

	i = 0;
	j = 0;
	ft_bzero((void *)list, 4);
	while (j < 4 && tetro[i])
	{
		if (tetro[i] == '#' && i - 5 >= 0)
			list[j] += (tetro[i - 5] == '#') ? 1 : 0;
		if (tetro[i] == '#' && i + 5 <= 19)
			list[j] += (tetro[i + 5] == '#') ? 1 : 0;
		if (tetro[i] == '#' && i > 0)
			list[j] += (tetro[i - 1] == '#') ? 1 : 0;
		if (tetro[i] == '#' && i < 19)
			list[j] += (tetro[i + 1] == '#') ? 1 : 0;
		if (tetro[i] == '#')
			j++;
		i++;
	}
	if (list[0] + list[1] + list[2] + list[3] >= 6)
		return (1);

	return (0);
}

int		advanced_validate(char **tetroes)
{
	int		i;
	int		sides;

	sides = 0;
	i = 0;
	while (tetroes[i])
	{
		if (!check_tetro( tetroes[i]))
			return (0);
		i++;
	}
	return (1);
}
