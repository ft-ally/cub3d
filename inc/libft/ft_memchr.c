/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:46:34 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/16 13:06:16 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ptr;
	unsigned char			uc;
	size_t					i;

	uc = (unsigned char)c;
	ptr = s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == uc)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (0);
}
// ft_memchr()
//int	main(void)
//{
//	const char c[] = "abc1d1234";
//	char *result = memchr(c, '1', sizeof(c));
//	char *result2 = ft_memchr(c, '1', sizeof(c));
//	printf("Found character: %c at position: %ld\n", *result, result - c);
//	printf("Found character: %c at position: %ld\n", *result2, result2 - c);
//	return(0);
//}
