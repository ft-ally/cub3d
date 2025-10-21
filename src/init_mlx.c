/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:47:42 by tutku             #+#    #+#             */
/*   Updated: 2025/10/21 14:23:27 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// 1.load the image and capture its width/height
/// 2.get pixel buffer info
static int	load_xpm_files(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->gfx.wall[i].img = mlx_xpm_file_to_image(game->gfx.mlx,
			game->textures[i], &game->gfx.wall[i].w, &game->gfx.wall[i].h);
		if (!game->gfx.wall[i].img)
			return (free_loaded_textures(game, i, ERROR));
		game->gfx.wall[i].addr = mlx_get_data_addr(game->gfx.wall[i].img, &game->gfx.wall[i].bpp,
			&game->gfx.wall[i].line_len, &game->gfx.wall[i].endian);
		if (!game->gfx.wall[i].addr)
		{
			mlx_destroy_image(game->gfx.mlx, game->gfx.wall[i].img);
			return (free_loaded_textures(game, i, ERROR));
		}
		i++;
	}
	return (SUCCESS);
}

int	init_mlx(t_game *game)
{
	game->gfx.mlx = mlx_init();
	if (!game->gfx.mlx)
		return (free(game->gfx.mlx), print_error("Error initializing mlx"));
	game->gfx.win = mlx_new_window(game->gfx.mlx, WIDTH, HEIGHT, "Cub3D"); //fix later
	if (!game->gfx.win)
		return (ft_free_mlx(game, WIN_FAIL));
	// load_xpm_files(game);
	game->gfx.image.img = mlx_new_image(game->gfx.mlx, WIDTH, HEIGHT);
	game->gfx.image.addr = mlx_get_data_addr(
		game->gfx.image.img,
		&game->gfx.image.bpp,
		&game->gfx.image.line_len,
		&game->gfx.image.endian);
	if (load_xpm_files(game) != SUCCESS)
		return (ft_free_mlx(game, ERROR));
	return (SUCCESS);
}
