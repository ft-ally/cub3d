/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:21:51 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/15 17:25:38 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_extension(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (!ft_strcmp(&map_name[len - 4], ".cub"))
		return(print_error("Wrong extension!"));
	else
		return (SUCCESS);
}

int	check_valid_input(int argc, char *map_name)
{
	if (argc < 2)
		return (print_error("Choose map"));
	if (argc >2)
		return (print_error("Too many arguments, only enter map name!"));
	if (check_extension(map_name) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}