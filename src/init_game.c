/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:15:25 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/11/18 17:06:42 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pressed_esc(t_game *game)
{
	//TODO: free everything
	ft_free_mlx(game, ESC_PRESS);
	free_all(game);
	exit(0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_free_mlx(game, ESC_PRESS);
		free_all(game);
		exit(0);
	}
	init_movements(keycode, game);
	return (SUCCESS);
}

/// 1. draw ceiling+floor
/// 2. run DDA for each x column to draw walls
int	render_frame(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	color_ceiling(game);
	color_floor(game);
	if (init_dda(game) != SUCCESS)
		return (ft_free_mlx(game, ESC_PRESS), free_all(game), ERROR); //TODO: add free
	mlx_put_image_to_window(game->gfx.mlx, game->gfx.win,
		game->gfx.image.img, 0, 0);
	return (SUCCESS);
}

int	init_hooks(t_game *game)
{
	mlx_key_hook(game->gfx.win, key_hook, game);
	mlx_hook(game->gfx.win, 17, 0, pressed_esc, game);
	mlx_loop_hook(game->gfx.mlx, render_frame, game);
	return (SUCCESS);
}

int	init_game(t_game *game)
{
	if (init_player_pos(game) != SUCCESS)
		return (ERROR);
	if (init_mlx(game) != SUCCESS)
		return (ERROR);
	if (init_hooks(game) != SUCCESS)
		return (ft_free_mlx(game, ERROR), free_all(game), ERROR); //TODO: add free
	mlx_loop(game->gfx.mlx);
	return (SUCCESS);
}
