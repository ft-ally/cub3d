/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:01:53 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/18 17:56:53 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_path(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (print_error("Texture path invalid"));
	close(fd);
	return (SUCCESS);
}

int	get_wall_index(char *id)
{
	if (ft_strcmp(id, "NO") == 0)
		return (NORTH);
	if (ft_strcmp(id, "SO") == 0)
		return (SOUTH);
	if (ft_strcmp(id, "WE") == 0)
		return (WEST);
	if (ft_strcmp(id, "EA") == 0)
		return (EAST);
	return (-1);
}

int	all_id_found(t_game *game)
{
	int	i;

	i = 0;
	if (game->ceiling_rgb == -1 || game->floor_rgb == -1)
		return (0);
	while (i < 4)
	{
		if (game->textures[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}

void	pad_line(int width, char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
		len--;
	}
	i = len;
	while (i < width)
	{
		str[i] = ' ';
		i++;
	}
	str[width] = '\0';
}

int	allocate_array(t_game *game)
{
	int	i;

	i = 0;
	game->map->map_grid = malloc((game->map->height + 1) * sizeof(char *));
	if (!game->map->map_grid)
		return (print_error("Map allocation error"));
	while (i < game->map->height)
	{
		game->map->map_grid[i] = malloc((game->map->width + 1) * sizeof (char));
		if (!game->map->map_grid[i])
		{
			while (--i >= 0)
				free(game->map->map_grid[i]);
			free(game->map->map_grid);
			return (print_error("Memory allocation failed"));
		}
		i++;
	}
	game->map->map_grid[i] = NULL;
	return (SUCCESS);
}
