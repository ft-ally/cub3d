/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 01:24:19 by tutku             #+#    #+#             */
/*   Updated: 2025/11/16 13:51:18 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//write rgb value into the image buffer
void	img_put_px(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)dest = color;
}

void	color_ceiling(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < (HEIGHT / 2))
	{
		x = 0;
		while (x < WIDTH)
		{
			img_put_px(&game->gfx.image, x, y, game->ceiling_rgb);
			x++;
		}
		y++;
	}
}

void	color_floor(t_game *game)
{
	int		x;
	int		y;

	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			img_put_px(&game->gfx.image, x, y, game->floor_rgb);
			x++;
		}
		y++;
	}
}
