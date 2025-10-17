/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:23:58 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/18 00:25:48 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static int init_test(t_game *game)
{
    game->ceiling = (8 << 16) | (148 << 8) | 159;
    game->floor = (9 << 16) | (54 << 8) | 108;
    static t_textures textures = {
        .north = "./textures/north.xpm",
        .south = "./textures/south.xpm",
        .west = "./textures/west.xpm",
        .east = "./textures/east.xpm"
    };
    game->textures = &textures;
    static char *map_data[] = {
        "11111",
        "1N001",
        "10001",
        "10001",
        "11111",
        NULL
    };
    static t_map map;
    map.map_grid = map_data;
    game->map = &map;
    return (SUCCESS);
}

int	main(void)
{
	t_game	game;

	// if (init_program(&game, argc, argv) != SUCCESS)
	// 	return (ERROR);//free_all(&game), 
	if (init_test(&game) != SUCCESS)
		return (ERROR);
	if (init_game(&game) != SUCCESS)
		return (ERROR);
	// free_all(&game);
	return (SUCCESS);
}