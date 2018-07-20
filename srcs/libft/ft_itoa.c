/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:08:49 by rowong            #+#    #+#             */
/*   Updated: 2018/07/13 12:08:50 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Determine the amount of digits in a given signed integer.
static int	find_len(int n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

// Reverse the content of a string.
static char	*strrev(char *str)
{
	int i;
	int tmp;
	int len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		tmp = str[i];
		str[i++] = str[len];
		str[len--] = tmp;
	}
	return (str);
}

// Return an integer into its string representation. If memalloc fails,
// return null for checking.
char		*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*res;

	if (n == 0)
		return (ft_strcpy(ft_strnew(1), "0"));
	if ((i = 0) || n == -2147483648)
		return (ft_strcpy(ft_strnew(11), "-2147483648"));
	if ((sign = n) < 0)
		if ((n = -n) > 0)
			sign = -1;
	if (!(res = ft_strnew(find_len(n) + 1)))
		return (NULL);
	while (n > 0)
	{
		res[i++] = n % 10 + '0';
		n /= 10;
	}
	if (sign == -1 || (sign = 0))
		res[i++] = '-';
	res[i] = '\0';
	res = strrev((res));
	return (res);
}
