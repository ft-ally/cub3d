/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:15:25 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/10/21 14:22:46 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pressed_esc(t_game *game)
{
	//free everything
	ft_free_mlx(game, ESC_PRESS);
	exit(0);
}

int key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_free_mlx(game, ESC_PRESS); //add free for parsing
		exit(0);
	}
	return (SUCCESS);
}

int	init_hooks(t_game *game)
{
	mlx_key_hook(game->gfx.win, key_hook, game);
	mlx_hook(game->gfx.win, 17, 0, pressed_esc, game);
	mlx_loop(game->gfx.mlx);
	return (SUCCESS);
}

int	init_game(t_game *game)
{
	if (init_player_pos(game) != SUCCESS)
		return (ERROR);
	if (init_mlx(game) != SUCCESS)
		return (ERROR);
	color_ceiling(game);
	color_floor(game);
	mlx_put_image_to_window(game->gfx.mlx, game->gfx.win, game->gfx.image.img, 0, 0);
	if (init_hooks(game) != SUCCESS)
		return (ft_free_mlx(game, ERROR));
	return (SUCCESS);
}


//test // mlx_put_image_to_window(game->gfx.mlx, game->gfx.win, game->gfx.wall[NORTH].img, 0, 0); //test
