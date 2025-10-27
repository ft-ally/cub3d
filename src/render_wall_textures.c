/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:54:40 by tutku             #+#    #+#             */
/*   Updated: 2025/10/25 21:09:34 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// texture -> depending on the face hit
//1.determine which tex_col should be used for wall slice
//2.flip the texture column when needed
void	render_textured_column(t_game *g, int x)
{
	t_img	*texture;
	int		texture_col;

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
	double step    = (double)texture->h / (double)g->l.line_height;

	// 2) where to start sampling the texture for the first screen row we draw
	double tex_pos = (g->l.top_row - (HEIGHT / 2.0) + (g->l.line_height / 2.0)) * step;
	
	// 3) draw the wall slice: sample tex_y row-by-row and copy to the frame image
	for (int y = g->l.top_row; y <= g->l.bottom_row; ++y)
	{
		int tex_y = (int)tex_pos;
		if (tex_y < 0) tex_y = 0;
		if (tex_y >= texture->h) tex_y = texture->h - 1;
		tex_pos += step;
	
		char *src = texture->addr + tex_y * texture->line_len + texture_col * (texture->bpp / 8);
		int   color = *(int *)src;
	
		char *dst = g->gfx.image.addr + y * g->gfx.image.line_len + x * (g->gfx.image.bpp / 8);
		*(int *)dst = color;
	}
}

/*
why flip?
you stand in front of a wall and look at it from the front, 
the texture's left side should be shown on your left.
But if you hit the same wall from behind (from the opposite side), 
the left side of the texture should now appear on your right
*/