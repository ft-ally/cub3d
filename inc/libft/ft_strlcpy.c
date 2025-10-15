/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:58:36 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/06/18 17:11:03 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies a string to a destination buffer, ensuring null-termination.
/// @param dest The destination buffer where the string will be copied.
/// @param src The source NUL-terminated string to be copied.
/// @param size The size of the destination buffer.
/// @return The total length of the source string `src`. If the return value
///         is greater than or equal to `size`, truncation occurred.
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (!dest || !src)
		return (0);
	if (size == 0)
		return (src_len);
	if (size == 1)
		dest[0] = '\0';
	while (src[i] != '\0' && (i < size - 1) && (size > 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

//int	main(void)
//{
//	char	dest[15];
//	//char	dest2[15];
//	const char *src = "aasdjj;s;sa";

//	printf("ft: %zu\n", ft_strlcpy(dest, src, 15));
//	//printf("function: %d", strlcpy(dest2, src, 100));
//	return (0);
//}
