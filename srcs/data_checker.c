/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:41:25 by zwang             #+#    #+#             */
/*   Updated: 2018/07/20 13:53:05 by zwang            ###   ########.fr       */
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
int		advanced_validate(char *data)
{
*/	
