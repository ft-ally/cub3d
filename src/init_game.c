/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:15:25 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/10/20 14:04:07 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_plane_values(t_game *game, char pos)
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

void	set_dir_values(t_game *game, char pos)
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

/*
N → dir = (0, -1)
S → dir = (0, 1)
W → dir = (-1, 0)
E → dir = (1, 0)
*/
int	init_player_pos(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	map = game->map->map_grid;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
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
		y++;
	}
	return (print_error("Player not found"));
}

int	init_game(t_game *game)
{
	if (init_player_pos(game) != SUCCESS)
		return (ERROR);
	if (init_mlx(game) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

//load images here later
//put images to window here later
//mlx_key_hook(game->vis.win, key_hook, game); //add movements
//mlx_loop here later

/*
0x00RRGGBB
 ┌───────────────────────────┐  y = 0
 │         ceiling           │  → 0x0080A0D0
 │         (sky)             │
 ├───────────────────────────┤  y = HEIGHT/2
 │          floor            │  → 0x00303030
 │                           │
 └───────────────────────────┘  y = HEIGHT
*/