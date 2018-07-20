/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:37:43 by rowong            #+#    #+#             */
/*   Updated: 2018/07/14 13:37:44 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char *new_str;

	new_str = (char*)malloc(sizeof(char) * size + 1);
	if (!new_str)
		return (NULL);
	ft_bzero((void*)new_str, size + 1);
	return (new_str);
}
