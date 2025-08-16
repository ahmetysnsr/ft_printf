/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:25:11 by asari             #+#    #+#             */
/*   Updated: 2025/08/16 18:18:49 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_putnbr_hex_ptr(size_t n)
{
	char	*base;
	int		count;
	int		temp;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		temp = ft_putnbr_hex_ptr(n / 16);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	temp = ft_putchar(base[n % 16]);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;
	int	temp;

	count = 0;
	if (!ptr)
	{
		temp = ft_putstr("(nil)");
		if (temp == -1)
			return (-1);
		count += temp;
	}
	else
	{
		temp = ft_putstr("0x");
		if (temp == -1)
			return (-1);
		count += temp;
		temp = ft_putnbr_hex_ptr((size_t)ptr);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count);
}
