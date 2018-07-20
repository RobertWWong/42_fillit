/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 09:45:28 by zwang             #+#    #+#             */
/*   Updated: 2018/07/20 15:50:15 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

int				count_char(int file_desc);
char			*get_data(char *file_name, char *data);
int				ft_strcount(char const *s, char c);
char			**get_tetriminoes(char *data, char **tetriminoes);
int				basic_validate(char *data);


#endif
