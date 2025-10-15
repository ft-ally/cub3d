/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:45:45 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/12/17 15:05:03 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(va_list args, const char format)
{
	int		len;

	len = 0;
	if (format == '%')
		len += ft_putchar_len((char)format);
	else if (format == 'c')
		len += ft_putchar_len(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr_len(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len += ft_itoa_printf(va_arg(args, int));
	else if (format == 'p')
		len += ft_conv_hex(va_arg(args, unsigned long long));
	else if (format == 'x' || format == 'X')
		len += ft_conv_hex_x(va_arg(args, unsigned int), format);
	else if (format == 'u')
		len += ft_unsigned(va_arg(args, unsigned int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_format(args, str[i]);
		}
		else
			len += ft_putchar_len(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

//#include <stdio.h>
// int	main(void)
// {
// 	char	*fmt = "char:%c\nint:%d\nstring:%s\npointer:%p\n
//	pointer2:%p\nx:%x\nX:%X\ni hex:%i\ni octal:%i\nu: %u";
// 	char	c = '!';
// 	int		i = 0;
// 	int		*p = 0;
// 	unsigned int num = -55;

// 	printf("\n\nlen is: %d\n\n", ft_printf(fmt, c, i, "", p, 
//p, i, i, 0x15, 015, num));
// 	printf("\n\nlen is: %d\n\n", printf("char:%c\nint:%d\n
//	string:%s\npointer:%p\npointer2:%p\nx:%x\nX:%X\ni hex:%i\n
//	i octal:%i\nu: %u", c, i, "", p, p, i, i, 0x15, 015, num));
// 	return (0);
// }
