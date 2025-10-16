/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:07:02 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 17:39:11 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

///If the first lines after the rgb are not filled with \n or spaces, ERROR
int	check_lines_after_rgb(int fd)
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
				&& line[i] != '1' )
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
	int		len;
	
	if (check_lines_after_rgb(fd) == ERROR)
		return (ERROR);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->height++;
		len = ft_strlen(line);
		if (len > map->width)
			map->width = len;
		free(line);
	}
	if (map->height == 0)
		return (print_error("No map found"));
	return (SUCCESS);
}

int	skip_to_map(int fd)
{
	char	*line;
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (print_error("Get next line error"));
		i = 0;
		while (line[i])
		{
			if (i == 0 && line[i] == 'C')
			{
				c = 1;
				break ;
			}
			if (c == 1)
			{
				if (line[i] == ' ' || line[i] == '\t')
				{
					i++;
					continue ;
				}
				if (line[i] == '1' || line[i] == '0')
					return(free(line), SUCCESS);
			}
			i++;
		}
		free(line);
	}
	return (SUCCESS);
}

/// @brief 
///Copy the map into a 2d array, 
///validate the map for walls
///validate walkable path,
///don't forget to call free array if map is not valid
int	get_map(t_game *game, int fd)
{
	(void)game;
	if (skip_to_map(fd) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

	// validate_walls();
	// validate_walkable_path();
	//So rught now, go to the EOF on this fd.
	//Count how many get next line calls (rows)
	//Count how many chars -> longest one is the max column
	//Close file
	//Open the file again
	//malloc the 2d array with rows and columns
	//Skip until line[i] == '1' or 0
	//Then copy?