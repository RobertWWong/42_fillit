/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:36:21 by rowong            #+#    #+#             */
/*   Updated: 2018/01/13 16:04:54 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_sqrt(int	num)
{
	int racine;
	int sqrt;

	racine = 1;
	sqrt = 0;
	while (racine <= num / 2)
	{
		sqrt = racine * racine;
		if (sqrt == num)
		{
			return (racine);
		}
		racine = racine + 1;
	}
	return (0);

}
