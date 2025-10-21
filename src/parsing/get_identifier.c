/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:06:26 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/21 17:03:23 by aalombro         ###   ########.fr       */
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
	fd = open(trimmed_path, O_RDONLY);
	if (fd < 0)
		return (free(trimmed_path), print_error("Texture path invalid"));
	close(fd);
	free(*path);
	*path = ft_strdup(trimmed_path);
	free(trimmed_path);
	return (SUCCESS);
}


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
		if (validate_path(&path) == ERROR)
			return (ERROR);
		if (game->gfx.wall[idn].addr != NULL)
			return(print_error("Duplicate identifiers found"));
		game->gfx.wall[idn].addr = ft_strdup(path);
		free(path);
		if (!game->gfx.wall[idn].addr)
			return (print_error("Error allocating wall to gfx struct"));
		return (SUCCESS);
	}
	else
		return(print_error("Invalid identifier"));
	return (ERROR);
}

static int	extract_path(t_game *game, char *id, char *line, int i)
{
	//only free here!
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
	free(line);
	free(id);
	return (SUCCESS);
}

static int	get_next_identifier(t_game *game, int fd, int i)
{
	char	*line;
	char	*id_string;
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
			return(free(line), print_error("Map error! Either missing identfier or map not at the end"));
		if (line[i] == '\n' || line[i] == '\0')
		{
			free(line);
			continue ;
		}
		id_string = ft_strtrim(line, "\t\n");
		id = ft_substr(id_string, 0, 2); //malloc'd, free inside extract
		free(id_string);
		if (!id)
			return (free(line), print_error("Error allocating id"));
		return (extract_path(game, id, line, i));
	}
	return (SUCCESS);
}

int	get_identifier(t_game *game, int fd)
{
	int	i;

	i = 0;
	while (!all_id_found(game))
	{
		if (get_next_identifier(game, fd, i) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

