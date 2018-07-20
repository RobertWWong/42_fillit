/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:37:56 by rowong            #+#    #+#             */
/*   Updated: 2018/07/14 13:37:57 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	word_count(char const *s, char delimit)
{
	int words;
	int start_del;
	int ctr;

	ctr = 0;
	start_del = 1;
	words = 0;
	if (!s || !delimit)
		return (0);
	while (s[ctr])
	{
		if (s[ctr] != delimit && start_del && s[ctr])
		{
			start_del = 0;
			words += 1;
		}
		else if (s[ctr] == delimit)
			start_del = 1;
		ctr++;
	}
	return (words);
}

static	int	next_pos(char *str, char delimt)
{
	int len;

	len = 0;
	while (*str != delimt && *str)
	{
		str++;
		len++;
	}
	return (len);
}

static char	*copy_word(char *str, size_t start, size_t len)
{
	char			*new_str;
	const	char	*ptr;

	if (!str)
		return (NULL);
	ptr = str;
	if (!(new_str = ft_strnew(len)))
		return (NULL);
	ptr += start;
	ft_strncpy(new_str, ptr, len);
	return (new_str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		total_words;

	total_words = word_count(s, c);
	if (!(res = (char**)malloc(sizeof(char*) * (total_words + 1))))
		return (NULL);
	i = -1;
	while (++i < total_words)
	{
		while (*s == c && *s)
			s++;
		res[i] = copy_word((char*)s, 0, next_pos((char*)s, c));
		if (!res[i])
			return (NULL);
		s += next_pos((char*)s, c);
	}
	res[i] = NULL;
	return (res);
}
