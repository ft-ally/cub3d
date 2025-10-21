/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:06:50 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/21 17:37:03 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_invalid_char(char **map, char spawn_dir)
{
	int	i;
	int	j;
	int	spawn_count;

	i = -1;
	spawn_count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!(ft_strchr("01NSEW \t", map[i][j])))
				return (print_error("Invalid character in map"));
			if ((ft_strchr("NSEW", map[i][j])))
			{
				spawn_dir = map[i][j];
				spawn_count++;
			}
		}
	}
	if (spawn_count <= 0)
		return (print_error("No spawn location found"));
	if (spawn_count > 1)
	return (print_error("Multiple spawn locations found"));
	return (SUCCESS);
}

// int	validate_walls(char **map)
// {
	
// }

int	validate_map(t_game *game)
{
	char	**map;
	
	map = game->map->map_grid; //for easier passing
	if (check_invalid_char(map, game->spawn_dir) == ERROR)
		return (ERROR);
	// if (validate_walls(map) == ERROR)
	// 	return (ERROR);
	// if (validate_walkable(map) == ERROR)
	// 	return (ERROR);
	//validate walls
	//validate walkable path
	return (SUCCESS);
}