/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:27:29 by zwang             #+#    #+#             */
/*   Updated: 2018/07/20 15:54:33 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetrimino.h"

/*
** Read 21 char bytes at a time from to a char buffer to determine the size
** of the file read.
*/
int		count_char(int file_desc)
{
	int		size;
	char	characters[22];

	size = 0;
	while (read(file_desc, characters, 20) > 0)
	{
		size = size + 20;
		if (read(file_desc, characters, 1) > 0)
			size++;
	}
	return (size);
}

/*
** Read from a file into a string buffer the contents of the file
** Allocates memory to a string data pointer before reading in the entirety of
** the file to pointer.
*/
char	*get_data(char *file_name, char *data)
{
	int		file_desc;
	int		size;

	if ((file_desc = open(file_name, O_RDONLY)) < 1)
		return (NULL);
	size = count_char(file_desc);
	close(file_desc);
	if ((file_desc = open(file_name, O_RDONLY)) < 1)
		return (NULL);
	data = (char *)malloc(sizeof(char) * (size + 1));
	if (read(file_desc, data, size) < 0)
		return (NULL);
	return (data);
}

int		ft_strcount(char const *s, char c)
{
	int	num;

	if (!(*s))
		return (0);
	num = (*s == c) ? 0 : 1;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			num++;
		}
		else
			s++;
	}
	if (*(s - 1) == c)
		num--;
	return (num);
}

char	**get_tetriminoes(char *data, char **tetriminoes)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data[j])
	{
		tetriminoes[i] = ft_strnew(21);
		ft_strncpy(tetriminoes[i], &data[j], 20);
		i++;
		j = j + 21;	
	}
	tetriminoes[i] = NULL;
	return (tetriminoes);
}
