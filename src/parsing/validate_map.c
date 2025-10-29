/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:06:50 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/29 14:21:28 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_invalid_char(char **map, t_game *game)
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
			if (!(ft_strchr("01NSEWD ", map[i][j])))
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

static int	check_valid_floor(char **map, int width, int height)
{
	int i;
	int j;

	i = 0;
	if (width <= 2 || height <= 2)
		return (print_error("Map too small"));
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] != ' ' && map[i][j] != '1')
			{
				if (map[i + 1][j] == ' ' || map[i - 1][j] == ' '
					|| map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
						return (print_error("Out of bounds!"));
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	validate_walls(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_top_bottom(map, height) == ERROR)
		return (ERROR);
	if (check_first_last(map, width) == ERROR)
		return (ERROR);
	if (check_valid_floor(map, width, height) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	validate_map(t_game *game)
{
	char	**map;
	
	map = game->map->map_grid; //for easier passing
	if (check_invalid_char(map, game) == ERROR)
		return (ERROR);
	if (validate_walls(map, game->map->width, game->map->height) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

