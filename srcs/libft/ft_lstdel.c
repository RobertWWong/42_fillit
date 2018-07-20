/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 13:11:54 by rowong            #+#    #+#             */
/*   Updated: 2018/07/16 13:11:55 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *next_ptr;

	while (*alst)
	{
		next_ptr = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = next_ptr;
	}
	alst = NULL;
}
