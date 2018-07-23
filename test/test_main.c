/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 15:22:27 by zwang             #+#    #+#             */
/*   Updated: 2018/07/20 16:46:18 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetro.h"
#include "../includes/file_ops.h"
#include "../includes/ft_fillit.h"

/*
Read from a input file a map of tetro and return a list of tetroes
or NULL if any validation checks fail
*/
static t_tetro	**get_input_to_tetro_list(char *filename, int debug)
{
	char	*data;
	char	**tetroes;
	int		tetro_cnt;
	int		lines;

	data = NULL;
	tetroes = NULL;
	if (!(data = get_data(filename, data)) || !basic_validate(data))
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	// if (!basic_validate(data))
	// {
	// 	ft_putstr("Error\n");
	// 	return (0);
	// }
	else
	{
		//count amount of lines in a file
		lines = ft_strcount(data, '\n');
		//Allocate spaces for a string array, with each string being a tetro
		tetroes = (char **)malloc(sizeof(char *) * (lines / 4 + 1));
		//Get our list of tetro strings
		tetroes = get_tetroes(data, tetroes);
		//if all the tetro are valid, then we can create our lists
		if ((tetro_cnt = advanced_validate(tetroes)))
		{
			int i = -1;
			while (debug && ++i < tetro_cnt)
				ft_putstr(ft_strcat(tetroes[i], "\n"));
			return (create_tetro_list(tetroes, tetro_cnt));
		}
	}
	return (NULL);
}


int				main(int argc, char **argv)
{
	t_tetro	**tetro_list;

	argv++;
	if (argc >= 2)
	{
		if (!(tetro_list = get_input_to_tetro_list(*argv, 1)))
			return (0);
		print_tetro(tetro_list[0]);
		argv++;
		argc--;
	}
	return (0);
}
