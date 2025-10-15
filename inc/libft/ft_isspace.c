/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:39:08 by tutku             #+#    #+#             */
/*   Updated: 2025/05/06 15:48:36 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief checks if the character is a space
/// @return returns 1 if it is a space, 0 if not 
int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}
