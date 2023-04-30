/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:02:47 by jdufour           #+#    #+#             */
/*   Updated: 2023/04/30 20:35:12 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putadr(unsigned long n)
{
    char    *hex;
    int size;

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

int choose_format(char *prout, va_list grosprouts)
{
    int size;
    
    size = 0;
    if (*prout == 'd' || *prout == 'i')
        size = ft_putnbr(va_arg(grosprouts, int));
    if (*prout == 'u')
        size = ft_putunsigned(va_arg(grosprouts, unsigned int));
    if (*prout == 's')
        size = ft_putstr(va_arg(grosprouts, char*));
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

int ft_printf(char *prout, ...)
{
    va_list grosprouts;
    va_start(grosprouts, prout);
    int value;

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

// int main()
// {
//     char *var = NULL;
//     int value1 = printf("salut %d ca va : %c yo : %p, %% %%,%%, %x prout %i%s%X null ? %s blablabla\n😀 😃 😄 😁 😆 😅 😂 🤣 🥲 🥹 ☺️ 😊 😇 🙂 🙃 😉 😌 😍 🥰 😘 😗 😙 😚 😋 😛 😝 😜 🤪 🤨 🧐 🤓 😎 🥸 🤩 🥳 😏 😒 😞 😔 😟 😕 🙁 ☹️ 😣 😖 😫 😩 🥺 😢 😭 😮‍💨 😤 😠 😡 🤬 🤯 😳 🥵 🥶 😱 😨 😰 😥 😓 🫣 🤗 🫡 🤔 🫢 🤭 🤫 🤥 😶 😶‍🌫️ 😐 😑 😬 🫨 🫠 🙄 😯 😦 😧 😮 😲 🥱 😴 🤤 😪 😵 😵‍💫 🫥 🤐 🥴 🤢 🤮 🤧 😷 🤒 🤕 🤑 🤠 😈 👿 👹 👺 🤡 💩 👻 💀 ☠️ 👽 👾 🤖 🎃 😺 😸 😹 😻 😼 😽 🙀 😿 😾", 10, 'a', "yo", 255, 10, "jojo", 255, var);
//     printf("\n");
//     int value2 = ft_printf("salut %d ca va : %c yo : %p, %% %%,%%, %x prout %i%s%X null ? %s blablabla\n😀 😃 😄 😁 😆 😅 😂 🤣 🥲 🥹 ☺️ 😊 😇 🙂 🙃 😉 😌 😍 🥰 😘 😗 😙 😚 😋 😛 😝 😜 🤪 🤨 🧐 🤓 😎 🥸 🤩 🥳 😏 😒 😞 😔 😟 😕 🙁 ☹️ 😣 😖 😫 😩 🥺 😢 😭 😮‍💨 😤 😠 😡 🤬 🤯 😳 🥵 🥶 😱 😨 😰 😥 😓 🫣 🤗 🫡 🤔 🫢 🤭 🤫 🤥 😶 😶‍🌫️ 😐 😑 😬 🫨 🫠 🙄 😯 😦 😧 😮 😲 🥱 😴 🤤 😪 😵 😵‍💫 🫥 🤐 🥴 🤢 🤮 🤧 😷 🤒 🤕 🤑 🤠 😈 👿 👹 👺 🤡 💩 👻 💀 ☠️ 👽 👾 🤖 🎃 😺 😸 😹 😻 😼 😽 🙀 😿 😾", 10, 'a', "yo", 255, 10, "jojo", 255, var);
//     printf("value1 = %d, value2 = %d\n", value1, value2);
// }