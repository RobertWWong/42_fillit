/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:46:33 by rowong            #+#    #+#             */
/*   Updated: 2018/07/11 16:46:33 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_len(int n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len - 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	digits[11];
	int		i;
	int		len;

	if (n < 0 && n != -2147483648)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		len = find_len(n);
		i = len;
		while (n > 0)
		{
			digits[i--] = (n % 10) + 48;
			n /= 10;
		}
		digits[len + 1] = '\0';
		ft_putstr_fd(digits, fd);
	}
}
