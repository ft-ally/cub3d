/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:06:26 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/18 17:47:13 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	assign_path_identifier(t_game *game, char *path, char *id)
{
	char	**target;
	int		idn;

	target = NULL;
	if (ft_strcmp(id, "F ") == 0 || ft_strcmp(id, "C ") == 0)
		return (get_rgb(game, path, id));
	idn = get_wall_index(id);
	if (idn != -1)
	{
		if (validate_path(path) == ERROR)
			return (ERROR);
		if (game->textures[idn] != NULL)
			return (print_error("Duplicate identifiers found"));
		game->textures[idn] = ft_strdup(path);
		if (!game->textures[idn])
			return (print_error("Error allocating wall to gfx struct"));
		return (SUCCESS);
	}
	else
		return (print_error("Invalid identifier"));
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
		return (free(line), free(id), print_error("Error allocating path"));
	if (assign_path_identifier(game, path, id) != SUCCESS)
		return (free(path), free(line), free(id), ERROR);
	free(path);
	free(line);
	free(id);
	return (SUCCESS);
}

static int	get_next_identifier(t_game *game, int fd, int i)
{
	char	*line;
	char	*id;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (print_error("Error reading file"));
		i = 0;
		while (ft_isspace(line[i]))
			i++;
		if (line[i] == '1' || line[i] == '0')
			return (free(line),
				print_error("Map error! Missing identfier or map not at end"));
		if (line[i] == '\n' || line[i] == '\0')
		{
			free(line);
			continue ;
		}
		id = ft_substr(line, i, 2);
		if (!id)
			return (free(line), print_error("Error allocating id"));
		return (extract_path(game, id, line, i));
	}
}

int	get_identifier(t_game *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (!all_id_found(game))
	{
		if (get_next_identifier(game, fd, i) == ERROR)
		{
			line = get_next_line(fd);
			while (line)
			{
				free(line);
				line = get_next_line(fd);
			}
			return (ERROR);
		}
	}
	return (SUCCESS);
}
