/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:36:05 by rowong            #+#    #+#             */
/*   Updated: 2018/07/20 15:10:05 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char *tmp;

	tmp = dest;
	while (len > 0 && *src != '\0')
	{
		*tmp++ = *src++;
		--len;
	}
	while (len > 0)
	{
		*tmp++ = '\0';
		--len;
	}
	return (dest);
}
