/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:21:51 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/15 19:25:09 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static int check_extension(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (ft_strcmp(&map_name[len - 4], ".cub"))
		return(print_error("Wrong extension!"));
	else
		return (SUCCESS);
}

static int	check_valid_input(int argc, char *map_name)
{
	if (argc < 2)
		return (print_error("Choose map"));
	if (argc > 2)
		return (print_error("Too many arguments, only enter map name!"));
	if (check_extension(map_name) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}
//MALLOC WARNING!!!
static int	init_structs(t_map *map, t_game *game)
{
	ft_bzero(&game, sizeof(game));
	game->assets = malloc(sizeof(t_assets));
	if (!game->assets)
		return (print_error("Initial asset allocation failed"));
}
/// @brief checks the input, initializes struct, parses input file, copies map to 2d array 
int	init_program(t_map *map, t_game *game, int argc, char **argv)
{
	if (check_valid_input(argc, argv[1]) != SUCCESS)
		return (ERROR);
	if (init_structs(&game, &map) != SUCCESS)
		return (ERROR);
	if (parse_input_file(&game, &map, argv[1]) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}