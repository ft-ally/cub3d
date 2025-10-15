/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:53:56 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/17 10:18:30 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	if (!dest && !src)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else if (d <= s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

//ft_memmove()
//int	main(void)
//{
//	int	source[5] = {1,2,3,4,4};
//	int destination[5];
//	int	source2[5] = {1,2,3,4,4};
//	int destination2[5];

//	ft_memmove(destination, source, sizeof(int)*5);
//	printf("\nResult after ft_memmove: ");
//	for(int i = 0; i < 5; i++)
//		printf("%d ", destination[i]);
//	printf("\nResult after memmove: " ); // Output: "Hello, W W!"
//	memmove(destination2, source2, sizeof(int)*5);
//	for(int i = 0; i < 5; i++)
//		printf("%d ", destination2[i]);
//	return (0);
//}
