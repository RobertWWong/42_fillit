/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 09:45:28 by zwang             #+#    #+#             */
/*   Updated: 2018/07/21 11:53:37 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H
# define LEFT [0,-1]
# define RIGHT [0,1]
# define UP [-1, 0]
# define DOWN [1,0]
# define DIR [LEFT, RIGHT, UP, DOWN]

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

typedef struct			s_vertex
{
	int					x;
	int					y;
}						t_vertex;

typedef struct			s_tetrimino
{
	int					height;
	int					width;
	t_vertex			*upper;
	t_vertex			*lower;
	t_vertex			*left;
	t_vertex			*right;
	struct s_tetrimino	*next;
}						t_tetrimino;

#endif
