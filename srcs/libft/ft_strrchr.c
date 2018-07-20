/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:31:19 by rowong            #+#    #+#             */
/*   Updated: 2018/07/09 13:31:22 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*p;
	const char	*last;

	if (c == '\0')
		return (ft_strchr(s, '\0'));
	last = NULL;
	while ((p = ft_strchr(s, (unsigned char)c)) != NULL)
	{
		last = p;
		s = p + 1;
	}
	return ((char*)last);
}
