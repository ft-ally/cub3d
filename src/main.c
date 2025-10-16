/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:23:58 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 14:13:35 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>



int	main(int argc, char *argv[])
{
	t_game	game;

	if (init_program(&game, argc, argv) != SUCCESS)
		return (free_all(&game), ERROR);
	// if (game_init(&game) != SUCCESS)
	// 	return (ERROR);
	print_extracted_data(&game);
	free_all(&game);
	return (SUCCESS);
}