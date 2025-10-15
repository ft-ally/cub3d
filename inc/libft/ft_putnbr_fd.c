/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:03:40 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/16 11:35:48 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num < 10)
		ft_putchar_fd('0' + num, fd);
	else if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
}

//int	main(void)
//{
//	int	nb;

//	nb = 2147483647;
//	ft_putnbr_fd(nb, 1);
//	ft_putchar_fd('\n', 1);

//	nb = -2147483648;
//	ft_putnbr_fd(nb, 1);
//	ft_putchar_fd('\n', 1);

//	nb = 0;
//	ft_putnbr_fd(nb, 1);
//	return (0);
//}
