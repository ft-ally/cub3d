/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:23:58 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 14:02:01 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>


int	main(int argc, char *argv[])
{
	t_game	game;

	if (init_program(&game, argc, argv) != SUCCESS)
		return (free_all(&game), ERROR);
	// if (init_game(&game) != SUCCESS)
	// 	return (ERROR);
	printf("texture path north: %s\n", game.textures->north);
	printf("texture path south: %s\n", game.textures->south);
	printf("texture path east: %s\n", game.textures->east);
	printf("texture path west: %s\n", game.textures->west);
	free_all(&game);
	return (SUCCESS);
}