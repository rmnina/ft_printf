/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:30:33 by jdufour           #+#    #+#             */
/*   Updated: 2023/04/30 20:04:40 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_putchar(char c);
int ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int n);
int ft_put_hex(unsigned int n, char c);
int ft_putadr(unsigned long n);
int ft_printf(char *prout, ...);
int choose_format(char *prout, va_list grosprouts);

#endif