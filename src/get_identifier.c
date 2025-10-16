/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:06:26 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 14:54:15 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	validate_path(char **path)
{
	char	*trimmed_path;
	int		fd;

	trimmed_path = ft_strtrim(*path, " \t\n");
	if (!trimmed_path)
		return (print_error("Error trimming pathstring"));
	fd = open(*path, O_RDONLY);
	if (fd < 0)
		return (print_error("Texture path invalid"));
	close(fd);
	*path = trimmed_path;
	return (SUCCESS);
}

static int	assign_path_identifier(t_game *game, char *path, char *id)
{
	char	**target;

	target = NULL;
	if (ft_strcmp(id, "NO") == 0)
		target = &game->textures->north;
	else if (ft_strcmp(id, "SO") == 0)
		target = &game->textures->south;
	else if (ft_strcmp(id, "WE") == 0)
		target = &game->textures->west;
	else if (ft_strcmp(id, "EA") == 0)
		target = &game->textures->east;
	else if (ft_strcmp(id, "F") == 0 || ft_strcmp(id, "C") == 0)
		return (get_rgb(game, path, id));
	if (target)
	{
		if (validate_path(&path) == ERROR)
			return (ERROR);
		*target = ft_strdup(path);
		free(path);
		if (!*target)
			return (print_error("Error allocating texture"));
		return (SUCCESS);
	}
	return (ERROR);
}

static int	extract_path(t_game *game, char *id, char *line, int i)
{
	int		start;
	char	*path;

	i += ft_strlen(id);
	while (ft_isspace(line[i]))
		i++;
	start = i;
	while (line[i] && !ft_isspace(line[i]) && line[i] != '\n')
		i++;
	path = ft_substr(line, start, i - start);
	if (!path)
		return (free(path), print_error("Malloc fail"));
	if (assign_path_identifier(game, path, id) != SUCCESS)
		return (free(path), free(line), ERROR);
	free(path);
	free(line);
	return (SUCCESS);
}

static int	get_next_identifier(t_game *game, int fd, char *id)
{
	char	*line;
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
		if (ft_strncmp(&line[i], id, ft_strlen(id)) == 0)
			return (extract_path(game, id, line, i));
		else
		{
			free(line);
			return (print_error("Identifier not found or not in order"));
		}
	}
	return (SUCCESS);
}

int	get_identifier(t_game *game, int fd)
{
	if (get_next_identifier(game, fd, "NO") == ERROR)
		return (ERROR);
	if (get_next_identifier(game, fd, "SO") == ERROR)
		return (ERROR);
	if (get_next_identifier(game, fd, "WE") == ERROR)
		return (ERROR);
	if (get_next_identifier(game, fd, "EA") == ERROR)
		return (ERROR);
	if (get_next_identifier(game, fd, "F") == ERROR)
		return (ERROR);
	if (get_next_identifier(game, fd, "C") == ERROR)
		return (ERROR);
	return (SUCCESS);
}
