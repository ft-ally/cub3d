// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   render_wall_textures.c                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/10/25 19:54:40 by tutku             #+#    #+#             */
// /*   Updated: 2025/10/31 23:32:31 by tutku            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "cub3d.h"

/// texture -> depending on the face hit
void	render_textured_column(t_game *g, int x)
{
	t_img	*texture;
	int		texture_col;
	double	step; //check
	double	tex_pos; //check
	int		tex_y; //check

	g->render.is_vertical_wall = (g->r.side_hit == EAST
		|| g->r.side_hit == WEST);
	texture = &g->gfx.wall[g->r.side_hit];
	if (g->render.is_vertical_wall)
	g->render.ray_hit_pos = g->player.y + (g->r.wall_dist * g->r.ray_y);
	else
	g->render.ray_hit_pos = g->player.x + (g->r.wall_dist * g->r.ray_x);
	g->render.ray_hit_pos -= floor(g->render.ray_hit_pos);
	texture_col = flip_texture(texture, g);
	if (g->l.line_height <= 0) //check if needed
		return ;
	step    = (double)texture->h / (double)g->l.line_height;
	tex_pos = (g->l.top_row - (HEIGHT / 2.0) + (g->l.line_height / 2.0)) * step;
	for (int y = g->l.top_row; y <= g->l.bottom_row; ++y)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		tex_pos += step;
	}
}