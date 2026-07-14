/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:14:35 by asari             #+#    #+#             */
/*   Updated: 2025/08/04 19:39:04 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		if (write(1, &str[i++], 1) == -1)
			return (-1);
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		count;
	int		temp;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (-1 == ft_putchar('-'))
			return (-1);
		nb *= -1;
		count++;
	}
	if (nb >= 10)
	{
		temp = ft_putnbr(nb / 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	temp = ft_putchar(nb % 10 + '0');
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;
	int	temp;

	count = 0;
	if (n >= 10)
	{
		temp = ft_putnbr_unsigned(n / 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	temp = ft_putchar(n % 10 + '0');
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}

int	ft_putnbr_hex(unsigned int n, int uppercase)
{
	char	*base;
	int		count;
	int		temp;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		temp = ft_putnbr_hex(n / 16, uppercase);
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
