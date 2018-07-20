/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:27:29 by zwang             #+#    #+#             */
/*   Updated: 2018/07/20 14:35:58 by rowong           ###   ########.fr       */
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

char	**get_tetriminoes(char *data, char **tetriminoes)
{
	char	**tmp;
	int		i;
	int		j;
	int		count;

	tmp = ft_strsplit(data, '\n');
	i = 0;
	j = 0;
	while (tmp[j])
	{
		tetriminoes[i] = ft_strnew(21);
		count = 0;
		while (count++ < 4)
			ft_strcat(tetriminoes[i], tmp[j++]);
		i++;
	}
	return (tetriminoes);
}
