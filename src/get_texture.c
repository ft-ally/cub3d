/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:06:26 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/15 19:18:47 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	try_texture_paths(t_game *game)
{
	(void)game;
	return (SUCCESS);
}

static void	assign_path_texture(t_game *game, char *path, char *dir)
{
	if (ft_strcmp(dir, "NO") == 0)
		game->assets->north = ft_strdup(path);
	else if (ft_strcmp(dir, "SO") == 0)
		game->assets->south = ft_strdup(path);
	else if (ft_strcmp(dir, "WE") == 0)
		game->assets->west = ft_strdup(path);
	else if (ft_strcmp(dir, "EA") == 0)
		game->assets->east = ft_strdup(path);
}

//!!!!!MALLOC WARNING!!!!!
static int	get_next_texture(t_game *game, int fd, char *dir)
{
	char	*line;
	char	*path;
	int		start;
	int		i;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (print_error("Error reading file"));
		i = 0;
		while (ft_isspace(line[i]))
				i++;
		if (line[i] == '\n' || line[i] == '\0')
		{
			free(line);
			continue ;
		}
		if (ft_strncmp(&line[i], dir, ft_strlen(dir)) == 0)
		{
			i += ft_strlen(dir);
			while (ft_isspace(line[i]))
				i++;
			start = i;
			while (line[i] && !ft_isspace(line[i]) && line[i] != '\n')
				i++;
			path = ft_substr(line, start, i - start);
			assign_path_texture(game, path, dir);
			return (free(path), free(line), SUCCESS);
		}
		else
			return (free(line), print_error("Identifier not found or not in order"));
	}
	return (SUCCESS);
}

int	get_texture(t_game *game, int fd)
{
	if (get_next_texture(game, fd, "NO") == ERROR)
		return (ERROR);
	if (get_next_texture(game, fd, "SO") == ERROR)
		return (ERROR); //ADD MALLOC FREE TEXTURES
	if (get_next_texture(game, fd, "WE") == ERROR)
		return (ERROR);
	if (get_next_texture(game, fd, "EA") == ERROR)
		return (ERROR);
	return (SUCCESS);
}