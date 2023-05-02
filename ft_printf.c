/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:02:47 by jdufour           #+#    #+#             */
/*   Updated: 2023/05/02 23:17:34 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putadr(unsigned long n)
{
	char	*hex;
	int		size;

	hex = "0123456789abcdef";
	size = 0;
	if (n < 16)
		size += ft_putchar(hex[n]);
	else if (n > 15)
	{
		size += ft_putadr(n / 16);
		size += ft_putadr(n % 16);
	}	
	return (size);
}

int	choose_format(char *prout, va_list grosprouts)
{
	int	size;

	size = 0;
	if (*prout == 'd' || *prout == 'i')
		size = ft_putnbr(va_arg(grosprouts, int));
	if (*prout == 'u')
		size = ft_putunsigned(va_arg(grosprouts, unsigned int));
	if (*prout == 's')
		size = ft_putstr(va_arg(grosprouts, char *));
	if (*prout == 'c')
		size = ft_putchar(va_arg(grosprouts, int));
	if (*prout == '%')
		size = ft_putchar('%');
	if (*prout == 'x' || *prout == 'X')
		size = ft_put_hex(va_arg(grosprouts, unsigned int), *prout);
	if (*prout == 'p')
	{
		size = ft_putstr("0x");
		size += ft_putadr(va_arg(grosprouts, unsigned long));
	}
	return (size);
}

int	ft_printf(char *prout, ...)
{
	int		value;
	va_list	grosprouts;

	va_start(grosprouts, prout);
	value = 0;
	while (*prout)
	{
		if (*prout == '%')
		{
			prout++;
			value += choose_format(prout++, grosprouts);
		}
		else
		{
			ft_putchar(*prout);
			value++;
			prout++;
		}
	}
	return (value);
}
