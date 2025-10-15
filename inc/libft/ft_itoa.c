/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:51:41 by tutku             #+#    #+#             */
/*   Updated: 2025/03/25 16:27:30 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_num_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

/// @brief Convert int into a string
/// @param n number to be converted
/// @return null terminated string
char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	num;

	num = n;
	len = calc_num_len(num);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	result[len--] = '\0';
	if (num < 0)
	{
		result[0] = '-';
		num *= -1;
	}
	if (num == 0)
		result[0] = '0';
	while (num != 0)
	{
		result[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}

// int main(void)
// {
// 	int num;

// 	num = -12345;
// 	printf("digit amount %d\n", calc_num_len((long)num));
// 	printf("result: %s", ft_itoa(num));
// 	return (0);
// }
