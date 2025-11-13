/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:23:58 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/13 16:27:17 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_game	game;

	if (init_program(&game, argc, argv) != SUCCESS)
		return (free_all(&game), ERROR);
	 if (init_game(&game) != SUCCESS)
	 	return (ft_free_mlx(&game, SUCCESS), free_all(&game), ERROR);
	print_extracted_data(&game);
	ft_free_mlx(&game, SUCCESS);
	free_all(&game);
}

// int	main(void)
// {
// 	t_game	game;

// 	ft_memset(&game, 0, sizeof(t_game));
// 	if (setup_map_writable(&game) != SUCCESS) //test
// 		return (ERROR);
// 	if (init_test(&game) != SUCCESS) //test
// 		return (ERROR);
// 	if (init_game(&game) != SUCCESS)
// 		return (free_map(game.map), ft_free_mlx(&game, SUCCESS), ERROR);
// 	ft_free_mlx(&game, SUCCESS);
// 	free_map(game.map);
// 	return (SUCCESS);
// }
