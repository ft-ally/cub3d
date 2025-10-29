/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:13:25 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/29 12:11:03 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	print_map(t_game *game)
{
	int	i;

	i = 0;
	printf("====================\n");
	printf("MAP\n");
	printf("====================\n");
	if (game->map->map_grid)
	{
		while (game->map->map_grid[i])
		{
			printf("%s\n", game->map->map_grid[i]);
			i++;
		}
	}
}
/// @brief Print and validate data 
void	print_extracted_data(t_game *game)
{

	printf("====================\n");
	printf("Texture paths\n");
	printf("====================\n");
	printf("North: %s\n", game->textures[0]);
	printf("South: %s\n", game->textures[1]);
	printf("East: %s\n", game->textures[2]);
	printf("West: %s\n", game->textures[3]);
	
	printf("====================\n");
	printf("Colors\n");
	printf("====================\n");
	printf("===Floor===\n");
	printf("%d\n", game->floor_rgb);
	printf("===Ceiling===\n");
	printf("%d\n", game->ceiling_rgb);
	print_map(game);
}
