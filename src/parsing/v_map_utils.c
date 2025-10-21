/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_map_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:34:07 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/21 18:36:41 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_top_bottom(char **map, int height)
{
	int	j;

	j = 0;
	while(map[0][j])
	{
		if (map[0][j] != '1')
			return (print_error("Map not closed"));
		j++;
	}
	j = 0;
	while (map[height][j])
	{
		if (map[height][j] != '1')
			return (print_error("Map not closed"));
		j++;
	}
	return (SUCCESS);
}

int	check_first_last(char **map, int width)
{
	int	i;
	int	j;
	int	last;

	i = 0;
	while(map[i][j])
	{
		last = width;
		j = 0;
		while (ft_isspace(map[i][j]))
			j++;
		if (map[i][j] != '1')
			return (print_error("Map not closed"));
		while (ft_isspace(map[i][last]))
			last--;
		if (map[i][last] != '1')
			return (print_error("Map not closed"));
		i++;
	}
	return (SUCCESS);
}

void	set_spawn(t_game *game, char **map, int i, int j)
{
	game->spawn_dir = map[i][j];
	game->spawn_x = j;
	game->spawn_y = i;
}

char	**dup_map(t_game *game)
{
	int		i;
	char	*copy;

	i = 0;
	copy = malloc(sizeof(char *) * game->map->height);
	if (!copy)
		return (NULL);
	while (i < game->map->height && game->map->map_grid[i])
	{
		copy[i] = ft_strdup(game->map->map_grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (print_error("Copy map fail"), NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
