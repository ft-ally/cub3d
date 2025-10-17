/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:06:26 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/18 00:54:57 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	validate_rgb_string(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (!isdigit(str[i]) && ft_strcmp(&str[i], ",") == 0)
			return(print_error("Invalid character on RGB"));
		i++;
	}
	return (SUCCESS);
}
static int get_rgb(t_game *game, char *rgb_string, char *id)
{
	char	**rgb_array;
	(void)game;

	if (validate_rgb_string(rgb_string) == ERROR)
		return (ERROR);
	rgb_array = ft_split(rgb_string, ',');
	if (!rgb_array || !rgb_array[0] || !rgb_array[1]
		|| !rgb_array[2] || rgb_array[3])
	{
		free_array(rgb_array);
		rgb_array = NULL;
		return (print_error("RGB error"));
	}
	if (ft_strcmp(id, "F") == 0)
	{
		// game->floor.r =  ft_atoi(rgb_array[0]);
		// game->floor.g = ft_atoi(rgb_array[1]);
		// game->floor.b = ft_atoi(rgb_array[2]);
	}
	else
	{
		// game->ceiling.r = ft_atoi(rgb_array[0]);
		// game->ceiling.g = ft_atoi(rgb_array[1]);
		// game->ceiling.b = ft_atoi(rgb_array[2]);
	}
	return (free_array(rgb_array), rgb_array = NULL, SUCCESS);
}

int	validate_path(char **path)
{
	char	*trimmed_path;
	int	fd;
	
	trimmed_path = ft_strtrim(*path, " \t\n");
	if (!trimmed_path)
		return (print_error("Error trimming pathstring"));
	fd = open(*path, O_RDONLY);
	if (fd < 0)
		return(print_error("Texture path invalid"));
	close(fd);
	free(*path);
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
		if (!*target)
			return (print_error("Error allocating texture"));
		return (SUCCESS);
	}
	return (ERROR);
}

static int	get_next_identifier(t_game *game, int fd, char *id)
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
		if (ft_strncmp(&line[i], id, ft_strlen(id)) == 0)
		{
			i += ft_strlen(id);
			while (ft_isspace(line[i]))
				i++;
			start = i;
			while (line[i] && !ft_isspace(line[i]) && line[i] != '\n')
				i++;
			path = ft_substr(line, start, i - start);
			if (assign_path_identifier(game, path, id) != SUCCESS)
				return (free(path), free(line), ERROR);
			else
				return (free(path), free(line), SUCCESS);

		}
		else
			return (free(line), print_error("Identifier not found or not in order"));
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