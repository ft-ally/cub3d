/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:23:58 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/20 19:55:55 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	main(void)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (setup_map_writable(&game) != SUCCESS) //test
		return (ERROR);
	if (init_test(&game) != SUCCESS) //test
		return (ERROR);
	if (init_game(&game) != SUCCESS)
		return (free_map(game.map), ft_free_mlx(&game, SUCCESS), ERROR);
	free_map(game.map);
	ft_free_mlx(&game, SUCCESS);
	return (SUCCESS);
}
