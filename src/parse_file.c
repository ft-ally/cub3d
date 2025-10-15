/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:24:17 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/15 19:25:48 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Check if the NO SO WE EA are correct and in order
//Check if the map has correct walls

int	get_colors(t_game *game, int fd)
{
	
}


int	parse_file(t_game *game, t_map *map, char *file)
{
	int	fd;
	(void)map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error("File could not be opened"));
	if (get_texture(game, fd) == ERROR)
		return (close(fd), ERROR);
	if (get_colors(game, fd) == ERROR)
		return(close(fd), ERROR);
	close(fd);
	
	if (try_texture_paths(game) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
