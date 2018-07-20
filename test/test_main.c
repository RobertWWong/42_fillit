/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:06:04 by zwang             #+#    #+#             */
/*   Updated: 2018/07/20 14:55:04 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetrimino.h"

int		main(int argc, char **argv)
{
	char	*data;
	char	**tetriminoes;
	int		i;
	int		j;

	if (argc == 2)
	{
		if (!(data = get_data(argv[1], data)))
		{
			ft_putstr("Error");
			return (1);
		}
		tetriminoes = get_tetriminoes(data, tetriminoes);
		i = 0;
		while (tetriminoes[i])
			ft_putstr(tetriminoes[i++]);
	}
	return (0);
}
