/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:21:51 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/18 00:32:07 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
void free_textures(t_game *g)
{
	if (!g || !g->textures)
		return ;
	if (g->textures->north)
		free(g->textures->north);
	if (g->textures->south)
		free(g->textures->south);
	if (g->textures->east)
		free(g->textures->east);
	if (g->textures->west)
		free(g->textures->west);
	free(g->textures);
}

// void free_all(t_game *game)
// {
	
// 	free_textures(game);
	
// }

int	ft_free_mlx(t_game *game, int error_type)
{
	if (error_type == WIN_FAIL)
	{
		mlx_destroy_display(game->gfx.mlx);
		return (print_error("Error initializing mlx"));
	}
	else if (error_type == ESC_PRESS)
	{
		if (game->gfx.image.img)
			mlx_destroy_image(game->gfx.mlx, game->gfx.image.img);
		if (game->gfx.win)
			mlx_destroy_window(game->gfx.mlx, game->gfx.win);
		if (game->gfx.mlx)
		{
			mlx_destroy_display(game->gfx.mlx);
			free(game->gfx.mlx);
        	game->gfx.mlx = NULL;
		}
		// mlx_destroy_image(game->gfx.mlx, game->textures->east);
		// mlx_destroy_image(game->gfx.mlx, game->textures->north);
		// mlx_destroy_image(game->gfx.mlx, game->textures->south);
		// mlx_destroy_image(game->gfx.mlx, game->textures->west);
		exit(0);
		return (0);
	}
	return (SUCCESS);
}