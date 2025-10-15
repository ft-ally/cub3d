/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:51:14 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/05/12 19:11:47 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Concatenates two strings into a newly allocated string.
/// @param s1 The prefix string. Can be NULL (treated as empty).
/// @param s2 The suffix string. Can be NULL (treated as empty).
/// @return A pointer to the newly created string,
// or NULL if the allocation fails.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i++] = s2[j];
		j++;
	}
	new_str[i] = '\0';
	if (!s1 && !s2)
		return (NULL);
	return (new_str);
}

//int	main(void)
//{
//	char const	*s1;
//	char const	*s2;
//	char		*result;

//	s1 = "Hello ";
//	s2 = "World!";
//	result = ft_strjoin(s1, s2);
//	printf("%s\n", result);
//	return (0);
//}
