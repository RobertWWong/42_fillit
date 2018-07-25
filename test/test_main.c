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

void 	del_str_arr(char **str)
{
		char **tmp = str;
		char **newTemp = tmp;

		for (size_t i = 0; i < 4; i++) {
			newTemp = tmp + 1;
			ft_strdel(tmp);
			tmp = newTemp;
		}
		str = NULL;
}
void use_point(t_point point)
{
	//printf("Here are our points:\nx=%d\ny=%d\n\n", point.x, point.y );
}

int		lets_fillit(char *file_name)
{
	char	*data;
	char	**tetroes;
	int		tetro_cnt;
	int		lines;

	data = NULL;
	tetroes = NULL;
	if (!(data = get_data(file_name, data)) || !basic_validate(data))
	{
		ft_putstr("error\n");
		return (0);
	}
	else
	{
		//count amount of lines in a file
		lines = ft_strcount(data, '\n');
		//Allocate spaces for a string array, with each string being a tetro
		tetroes = (char **)malloc(sizeof(char *) * (lines / 4 + 1));
		//Get our list of tetro strings
		tetroes = get_tetroes(data, tetroes);

		if ((tetro_cnt = advanced_validate(tetroes))< 1)
		{
			return (0);
		}
		t_board *board = NULL;
		if (!(board = fill_square(tetroes)))
			return (0);
//printf("\n\n");
		print_board(board);
		//printf("\n");
		free_all_data(board);
		del_str_arr(tetroes);


	}
}

int				main(int argc, char **argv)
{
	argv++;
	if (argc >= 2)
	{
		if (!(lets_fillit(*argv)))
			return (0);
		argv++;
		argc--;
	}
	return (1);
}
