#ifndef FILE_OPS_H
# define FILE_OPS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

char					*get_data(char *file_name, char *data);
char					**get_tetroes(char *data, char **tetroes);
int						basic_validate(char *data);
int						advanced_validate(char **tetroes);	//not used within data checker

#endif
