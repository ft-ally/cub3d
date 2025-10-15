/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:27:29 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/06/11 13:56:35 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Allocates memory for an array of 'nmemb' elements
/// of 'size' bytes each and initializes all bytes to zero.
/// @param nmemb The number of elements to allocate.
/// @param size The size of each element in bytes.
/// @return A pointer to the allocated zero-initialized memory block,
/// or NULL if the allocation fails or if the size overflows.
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	size_t	total_size;

	total_size = nmemb * size;
	if (size == 0 || nmemb == 0)
		return (malloc(1));
	dest = (void *)malloc(total_size);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, total_size);
	return (dest);
}

//int	main(void)
//{
//	int	*arr1;
//	int	*arr2;
//	int	n = 7;

//	arr1 = (int*)calloc(n, sizeof(int));
//	arr2 = (int*)ft_calloc(n, sizeof(int));

//	if (arr1 == NULL)
//	{
//		printf("Memory allocation failed!\n");
//		return (1);
//	}
//	if (arr2 == NULL)
//	{
//		printf("Memory allocation failed!\n");
//		return (1);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr1[i]);// Output: 0 0 0 0 0
//	}
//	printf("\n");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	free(arr1);
//	free(arr2);
//	return (0);
//}
