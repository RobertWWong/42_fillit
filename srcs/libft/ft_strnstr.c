/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:30:23 by rowong            #+#    #+#             */
/*   Updated: 2018/07/09 13:30:25 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	iter;

	if (!*needle && !*haystack)
		return ((char *)haystack);
	if (!*needle)
		return ((char *)haystack);
	iter = 0;
	while (*haystack && iter < len)
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i] && i + iter < len)
			i++;
		if (!needle[i])
			return ((char *)haystack);
		haystack++;
		iter++;
	}
	return (NULL);
}
