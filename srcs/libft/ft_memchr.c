/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:22:28 by rowong            #+#    #+#             */
/*   Updated: 2018/07/09 13:22:29 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *first;

	if (n != 0)
	{
		first = (unsigned char*)s;
		while (n--)
		{
			if (*first == (unsigned char)c)
				return ((void*)first);
			first++;
		}
	}
	return (NULL);
}
