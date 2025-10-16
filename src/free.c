/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:21:51 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 13:34:49 by aalombro         ###   ########.fr       */
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

void free_all(t_game *game)
{
	
	free_textures(game);
	
}