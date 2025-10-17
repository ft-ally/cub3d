/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:15:25 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/10/17 21:27:36 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_game(t_game *game)
{
	if (init_mlx(game) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

//load images here later
//put images to window here later
//mlx_key_hook(game->vis.win, key_hook, game); //add movements
//mlx_loop here later

/*
0x00RRGGBB
 ┌───────────────────────────┐  y = 0
 │         ceiling           │  → 0x0080A0D0
 │         (sky)             │
 ├───────────────────────────┤  y = HEIGHT/2
 │          floor            │  → 0x00303030
 │                           │
 └───────────────────────────┘  y = HEIGHT
*/