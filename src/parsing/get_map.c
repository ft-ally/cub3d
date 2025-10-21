/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:07:02 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/21 18:42:09 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

///If the first lines after the ids are not filled with \n or spaces, ERROR
int	check_new_lines(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (print_error("No map found"));
		i = 0;
		while (line[i])
		{
			if (line[i] == '\n')
			{
				free(line);
				break ;
			}
			if (line[i] != '0' && line[i] != ' '
				&& line[i] != '1' && line[i] !='\t' )
					return(free(line), print_error("Invalid map format!"));
			else if (line[i] == '1' || line[i] == '0')
				return (free(line), SUCCESS);
			i++;
		}
	}
}

/// @brief Count the map rows and cols for map ->reaches EOF
int	count_rows_map(t_map *map, int fd)
{
	char	*line;
	size_t	len;
	
	if (check_new_lines(fd) == ERROR)
		return (ERROR);
	map->height = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->height++;
		len = ft_strlen(line);
		if ((int)len > map->width)
			map->width = len;
		free(line);
	}
	if (map->height == 0)
		return (print_error("No map found"));
	return (SUCCESS);
}

int	skip_to_map(int fd, char **line)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (1)
	{
		*line = get_next_line(fd);
		if (!*line)
			return (print_error("Get next line error"));
		i = 0;
		while ((*line)[i])
		{
			if (i == 0 && (*line)[i] == 'C')
			{
				c = 1;
				break ;
			}
			if (c == 1)
			{
				if ((*line)[i] == ' ' || (*line)[i] == '\t')
				{
					i++;
					continue ;
				}
				if ((*line)[i] == '1' || (*line)[i] == '0')
					return(SUCCESS);
			}
			i++;
		}
		free(*line);
	}
	return (SUCCESS);
}

int	copy_map_to_array(t_game *game, char *line, int fd)
{
	int		i;

	i = 0;
	if (allocate_array(game) == ERROR)
		return (ERROR);
	while (i < game->map->height)
	{
		game->map->map_grid[i] = ft_strcpy(game->map->map_grid[i], line);
		if ((int)ft_strlen(game->map->map_grid[i]) != game->map->width)
			pad_line(game->map->width, game->map->map_grid[i]);
		free(line);
		if (i < game->map->height - 1)
		{
			line = get_next_line(fd);
			if (!line)
				return (print_error("Get next line fail"));
		}
		i++;
    }
	return (SUCCESS);
}

int	get_map(t_game *game, int fd)
{
	char	*line;

	if (skip_to_map(fd, &line) == ERROR)
		return (ERROR);
	if (copy_map_to_array(game, line, fd) == ERROR)
		return (ERROR);
	if (validate_map(game) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
