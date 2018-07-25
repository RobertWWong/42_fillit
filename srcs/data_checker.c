/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:41:25 by zwang             #+#    #+#             */
/*   Updated: 2018/07/25 13:39:31 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_ops.h"
#include <stdio.h>

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
			{
				printf("Failed at check block\n");
				return (0);
			}
		// printf("Here's our data and i s = \n%si=%d\n\n", data, i);
		if (!data[i] && data[i - 2] != '\n')
		{
			printf("This dat ais null and two character back is not a null %c\n", data[i - 2]);
			return (1);
		}
		if (data[i++] != '\n')
		{
			printf("The last character isn't null %c\n",data[i]);
			return (0);
		}
	}
	if (data[i - 1] == '\n' && data[i - 2] == '\n')
		return (0);
	return (1);
}

/*
Definitely need to recheck this process.
Given a string rep of a tetro (including new line)
*/
int		check_tetro(char *tetro)
{
	int		i;
	int		j;
	int		k;
	int 	list[4];

	i = 0;
	j = 0;
	k = 0;
	while (k < 4)
		list[k++] = 0;
	while (j < 4 && tetro[i])
	{
		// printf("%d\t%d\t%d\t%d\n", list[0], list[1], list[2], list[3]);
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
	// printf("%d\t%d\t%d\gettett%d\n", list[0], list[1], list[2], list[3]);
	if (list[0] + list[1] + list[2] + list[3] >= 6)
		return (1);
	return (0);
}

/*
Will check all tetro string
return count of valid tetro in string
return 0 if any tetro is invalid*/
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
	return (i);
}
