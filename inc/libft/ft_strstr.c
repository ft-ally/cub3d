/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:36:06 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/07/04 13:09:37 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calc_size(char *c)
{
	int	size;

	size = 0;
	while (c[size] != '\0')
	{
		size++;
	}
	return (size);
}

/// @brief strstr() func. shall locate the first occurrence of to_find in str
/// @param str pointer to the null-terminated byte string to examine
/// @param to_find pointer to the null-terminated byte string to search for
/// @return if successfull a pointer to the located string
/// or a null pointer if the string is not found
/// If to_find points to a string with zero length,
/// the function shall return str
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		counter = calc_size(to_find);
		while (counter >= 0 && (str[i + j] == to_find[j]))
		{
			counter--;
			j++;
		}
		i++;
		if (counter == 0)
			return (str + i - 1);
		counter = 0;
	}
	return (0);
}
