/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:25:15 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/06/18 21:31:49 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Compares two null-terminated strings lexicographically.
 *
 * Iterates through both strings character by character.
 * 
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @return An integer indicating the result:
 *         - 0  if the strings are equal,
 *         - >0 if the first non-matching character in str1 
 *              has a greater ASCII value than in str2,
 *         - <0 if the first non-matching character in str1 
 *              has a lower ASCII value than in str2.
 */
int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}
