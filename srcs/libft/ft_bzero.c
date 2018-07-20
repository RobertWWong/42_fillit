/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:20:10 by rowong            #+#    #+#             */
/*   Updated: 2018/07/09 13:20:12 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Takes an string and zero out its bits. Good for ensuring an empty string.
void			ft_bzero(void *s, size_t n)
{
	char *p;

	p = s;
	while (n != 0)
	{
		*p++ = 0;
		n--;
	}
}
