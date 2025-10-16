/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:07:02 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 15:43:35 by aalombro         ###   ########.fr       */
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

int	copy_map_to_array(t_map *map, int fd)
{
	// char	*line;
	// size_t	longest_line;

	(void)map;
	// longest_line = 0;
	
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	if (ft_strlen(line) > longest_line)
	// 		longest_line = ft_strlen(line);
	// }
	return(SUCCESS);
}


/// @brief This will copy the map into a 2d array, validate the map for walls
///validate walkable path,
///don't forget to call free array if map is not valid
int	get_map(t_game *game, int fd)
{
	if (check_lines_after_rgb(fd) == ERROR)
		return (ERROR);
	if (copy_map_to_array(game->map, fd) == ERROR)
		return (ERROR);
	// validate_walls();
	// validate_walkable_path();
	return (SUCCESS);
}