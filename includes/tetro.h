/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 09:45:28 by zwang             #+#    #+#             */
/*   Updated: 2018/07/22 20:09:29 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRO_H
# define TETRO_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

/*
struct will have height and width to help with board size
it also contains an array of points, detailing it's location and shape to be
no idea why we have a pointer to another tetro

NEED TO FREE tetro SOMETIME IN LIFE
*/
typedef struct			s_tetro
{
	t_point				points[4];
}						t_tetro;


t_tetro					*form_tetro(char *tetro);
int						free_tetro(t_tetro *tetro);
void 					print_tetro(t_tetro *tetro);

#endif
