/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:58:08 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/12/17 15:06:58 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// for %x and %X
int	ft_conv_hex_x(unsigned int dec, char c)
{
	int	len;

	len = 0;
	if (dec == 0)
		return (ft_putstr_len("0"));
	if (dec >= 16)
	{
		len += ft_conv_hex_x(dec / 16, c);
		len += ft_conv_hex_x(dec % 16, c);
	}
	else
	{
		if (dec < 10)
			len += ft_putchar_len(dec + '0');
		else
		{
			if (c == 'x')
				len += ft_putchar_len(dec - 10 + 'a');
			if (c == 'X')
				len += ft_putchar_len(dec - 10 + 'A');
		}
	}
	return (len);
}

int	ft_conv_ptr(uintptr_t dec)
{
	int	len;

	len = 0;
	if (dec >= 16)
	{
		len += ft_conv_ptr(dec / 16);
		len += ft_conv_ptr(dec % 16);
	}
	else
	{
		if (dec < 10)
			len += ft_putchar_len(dec + '0');
		else
			len += ft_putchar_len ((dec - 10 + 'a'));
	}
	return (len);
}

// for %p to print address
int	ft_conv_hex(unsigned long long dec)
{
	int	len;

	len = 0;
	if (dec == 0)
		len = ft_putstr_len("(nil)");
	else
	{
		len = ft_putstr_len("0x");
		len += ft_conv_ptr(dec);
	}
	return (len);
}

// for %u
int	ft_unsigned(unsigned int num)
{
	int		len;

	len = 0;
	if (num < 10)
	{
		len += ft_putchar_len(num + '0');
	}
	else
	{
		len += ft_itoa_printf(num / 10);
		len += ft_putchar_len((num % 10) + '0');
	}
	return (len);
}
