/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageyik <muhittingyk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:52:14 by ageyik            #+#    #+#             */
/*   Updated: 2024/12/14 16:32:59 by ageyik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(int n, int i)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		i++;
		i = ft_put_nbr(-n, i);
	}
	else if (n > 9)
	{
		i = ft_put_nbr(n / 10, i);
		i = ft_put_nbr(n % 10, i);
	}
	else
	{
		ft_putchar(48 + n);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	i = ft_put_nbr(n, i);
	return (i - 1);
}
