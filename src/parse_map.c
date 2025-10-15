/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:24:17 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/15 17:25:26 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Check if the NO SO WE EA are correct and in order
//Check if the map has correct walls

static int	try_texture_paths(t_game *game)
{
	(void)game;
	return (SUCCESS);
}
static void	assign_path_texture(t_game *game, char *path, char *dir)
{
	if (ft_strcmp(dir, "NO") == 0)
		game->assets->north = ft_strdup(path);
	if (ft_strcmp(dir, "SO") == 0)
		game->assets->south = ft_strdup(path);
	if (ft_strcmp(dir, "WE") == 0)
		game->assets->west = ft_strdup(path);
	if (ft_strcmp(dir, "EA") == 0)
		game->assets->east = ft_strdup(path);
}
static int	get_next_texture(t_game *game, int fd, char *dir)
{
	char	*line;
	char	*path;
	int		start;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (print_error("Error reading file"));
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp(&line[i], dir, ft_strlen(dir) == 0))
	{
		i += ft_strlen(dir);
		while (ft_isspace(line[i]))
			i++;
		start = i;
		while (line[i] && !ft_isspace(line[i]) && line[i] != '\n')
			i++;
		path = ft_substr(line, start, i - start);
		assign_path_texture(game, path, dir);
		free(path);
	}
	else
		return (free(line), print_error("Identifier not in order"));
	return (free(line), SUCCESS);
}

static int	get_texture(t_game *game, int fd)
{
	if (get_next_texture(game, fd, "NO") == ERROR)
		return (ERROR);
	if (get_next_texture(game, fd, "SO") == ERROR)
		return (ERROR);
	if (get_next_texture(game, fd, "WE") == ERROR)
		return (ERROR);
	if (get_next_texture(game, fd, "EA") == ERROR)
		return (ERROR);
	return (SUCCESS);
}
	

int	parse_map(t_game *game, t_map *map, char *file)
{
	int	fd;
	(void)map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return(print_error("File could not be opened"));
	if (get_texture(game, fd) == ERROR)
		return (close(fd), ERROR);
	close (fd);
	if (try_texture_paths(game) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

// 1. Check if file can be opened
// 2. Get the NO SO WE EA 
// 3. Skip spaces, if the first characters are not NO