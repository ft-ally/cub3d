/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:25:37 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 15:27:38 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_rgb_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]) && str[i] != ',')
			return (print_error("Invalid character on RGB"));
		i++;
	}
	return (SUCCESS);
}

static int	assign_rgb_to_struct(t_game *game, char *id, char **rgb_array)
{
	long	r;
	long	g;
	long	b;

	r = ft_atoi(rgb_array[0]);
	g = ft_atoi(rgb_array[1]);
	b = ft_atoi(rgb_array[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255
		|| b < 0 || b > 255)
		return (print_error("Invalid RGB identifier"));
	if (ft_strcmp(id, "F") == 0)
	{
		game->floor.r = r;
		game->floor.g = g;
		game->floor.b = b;
	}
	else
	{
		game->ceiling.r = r;
		game->ceiling.g = g;
		game->ceiling.b = b;
	}
	return (SUCCESS);
}

int	get_rgb(t_game *game, char *rgb_string, char *id)
{
	char	**rgb_array;
	int		i;

	i = 0;
	if (validate_rgb_string(rgb_string) == ERROR)
		return (ERROR);
	rgb_array = ft_split(rgb_string, ',');
	if (!rgb_array || !rgb_array[0] || !rgb_array[1]
		|| !rgb_array[2] || rgb_array[3])
	{
		free_array(rgb_array);
		return (print_error("RGB error"));
	}
	if (assign_rgb_to_struct(game, id, rgb_array) == ERROR)
		return (free_array(rgb_array), ERROR);
	free_array(rgb_array);
	return (SUCCESS);
}
