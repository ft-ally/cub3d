/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:12:50 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/16 19:23:25 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The  memcmp()  function compares the first n bytes (each interpreted as
// unsigned char) of the memory areas s1 and s2.
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
		{
			return (((unsigned char)str1[i]) - ((unsigned char)str2[i]));
		}
		i++;
	}
	return (0);
}
