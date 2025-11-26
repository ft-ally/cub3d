/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:53:00 by tutku             #+#    #+#             */
/*   Updated: 2025/11/26 14:37:04 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//loop that increments the ray with 1 square every time, until a wall is hit
//jump to next map square, either in x-direction, or in y-direction
//side_hit = 0-> hit a vertical wall (crossed x gridline) E or W
//side_hit = 1-> hit a horizontal wall (crossed y gridline) N or S
//x<y -> next vertical gridline is closer than the next horizontal gridline
//crossing a vertical line -> hitting east or west of a wall
static void	start_dda(t_game *g)
{
	g->is_hit_wall = 0;
	while (g->is_hit_wall != 1)
	{
		if (g->r.side_x < g->r.side_y)
		{
			g->r.side_x += g->r.delta_dist_x;
			g->r.cur_map_x += g->r.step_x;
			g->r.side_hit = E_OR_W;
		}
		else
		{
			g->r.side_y += g->r.delta_dist_y;
			g->r.cur_map_y += g->r.step_y;
			g->r.side_hit = N_OR_S;
		}
		if (g->map->map_grid[g->r.cur_map_y][g->r.cur_map_x] == '1')
			g->is_hit_wall = 1;
	}
}

// wall_dist-> distance between the wall and the camera vector
int	init_dda(t_game *g)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		init_ray(g, x);
		get_dist_to_next_grid(g);
		set_moving_direction(g);
		start_dda(g);
		set_side_hit(g);
		init_pixel_fill(g);
		render_textured_column(g, x);
	}
	mlx_put_image_to_window(g->gfx.mlx, g->gfx.win, g->gfx.image.img, 0, 0);
	return (SUCCESS);
}

/*
compute the perpendicular ray length using explicit formulas:

t = (wallBoundary - playerCoord) / rayDirComponent
chosen by which face hit. 

the same via:
wall_dist = sideDist_axis - deltaDist_axis
Both yield the “ray length” (distance along the ray) and avoid fisheye.
*/
