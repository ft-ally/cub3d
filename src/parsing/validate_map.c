/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:06:50 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/21 18:50:13 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_invalid_char(char **map, t_game *game)
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
			if (!(ft_strchr("01NSEW ", map[i][j])))
				return (print_error("Invalid character in map"));
			if ((ft_strchr("NSEW", map[i][j])))
			{
				set_spawn(game, map, i, j);
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


void flood_fill( char **map, int x, int y, int width, int height)
{
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'P';
	flood_fill(map, x + 1, y, width, height);
	flood_fill(map, x - 1, y, width, height);
	flood_fill(map, x, y + 1, width, height);
	flood_fill(map, x, y - 1, width, height);
}

int	validate_walkable(t_game *g)
{
	char	**map;
	
	map = dup_map(g);
	if (!map)
		return (ERROR);
	flood_fill(map, g->spawn_x, g->spawn_y, g->map->width, g->map->height);
}

int	validate_walls(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_top_bottom(map, height - 1) == ERROR)
		return (ERROR);
	if (check_first_last(map, width - 1) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	validate_map(t_game *game)
{
	char	**map;
	
	map = game->map->map_grid; //for easier passing
	if (check_invalid_char(map, game) == ERROR)
		return (ERROR);
	// if (validate_walls(map, game->width, game->height) == ERROR)
	// 	return (ERROR);
	// if (validate_walkable(map) == ERROR)
	// 	return (ERROR);
	//validate walls
	//validate walkable path
	return (SUCCESS);
}

	//First character of every row has to be a 1
	//The last character of every row except for space has to be a 1
	//The top most row (map[0]) should only have 1s
	//The bottom most row should only have 1s