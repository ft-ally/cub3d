/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 01:24:19 by tutku             #+#    #+#             */
/*   Updated: 2025/10/20 18:32:58 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_ceiling(t_game *game)
{
	int		x;
	int		y;
	char	*dest;

	y = 0;
	while (y < (HEIGHT / 2))
	{
		x = 0;
		while (x < WIDTH)
		{
			dest = game->gfx.image.addr
				+ (y * game->gfx.image.line_len + x * game->gfx.image.bpp / 8);
			*(int *)dest = game->ceiling_rgb;
			x++;
		}
		y++;
	}
}

void	color_floor(t_game *game)
{
	int		x;
	int		y;
	char	*dest;

	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			dest = game->gfx.image.addr
				+ (y * game->gfx.image.line_len + x * game->gfx.image.bpp / 8);
			*(int *)dest = game->floor_rgb;
			x++;
		}
		y++;
	}
}
