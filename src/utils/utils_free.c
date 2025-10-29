/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:21:51 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/29 12:10:39 by aalombro         ###   ########.fr       */
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
