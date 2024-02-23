/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:17:40 by nsalles           #+#    #+#             */
/*   Updated: 2023/10/24 01:57:07 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		return (ft_putchar(n + '0') + i);
	return (i);
}

int	ft_printf_switch(va_list arg, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(arg, unsigned long long)));
	if (c == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(arg, unsigned int)));
	if (c == 'x')
		return (ft_putlohexa(va_arg(arg, unsigned int)));
	if (c == 'X')
		return (ft_putuphexa(va_arg(arg, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i])
		{
			i += ft_putchar(str[i]);
			len++;
		}
		if (str[i] == '%')
		{
			i++;
			len += ft_printf_switch(arg, str[i]);
			i++;
		}
	}
	va_end(arg);
	return (len);
}
