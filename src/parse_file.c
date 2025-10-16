/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:24:17 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 17:30:57 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_file(t_game *game, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error("File could not be opened"));
	if (get_identifier(game, fd) == ERROR)
		return (close(fd), ERROR);
	if (count_rows_map(game->map, fd) == ERROR)
		return (close(fd), ERROR);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error("File could not be opened"));
	if (get_map(game, fd) == ERROR)
		return (close(fd), ERROR);
	close(fd);
	return (SUCCESS);
}
