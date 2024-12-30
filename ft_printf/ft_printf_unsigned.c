/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageyik <muhittingyk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:52:26 by ageyik            #+#    #+#             */
/*   Updated: 2024/12/14 16:33:06 by ageyik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned(unsigned int n, int i)
{
	char	c;

	if (n > 9)
	{
		i = ft_put_unsigned(n / 10, i);
		i = ft_put_unsigned(n % 10, i);
	}
	else
	{
		c = 48 + n;
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	ft_putunsigned(unsigned int n)
{
	int	i;

	i = 0;
	i = ft_put_unsigned(n, i);
	return (i - 1);
}
