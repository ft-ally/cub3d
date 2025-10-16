/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:21:51 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 17:32:19 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static int	check_extension(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (ft_strcmp(&map_name[len - 4], ".cub"))
		return (print_error("Wrong extension!"));
	else
		return (SUCCESS);
}

static int	check_valid_input(int argc, char *map_name)
{
	if (argc < 2)
		return (print_error("Choose a map"));
	if (argc > 2)
		return (print_error("Too many arguments, only enter map name!"));
	if (check_extension(map_name) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

static int	init_structs(t_game *game)
{
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
		return (print_error("Initial texture allocation failed"));
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (print_error("Map allocation failed"));
	ft_bzero(game->map, sizeof(t_map));
	return (SUCCESS);
}

/// @brief checks the input, initializes struct, parses input file,
/// copies map to 2d array 
int	init_program(t_game *game, int argc, char **argv)
{
	ft_bzero(game, sizeof(t_game));
	
	if (check_valid_input(argc, argv[1]) != SUCCESS)
		return (ERROR);
	if (init_structs(game) != SUCCESS)
		return (ERROR);
	if (parse_file(game, argv[1]) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}
