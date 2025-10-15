/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:54:59 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/15 10:27:52 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// int main(void)
// {
// 	char c = '2';
// 	printf("%d\n", ft_isalnum(c));
// 	char c = 'A';
// 	printf("%d", ft_isalnum(c));
// 	return (0);
// }
