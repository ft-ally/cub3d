/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:13:25 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 14:56:12 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
}
