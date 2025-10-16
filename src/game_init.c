/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:15:25 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/10/16 14:00:13 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_mlx(t_game *game, int error_type)
{
	if (error_type == WIN_FAIL)
	{
		mlx_destroy_display(game->gfx.mlx);
		free(game->gfx.mlx);
	}
	else if (error_type == ESC)
	{
		mlx_destroy_window(game->gfx.mlx, game->gfx.win);
		mlx_destroy_image(game->gfx.mlx, game->textures->east);
		mlx_destroy_image(game->gfx.mlx, game->textures->north);
		mlx_destroy_image(game->gfx.mlx, game->textures->south);
		mlx_destroy_image(game->gfx.mlx, game->textures->west);
	}
}

int	init_mlx(t_game *game)
{
	char *buffer; //test

	game->gfx.mlx = malloc(sizeof(t_gfx));
	if (!game->gfx.mlx)
		return (print_error("Error allocating memory for mlx"));
	game->gfx.mlx = mlx_init();
	if (!game->gfx.mlx)
		return (free(game->gfx.mlx), print_error("Error initializing mlx"));
	game->gfx.win = mlx_new_window(game->gfx.mlx, WIDTH, HEIGHT, "Cub3D"); //fix later
	if (!game->gfx.win)
		return (free(game->gfx.mlx), print_error("Error creating window"));


	game->gfx.image.img = mlx_new_image(game->gfx.mlx, WIDTH, HEIGHT);
	buffer = mlx_get_data_addr(game->gfx.image.img, &game->gfx.image.bits_per_pixel,
				&game->gfx.image.line_len, &game->gfx.image.endian);

	//img.img = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len,
	//			&img.endian);
	mlx_loop(game->gfx.mlx);
	return (SUCCESS);
}

int	init_game(t_game *game)
{
	if (init_mlx(game) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

//load images here later
//put images to window here later
//mlx_key_hook(game->vis.win, key_hook, game); //add movements
//mlx_loop here later