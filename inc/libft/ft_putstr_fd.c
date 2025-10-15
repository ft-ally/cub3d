/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:46:08 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/15 10:58:11 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

//int	main(void)
//{
//	char	*s = "HELLO WORLD!";

//	ft_putstr_fd(s, 1);
//	return (0);
//}
/*
* fd == 0 -> stdin
* fd == 1 -> stdout
* fd == 2 -> stderr
*/
