/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:13:25 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 19:01:28 by aalombro         ###   ########.fr       */
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
	printf("North: %s\n", game->textures->north);
	printf("South: %s\n", game->textures->south);
	printf("East: %s\n", game->textures->east);
	printf("West: %s\n", game->textures->west);
	printf("====================\n");
	printf("Colors\n");
	printf("====================\n");
	printf("===Floor===\n");
	printf("R:%i || G:%i || B:%i\n", game->floor.r,
		game->floor.g, game->floor.b);
	printf("===Ceiling===\n");
	printf("R:%i || G: %i || B:%i\n",
		game->ceiling.r, game->ceiling.g, game->ceiling.b);
	print_map(game);
}
