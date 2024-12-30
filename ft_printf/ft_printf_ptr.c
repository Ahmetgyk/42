/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageyik <muhittingyk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:52:18 by ageyik            #+#    #+#             */
/*   Updated: 2024/12/21 18:23:05 by ageyik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(uintptr_t ptr, int i)
{
	if (ptr >= 16)
	{
		i = ft_put_ptr(ptr / 16, i);
		i = ft_put_ptr(ptr % 16, i);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar((ptr + '0'));
		else
			ft_putchar((ptr - 10 + 'a'));
		i++;
	}
	return (i);
}

int	ft_putptr(uintptr_t ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5 - 1);
	}
	else
	{
		write(1, "0x", 2);
		i = ft_put_ptr(ptr, i);
		return (i + 1);
	}
}
