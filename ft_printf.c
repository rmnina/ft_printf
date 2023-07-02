/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicu <jovicu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:02:47 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/03 01:54:01 by jovicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	choose_format(char *format, va_list args)
{
	int	size;

	size = 0;
	if (*format == 'd' || *format == 'i')
		size = ft_putnbr(va_arg(args, int));
	if (*format == 'u')
		size = ft_putunsigned(va_arg(args, unsigned int));
	if (*format == 's')
		size = ft_putstr(va_arg(args, char *));
	if (*format == 'c')
		size = ft_putchar(va_arg(args, int));
	if (*format == '%')
		size = ft_putchar('%');
	if (*format == 'x' || *format == 'X')
		size = ft_put_hex(va_arg(args, unsigned int), *format);
	if (*format == 'p')
	{
		size = ft_putstr("0x");
		size += ft_putadr(va_arg(args, unsigned long));
	}
	return (size);
}

int	ft_printf(char *format, ...)
{
	int		value;
	va_list	args;

	value = 0;
	va_start(args, format);
	if (format[value] == '%' && format[value + 1] == '\0')
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			value += choose_format(format++, args);
		}
		else
		{
			ft_putchar(*format);
			value++;
			format++;
		}
		if (*format == '\0')
			break;
	}
	va_end(args);
	return (value);
}
