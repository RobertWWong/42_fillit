#include "../includes/ft_fillit.h"
#include "../includes/libft.h"

#include "../includes/tetrimino.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*data;

	data = NULL;
	if (argc == 2)
	{
		if (!(data = get_data(argv[1], data)))
		{
			ft_putstr("Error");
			return (1);
		}
		printf("%d\n", basic_validate(data));
	}
	printf("oh yes");
	return (0);
}
