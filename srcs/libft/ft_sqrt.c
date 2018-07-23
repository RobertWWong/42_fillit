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

int		ft_sqrt(int nb)
{
	int front;
	int back;
	int mid;
	int res;

	front = 1;
	back = 46341;
	res = 0;
	mid = 0;
	if (nb == 0 || nb == 1)
		return (nb);
	while (front <= back)
	{
		mid = (front + back) / 2;
		res = mid * mid;
		if (res == nb)
			return (mid);
		if (res < nb)
			front = mid + 1;
		else if (res > nb)
			back = mid - 1;
	}
	return (0);
}
