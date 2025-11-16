/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:35:01 by tutku             #+#    #+#             */
/*   Updated: 2025/11/16 13:43:26 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
N → dir = (0, -1)
S → dir = (0, 1)
W → dir = (-1, 0)
E → dir = (1, 0)
*/
static void	set_plane_values(t_game *game, char pos)
{
	if (pos == 'N')
	{
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	if (pos == 'S')
	{
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	if (pos == 'W')
	{
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
	if (pos == 'E')
	{
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
}

static void	set_dir_values(t_game *game, char pos)
{
	if (pos == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	if (pos == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	if (pos == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	if (pos == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
}

int	init_player_pos(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	map = game->map->map_grid;
	y = -1;
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				game->player.x = x + 0.5;
				game->player.y = y + 0.5;
				set_dir_values(game, map[y][x]);
				set_plane_values(game, map[y][x]);
				map[y][x] = '0';
				return (SUCCESS);
			}
			x++;
		}
	}
	return (print_error("Player not found"));
}
