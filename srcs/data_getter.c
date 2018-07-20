/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:27:29 by zwang             #+#    #+#             */
/*   Updated: 2018/07/20 10:46:05 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrimino.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);	
}

int		count_char(int file_desc)
{
	int		size;
	char	characters[22];
	int		ret;

	size = 0;		
	while (read(file_desc, characters, 20) > 0)
	{
		size = size + 20;
		if (read(file_desc, characters, 1) > 0)
			size++;
	}
	return (size);
}

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

