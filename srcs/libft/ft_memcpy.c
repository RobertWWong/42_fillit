/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:22:55 by rowong            #+#    #+#             */
/*   Updated: 2018/07/09 13:22:55 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (n == 0 || dst == src)
		return (dst);
	else
	{
		d = dst;
		s = src;
		while (n)
		{
			*d++ = *s++;
			n--;
		}
		return (dst);
	}
}
