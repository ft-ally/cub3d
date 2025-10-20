/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:53:17 by tutku             #+#    #+#             */
/*   Updated: 2025/10/20 17:02:29 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static const char *MAP_LIT[] = {
    "11111",
    "1N001",
    "10001",
    "10001",
    "11111",
    NULL
};

int init_test(t_game *game)
{
    game->ceiling = (8 << 16) | (148 << 8) | 159;
    game->floor   = (9 << 16) | (54 << 8) | 108;

    static t_textures textures = {
        .north = "./textures/north.xpm",
        .south = "./textures/south.xpm",
        .west  = "./textures/west.xpm",
        .east  = "./textures/east.xpm"
    };
    game->textures = &textures;
    return (SUCCESS);
}

int setup_map_writable(t_game *game)
{
    int h = 0;
    while (MAP_LIT[h])
        h++;

    game->map = malloc(sizeof(t_map));
    if (!game->map)
        return print_error("malloc map failed");

    game->map->map_grid = malloc((h + 1) * sizeof(char *));
    if (!game->map->map_grid)
        return print_error("malloc map_grid failed");

    for (int i = 0; i < h; i++) {
        game->map->map_grid[i] = ft_strdup(MAP_LIT[i]);
        if (!game->map->map_grid[i]) {
            // rollback on failure
            while (--i >= 0) free(game->map->map_grid[i]);
            free(game->map->map_grid);
            free(game->map);
            game->map = NULL;
            return print_error("strdup failed");
        }
    }
    game->map->map_grid[h] = NULL;
    return SUCCESS;
}

void free_map(t_map *m)
{
    if (m)
    {
        if (m->map_grid)
        {
            for (int i = 0; m->map_grid[i]; i++)
                free(m->map_grid[i]);
            free(m->map_grid);
        }
        free(m);
        m = NULL;
    }
}