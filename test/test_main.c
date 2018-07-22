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

int		main(int argc, char **argv)
{
	char	*data = NULL;
	char	**tetroes = NULL;
	int		i;
	int		lines;

	argv++;
	if (argc >= 2)
	{
		if (!(data = get_data(*argv, data)))
		{
			ft_putstr("Error\n");
			return (0);
		}
		if (!basic_validate(data))
			ft_putstr("Invalid File");
		else
		{
			lines = ft_strcount(data, '\n');
			tetroes = (char **)malloc(sizeof(char *) * (lines / 4 + 1));
			tetroes = get_tetroes(data, tetroes);
			i = 0;
			if (advanced_validate(tetroes))
			{
				while (tetroes[i])
				{
					ft_putstr(tetroes[i++]);
					ft_putstr("\n");
				}
				t_tetro *test = malloc(sizeof(t_tetro)*1);
				test = form_tetro(tetroes[0]);
				test = form_tetro(tetroes[1]);
				test = form_tetro(tetroes[2]);

			}
		}
		argc--;
	}
	return (0);
}
