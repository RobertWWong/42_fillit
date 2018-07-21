/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 09:45:28 by zwang             #+#    #+#             */
/*   Updated: 2018/07/21 15:31:17 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>

int						count_char(int file_desc);
char					*get_data(char *file_name, char *data);
int						ft_strcount(char const *s, char c);
char					**get_tetriminoes(char *data, char **tetriminoes);
int						basic_validate(char *data);
int						advanced_validate(char **tetriminoes);	//not used within data checker

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

/*
struct will have height and width to help with board size
it also contains an array of points, detailing it's location and shape to be
no idea why we have a pointer to another tetrimino
*/
typedef struct			s_tetrimino
{
	int					height;
	int					width;
	t_point				points[4];
	// t_point			*upper;
	// t_point			*lower;
	// t_point			*left;
	// t_point			*right;
	struct s_tetrimino	*next;
}						t_tetrimino;

#endif
