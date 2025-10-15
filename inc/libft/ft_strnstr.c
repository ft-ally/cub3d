/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:36:45 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/10 15:08:47 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if little is empty -> return big
//if little occurs nowhere in big -> return NULL
//else return a pointer to the first char of the first occurrence of little

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (little[j] != '\0' && big[i + j] == little[j]
				&& (i + j) < len)
			{
				j++;
			}
			if (little[j] == '\0')
			{
				return ((char *)(big + i));
			}
		}
		i++;
	}
	return (NULL);
}

//int	main(void)
//{
//	char	*big = "Hello World!";
//	char	*little = "orl";
//	char	*ptr1 = ft_strnstr(big, little, strlen(big));

//	printf("ft: %s\n", ptr1);
//	return (0);
//}
