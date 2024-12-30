/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageyik <muhittingyk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:52:30 by ageyik            #+#    #+#             */
/*   Updated: 2024/12/21 17:34:19 by ageyik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(va_list ag, const char format)
{
	int	n;

	n = 0;
	if (format == 'c')
		n += ft_putchar(va_arg(ag, int));
	else if (format == 's')
		n += ft_putstr(va_arg(ag, char *));
	else if (format == 'p')
		n += ft_putptr(va_arg(ag, uintptr_t));
	else if (format == 'd' || format == 'i')
		n += ft_putnbr(va_arg(ag, int));
	else if (format == 'u')
		n += ft_putunsigned(va_arg(ag, unsigned int));
	else if (format == 'x' || format == 'X')
		n += ft_puthex(va_arg(ag, unsigned int), format);
	else if (format == '%')
		n += ft_putchar('%');
	return (n - 1);
}

int	ft_printf(char const *str, ...)
{
	va_list	ag;
	int		i;
	int		n;

	va_start(ag, str);
	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
		}
		else
		{
			n += ft_conversion(ag, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(ag);
	return (n + i);
}
