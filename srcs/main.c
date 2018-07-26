/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:24:19 by zwang             #+#    #+#             */
/*   Updated: 2018/07/25 14:55:10 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		check_tetro(char *tetro);
int		basic_validate(char *data);
int		advanced_validate(char **tetroes);

int		main()
{
	char	*s = "....\n.#..\n.###\n....\n\n....\n....\n..##\n..##\n\n..#.\n..#.\n..#.\n..#.\n";

	printf("%d\n", basic_validate(s));
	return (0);
}
