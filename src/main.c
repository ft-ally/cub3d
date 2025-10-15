/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:23:58 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/15 19:26:46 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>


int	main(int argc, char *argv[])
{
	t_map	map;
	t_game	game;

	if (init_program(&map, &game, argc, argv) != SUCCESS)
		return (ERROR);
	if (game_init(&game) != SUCCESS)
		return (ERROR);
	printf("asset path north: %s\n", game.assets->north);
	printf("asset path south: %s\n", game.assets->south);
	printf("asset path east: %s\n", game.assets->east);
	printf("asset path west: %s\n", game.assets->west);
	return (SUCCESS);
}