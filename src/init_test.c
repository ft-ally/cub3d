/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:53:17 by tutku             #+#    #+#             */
/*   Updated: 2025/10/22 16:48:26 by tcakir-y         ###   ########.fr       */
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

int	init_test(t_game *game)
{
	game->ceiling_rgb = (8 << 16) | (148 << 8) | 159;
	game->floor_rgb   = (9 << 16) | (54 << 8) | 108;
	game->textures[NORTH] = "./textures/north.xpm";
	game->textures[SOUTH] = "./textures/south.xpm";
	game->textures[WEST] = "./textures/west.xpm";
	game->textures[EAST] = "./textures/east.xpm";
	return (SUCCESS);
}

int	setup_map_writable(t_game *game)
{
	int	h = 0;

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
			while (--i >= 0) free(game->map->map_grid[i]);
			free(game->map->map_grid);
			free(game->map);
			game->map = NULL;
			return (print_error("strdup failed"));
		}
	}
	game->map->map_grid[h] = NULL;
	return SUCCESS;
	}

void	free_map(t_map *m)
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