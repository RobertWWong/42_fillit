/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:06:04 by zwang             #+#    #+#             */
/*   Updated: 2018/07/20 10:29:15 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrimino.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*data;

	if (argc == 2)
	{
		if (!(data = get_data(argv[1], data)))
		{
			ft_putstr("Error");
			return (1);
		}
		printf("%d\n", basic_validate(data));
	}
	return (0);
}
