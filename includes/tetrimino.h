/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 09:45:28 by zwang             #+#    #+#             */
/*   Updated: 2018/07/20 09:58:03 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		count_char(int file_desc);
char	*get_data(char *file_name, char *data);
int		basic_validate(char *data);



#endif
