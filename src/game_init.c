/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:15:25 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/10/15 19:24:06 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//static void	init_mlx_vars(t_game *game)
//{
//	if (!game->vis.mlx)
//		return ;
//}

int	game_init(t_game *game)
{
	t_img_data	img;

	game->vis.mlx = malloc(sizeof(t_mlx));
	if (!game->vis.mlx)
		return (print_error("Error allocating memory for mlx"));
	game->vis.mlx = mlx_init();
	if (!game->vis.mlx)
		return (free(game->vis.mlx), print_error("Error initializing mlx"));
	game->vis.win = mlx_new_window(game->vis.mlx, WIDTH, HEIGHT, "Cub3D"); //fix later
	if (!game->vis.win)
		return (free(game->vis.mlx), print_error("Error creating window"));
	//img.img = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len,
	//			&img.endian);
	
	mlx_loop(game->vis.mlx);
	return (SUCCESS);
}

//load images here later
//put images to window here later
//mlx_key_hook(game->vis.win, key_hook, game); //add movements
//mlx_loop here later