/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:24:19 by zwang             #+#    #+#             */
/*   Updated: 2018/07/24 16:41:48 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/file_ops.h"

int		main(int argc, char **argv)
{
	char	*s = "....\n....\n..##\n..##\n\n..#.\n..#.\n.##.\n....\n\n";
	

	printf("%d\n", basic_validate(s));

	return (0);
}
