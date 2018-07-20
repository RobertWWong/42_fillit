/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:37:01 by rowong            #+#    #+#             */
/*   Updated: 2018/07/09 13:37:02 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	char			*d;
	const char		*s;
	size_t			n;
	unsigned int	dlen;

	d = dest;
	s = src;
	n = dstsize;
	while (n-- != 0 && *d != 0)
		d++;
	dlen = d - dest;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_getlen(s));
	while (*s != 0)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
