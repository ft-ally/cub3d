/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:09:01 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/11/26 15:51:07 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_wall_column(t_game *g, int x, t_img *texture, double tex_pos)
{
	int		tex_y;
	int		y;
	char	*src;
	char	*dst;
	int		color;

	y = g->l.top_row;
	while (y < g->l.bottom_row)
	{
		tex_y = (int)tex_pos;
		tex_pos += g->step;
		src = texture->addr
			+ (tex_y * texture->line_len
				+ flip_texture(texture, g) * (texture->bpp / 8));
		color = *(int *)src;
		dst = g->gfx.image.addr
			+ (y * g->gfx.image.line_len
				+ x * (g->gfx.image.bpp / 8));
		*(int *)dst = color;
		y++;
	}
}

// texture -> depending on the face hit
void	render_textured_column(t_game *g, int x)
{
	t_img	*texture;
	double	tex_pos;

	g->render.is_vertical_wall = (g->r.side_hit == EAST
			|| g->r.side_hit == WEST);
	texture = &g->gfx.wall[g->r.side_hit];
	if (g->render.is_vertical_wall)
		g->render.ray_hit_pos = g->player.y + (g->r.wall_dist * g->r.ray_y);
	else
		g->render.ray_hit_pos = g->player.x + (g->r.wall_dist * g->r.ray_x);
	g->render.ray_hit_pos -= floor(g->render.ray_hit_pos);
	g->step = (double)texture->h / (double)g->l.line_height;
	tex_pos = (g->l.top_row - (HEIGHT / 2.0)
			+ (g->l.line_height / 2.0)) * g->step;
	print_wall_column(g, x, texture, tex_pos);
}
