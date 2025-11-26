/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:23:58 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/26 14:41:07 by tcakir-y         ###   ########.fr       */
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
	ft_free_mlx(&game, SUCCESS);
	free_all(&game);
	return (SUCCESS);
}
