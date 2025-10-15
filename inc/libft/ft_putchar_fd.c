/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:32:53 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/15 10:53:11 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

//int	main(void)
//{
//	ft_putchar_fd('X', 1);
//	return (0);
//}
/*
* fd == 0 -> stdin
* fd == 1 -> stdout
* fd == 2 -> stderr
*/
