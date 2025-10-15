/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:57:13 by tutku             #+#    #+#             */
/*   Updated: 2024/10/15 10:24:59 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// void plus_one(unsigned int index, char *s)
// {
// 	(void)index;
// 	*s = *s + 1;
// }

// int main(void)
// {
// 	char s[] = "abc";
// 	ft_striteri(s, plus_one);
// 	printf("%s", s);
// 	return (0);
// }
