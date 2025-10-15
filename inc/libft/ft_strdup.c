/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:29:51 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/11 19:28:55 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*str;
	int		i;

	len = 0;
	while (s[len] != '\0')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

//int	main(void)
//{
//	const char	*str;
//	const char	*lib;
//	const char	*ft;

//	str = "CODAAM!";
//	lib = strdup(str);
//	ft = ft_strdup(str);
//	printf("Lib: %s\nft: %s\n", lib, ft);
//	return (0);
//}
