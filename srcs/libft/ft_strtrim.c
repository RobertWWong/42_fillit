/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:24:49 by rowong            #+#    #+#             */
/*   Updated: 2018/07/13 17:24:57 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_white_sp(char *s)
{
	if (*s == ' ' || *s == '\n' || *s == '\t')
		return (1);
	return (0);
}

static	int		all_ws(const char *s)
{
	while (*s)
		if (is_white_sp((char*)s))
			s++;
		else
			return (0);
	return (1);
}

static	int		all_alpha_num(char *s)
{
	int last;

	last = ft_strlen(s) - 1;
	if (!(is_white_sp(s)) && !(is_white_sp((s + last))))
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int		front;
	int		len;
	int		back;
	int		diff;
	char	*res;

	if (!s)
		return (NULL);
	if (all_alpha_num((char*)s))
		return (ft_strdup(s));
	if (all_ws(s))
		return (ft_strdup("\0"));
	front = 0;
	while ((is_white_sp((char*)(s + front))))
		front++;
	len = front;
	while (s[len] || !(back = 1))
		len++;
	diff = s[len - back];
	while (diff == ' ' || diff == '\n' || diff == '\t')
		diff = s[len - ++back];
	if (!(res = ft_strnew((len - back) - front + 1)))
		return (NULL);
	res = ft_strncpy(res, (s + front), (len - back) - front + 1);
	return (res);
}
