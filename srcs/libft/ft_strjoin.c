/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:40:27 by rowong            #+#    #+#             */
/*   Updated: 2018/07/12 16:40:55 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	total;

	if (!s1 || !s2)
		return (NULL);
	total = ft_getlen(s1) + ft_getlen(s2);
	new = ft_strnew(total);
	if (!new)
		return (NULL);
	new = ft_strcat(new, s1);
	new = ft_strcat(new, s2);
	new[total] = '\0';
	return (new);
}
