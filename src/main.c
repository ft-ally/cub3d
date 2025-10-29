/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:23:58 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/29 15:04:42 by aalombro         ###   ########.fr       */
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
	printf("Done");
	print_extracted_data(&game);
	free_all(&game);
	return (SUCCESS);
}