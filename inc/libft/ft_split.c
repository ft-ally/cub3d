/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:58:25 by tutku             #+#    #+#             */
/*   Updated: 2024/10/18 13:11:08 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// when it finds a match, it skips the repeats
// then if *str != '\0' -> counter++;
static int	count_words(char const *str, char word)
{
	int	counter;

	counter = 0;
	if (!*str)
		return (0);
	while (*str)
	{
		while (*str == word)
			str++;
		if (*str)
			counter++;
		while (*str && *str != word)
			str++;
	}
	return (counter);
}

static size_t	len_calc(char const *s, char c)
{
	size_t	len;

	if (!ft_strchr(s, c))
		len = ft_strlen(s);
	else
		len = ft_strchr(s, c) - s;
	return (len);
}

static void	*free_everything(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**words;
	int		i;

	words = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!words)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			len = len_calc(s, c);
			words[i] = ft_substr(s, 0, len);
			if (!words[i])
				return (free_everything(words, i));
			i++;
			s = s + len;
		}
	}
	words[i] = NULL;
	return (words);
}

// int main(void)
// {
// 	int j = 0;
// 	char const *s = "xHelloxxCodamxx!!x";
// 	char **result = ft_split(s, 'x');

// 	while (result[j])
// 		printf("%s\n", result[j++]);

// 	j = 0;
// 	while (result[j])
// 	{
// 		free(result[j++]);
// 	}
// 	free(result);
// 	return (0);
// }
//if (!s)
//		return (0);
