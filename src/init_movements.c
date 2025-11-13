/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:07:11 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/11/13 17:46:52 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rotations(int keycode, t_game *game)
{
	const double	old_dir_x = game->player.dir_x;
	const double	old_plane_x = game->player.plane_x;

	if (keycode == KEY_LEFT)
	{
		game->player.dir_x = game->player.dir_x * cos(-ROT_SPEED) - game->player.dir_y * sin(-ROT_SPEED);
		game->player.dir_y = old_dir_x * sin(-ROT_SPEED) + game->player.dir_y * cos(-ROT_SPEED);
		game->player.plane_x = game->player.plane_x * cos(-ROT_SPEED) - game->player.plane_y * sin (-ROT_SPEED);
		game->player.plane_y = old_plane_x * sin(-ROT_SPEED) + game->player.plane_y * cos(-ROT_SPEED);
	}
	if (keycode == KEY_RIGHT)
	{
		game->player.dir_x = game->player.dir_x * cos(ROT_SPEED) - game->player.dir_y * sin(ROT_SPEED);
		game->player.dir_y = old_dir_x * sin(ROT_SPEED) + game->player.dir_y * cos(ROT_SPEED);
		game->player.plane_x = game->player.plane_x * cos(ROT_SPEED) - game->player.plane_y * sin (ROT_SPEED);
		game->player.plane_y = old_plane_x * sin(ROT_SPEED) + game->player.plane_y * cos(ROT_SPEED);
	}
}

static void	init_w_s(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		if (game->map->map_grid[(int)(game->player.y)]
				[(int)(game->player.x + game->player.dir_x * MOVE_SPEED)] == '0')
			game->player.x += game->player.dir_x * MOVE_SPEED;
		if (game->map->map_grid[(int)(game->player.y + game->player.dir_y * MOVE_SPEED)]
				[(int)(game->player.x)] == '0')
			game->player.y += game->player.dir_y * MOVE_SPEED;
	}
	if (keycode == KEY_S)
	{
		if (game->map->map_grid[(int)(game->player.y)]
				[(int)(game->player.x - game->player.dir_x * MOVE_SPEED)] == '0')
			game->player.x -= game->player.dir_x * MOVE_SPEED;
		if (game->map->map_grid[(int)(game->player.y - game->player.dir_y * MOVE_SPEED)]
				[(int)(game->player.x)] == '0')
			game->player.y -= game->player.dir_y * MOVE_SPEED;
	}
}

static void init_a_d(int keycode, t_game *game)
{
	if (keycode == KEY_A)
	{
		if (game->map->map_grid[(int)(game->player.y)]
				[(int)(game->player.x - game->player.plane_x * MOVE_SPEED)] == '0')
			game->player.x -= game->player.plane_x * MOVE_SPEED;
		if (game->map->map_grid[(int)(game->player.y - game->player.plane_y * MOVE_SPEED)]
				[(int)(game->player.x)] == '0')
			game->player.y -= game->player.plane_y * MOVE_SPEED;
	}
	if (keycode == KEY_D)
	{
		if (game->map->map_grid[(int)(game->player.y)]
				[(int)(game->player.x + game->player.plane_x * MOVE_SPEED)] == '0')
			game->player.x += game->player.plane_x * MOVE_SPEED;
		if (game->map->map_grid[(int)(game->player.y + game->player.plane_y * MOVE_SPEED)]
				[(int)(game->player.x)] == '0')
			game->player.y += game->player.plane_y * MOVE_SPEED;
	}
}

void	init_movements(int keycode, t_game *game)
{
	init_w_s(keycode, game);
	init_a_d(keycode, game);
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
		init_rotations(keycode, game);
}
