/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageyik <muhittingyk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:51:43 by ageyik            #+#    #+#             */
/*   Updated: 2024/12/21 18:27:35 by ageyik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	ft_conversion(va_list ag, const char format);
int	ft_putunsigned(unsigned int n);
int	ft_put_unsigned(unsigned int n, int i);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_putptr(uintptr_t ptr);
int	ft_put_ptr(uintptr_t ptr, int i);
int	ft_putnbr(int n);
int	ft_put_nbr(int n, int i);
int	ft_puthex(unsigned int n, const char format);
int	ft_put_hex(unsigned int n, const char format, int i);

#endif
