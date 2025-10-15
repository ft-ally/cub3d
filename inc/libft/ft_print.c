/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:03:09 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/12/17 15:04:52 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_len(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr_len(char *s)
{
	if (s == NULL)
		return (ft_putstr_len("(null)"));
	return (write(1, s, ft_strlen(s)));
}
