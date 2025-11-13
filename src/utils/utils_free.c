/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:21:51 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/13 16:00:41 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_textures(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g->textures[i])
			free(g->textures[i]);
		i++;
	}
}

int	free_loaded_textures(t_game *game, int end, int status)
{
	int	i;

	i = 0;
	while (i < end)
	{
		mlx_destroy_image(game->gfx.mlx, game->gfx.wall[i].img);
		i++;
	}
	if (status != SUCCESS)
		return (print_error("Failed to load XPM file."));
	return (SUCCESS);
}

int	ft_free_mlx(t_game *game, int error_type)
{
	free_map(game->map); //test
	if (error_type == WIN_FAIL)
	{
		mlx_destroy_display(game->gfx.mlx);
		return (print_error("Error initializing mlx"));
	}
	else if (error_type == ESC_PRESS)
	{
		if (game->gfx.image.img)
			mlx_destroy_image(game->gfx.mlx, game->gfx.image.img);
		free_loaded_textures(game, 4, SUCCESS);
		if (game->gfx.win)
			mlx_destroy_window(game->gfx.mlx, game->gfx.win);
		if (game->gfx.mlx)
		{
			mlx_destroy_display(game->gfx.mlx);
			free(game->gfx.mlx);
			game->gfx.mlx = NULL;
		}
		exit(0);
	}
	return (SUCCESS);
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	free_textures(game);
	if (game->map)
	{
		free_array(game->map->map_grid);
		free(game->map);
	}
		
}
