/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_wall_textures.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:09:56 by tutku             #+#    #+#             */
/*   Updated: 2025/10/25 21:06:48 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//vertical wall->Wall aligned along the Y-axis (standing North–South)
//flip if you hit west or sout side of the wall
//if tex_col==0(leftmost) -> flipped==9(rightmost)
int		flip_texture(t_img	*texture, t_game *g)
{
	const int	is_west_side = g->render.is_vertical_wall && g->r.ray_x > 0;
	const int	is_south_side = !g->render.is_vertical_wall && g->r.ray_y < 0;
	int			texture_col;

	texture_col = (int)(g->render.ray_hit_pos * (double) texture->w);
	if (is_west_side || is_south_side)
		return (texture->w - texture_col - 1);
	return (texture_col);
}