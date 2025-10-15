/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:00:04 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/18 17:12:36 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && check(s1[start], set))
		start++;
	while ((start < end) && check(s1[end - 1], set))
		end--;
	new_str = ft_substr(s1, start, end - start);
	return (new_str);
}

//int	main(void)
//{
//	char const	*s1 = "+-++++-+*NULL*-+-+-+-";
//	char const	*set = "+-";

//	printf("%s ", ft_strtrim(s1, set));
//	printf("%s ", ft_strtrim("", "abcd"));
//	return (0);
//}
