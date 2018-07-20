/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:22:35 by rowong            #+#    #+#             */
/*   Updated: 2018/07/09 13:22:36 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char p1;
	unsigned char p2;

	while (n--)
	{
		p1 = *(unsigned char*)s1++;
		p2 = *(unsigned char*)s2++;
		if (p1 != p2)
			return ((p1 - p2));
	}
	return (0);
}
