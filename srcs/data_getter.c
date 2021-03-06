/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:27:29 by zwang             #+#    #+#             */
/*   Updated: 2018/07/23 09:31:14 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_ops.h"

/*
** Read 21 char bytes at a time from to a char buffer to determine the size
** of the file read.
*/
int		count_char(int file_desc)
{
	int		size;
	char	characters[600];

	ft_strclr(characters);
	size = 0;
	if ((size = read(file_desc, characters, 547)) > 0)
	{
		return size;
		// size = size + 20;
		// if (read(file_desc, characters, 1) > 0)
		// 	size++;
		// else
		// 	return (size);
		// if (characters[0] != '\n')
		// 	return (-1);
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

	if ((size = count_char(file_desc)) < 0 || size > 546)
	{
		close(file_desc);
		return (NULL);
	}
	close(file_desc);
	// printf("Size=%d \n\n",size);
	if ((file_desc = open(file_name, O_RDONLY)) < 1)
		return (NULL);
	data = (char *)malloc(sizeof(char) * (size + 1));
	data[size] = '\0';
	if (read(file_desc, data, size) < 0)
		return (NULL);
	return (data);
}

/*
Return a list of tetro string rep from the file buffer */
char	**get_tetroes(char *data, char **tetroes, int tetro_amt)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data[j] && i < tetro_amt)
	{
		tetroes[i] = ft_strnew(21);
		ft_strncpy(tetroes[i], &data[j], 20);
		i++;
		j = j + 21;
	}
	tetroes[i] = NULL;
	return (tetroes);
}
