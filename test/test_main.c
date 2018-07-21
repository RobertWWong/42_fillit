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

#include "../includes/tetrimino.h"

int		main(int argc, char **argv)
{
	char	*data = NULL;
	char	**tetriminoes = NULL;
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
			tetriminoes = (char **)malloc(sizeof(char *) * (lines / 4 + 1));
			tetriminoes = get_tetriminoes(data, tetriminoes);
			i = 0;
			if (advanced_validate(tetriminoes))
			{
				while (tetriminoes[i])
				{
					ft_putstr(tetriminoes[i++]);
					ft_putstr("\n");
				}
				t_tetrimino *test = malloc(sizeof(t_tetrimino)*1);
				test = form_tetrimino(tetriminoes[0]);
				test = form_tetrimino(tetriminoes[1]);
				test = form_tetrimino(tetriminoes[2]);

			}
		}
		argc--;
	}
	return (0);
}
