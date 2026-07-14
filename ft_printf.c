/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:15:26 by asari             #+#    #+#             */
/*   Updated: 2025/08/16 18:26:53 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	format_handler(char s, va_list args)
{
	if (s == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s == 'd' || s == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (s == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (s == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 0));
	else if (s == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 1));
	else if (s == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (s == '%')
		return (ft_putchar('%'));
	else
	{
		if (ft_putchar('%') == -1)
			return (-1);
		else if (ft_putchar(s) == -1)
			return (-1);
		return (2);
	}
}

static int	ft_printf_loop(const char *str, va_list args)
{
	int	print_len;
	int	temp;

	print_len = 0;
	while (*str)
	{
		temp = 1;
		if (*str == '%')
		{
			if (!*++str)
				return (-1);
			temp = format_handler(*str, args);
		}
		else
			temp = ft_putchar(*str);
		if (temp == -1)
			return (-1);
		print_len += temp;
		str++;
	}
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_len;

	if (!str)
		return (-1);
	va_start(args, str);
	print_len = ft_printf_loop(str, args);
	va_end(args);
	return (print_len);
}
