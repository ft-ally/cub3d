/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:40:06 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/12/17 15:07:13 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_itoa_printf(int n)
{
	long	num;
	int		len;

	num = n;
	len = 0;
	if (num < 0)
	{
		len += ft_putchar_len('-');
		num = -num;
	}
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
