/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageyik <muhittingyk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:52:10 by ageyik            #+#    #+#             */
/*   Updated: 2024/12/14 16:32:56 by ageyik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned int n, const char format, int i)
{
	if (n >= 16)
	{
		i = ft_put_hex(n / 16, format, i);
		i = ft_put_hex(n % 16, format, i);
	}
	else
	{
		if (n <= 9)
			ft_putchar((n + '0'));
		else
		{
			if (format == 'x')
				ft_putchar((n - 10 + 'a'));
			if (format == 'X')
				ft_putchar((n - 10 + 'A'));
		}
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned int n, const char format)
{
	int	i;

	i = 0;
	i = ft_put_hex(n, format, i);
	return (i - 1);
}
