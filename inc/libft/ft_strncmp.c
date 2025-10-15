/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:17:08 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/02/12 18:41:24 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief compares at most a specified number of characters
/// @param s1 first string to be compared
/// @param s2 second string to be compared
/// @param n refers to max num of characters to be compared
/// @return s1<s2(-), s1>s2(+), s1=s2(0)
int	ft_strncmp(const char *s1, const char *s2, size_t	n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
