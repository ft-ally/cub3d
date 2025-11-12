/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:06:41 by tutku             #+#    #+#             */
/*   Updated: 2025/11/12 21:27:54 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
g->r.cur_map_x/y -> represent the current square of the map the ray is in
g->r.side_x/y -> the distance the ray has to travel from its start position to 
	the first x-side and the first y-side, later incremented as steps are taken
g->r.delta_dist_x/y -> the distance the ray has to travel to go 
	from 1 x-side to the next x-side, or from 1 y-side to the next y-side
*/
void	init_ray(t_game *g, int x)
{
	g->r.camera_x = ((2.0 * x) / (double)WIDTH) - 1;
	g->r.ray_x = g->player.dir_x + (g->player.plane_x * g->r.camera_x);
	g->r.ray_y = g->player.dir_y + (g->player.plane_y * g->r.camera_x);
	g->r.cur_map_x = (int)g->player.x;
	g->r.cur_map_y = (int)g->player.y;
}

/* check
deltaDistX = abs(1 / rayDirX) or sqrt(1 + (ray_y * ray_y) / (ray_x * ray_x));
deltaDistY = abs(1 / rayDirY) or sqrt(1 + (ray_x * ray_x) / (ray_y * ray_y));
if x or y is zero, division to zero is avoided by setting it to 1e30
*/
void	get_dist_to_next_grid(t_game *g)
{
	const double	ray_x = g->r.ray_x;
	const double	ray_y = g->r.ray_y;

	if (ray_x == 0)
		g->r.delta_dist_x = 1e30;
	else
		g->r.delta_dist_x =  1 / fabs(ray_x);
	if (ray_y == 0)
		g->r.delta_dist_y = 1e30;
	else
		g->r.delta_dist_y = 1 / fabs (ray_y);
}

///step_x(left/right) step_y(up/down) holds-> which side we're moving
//if step_y == -1 (going up, smaller y)
///side_x side_y-> dist from cur_pos to first hor. or vert. grid ray will hits
void	set_moving_direction(t_game *g)
{
	if (g->r.ray_x < 0)
	{
		g->r.step_x = -1;
		g->r.side_x = (g->player.x - g->r.cur_map_x) * g->r.delta_dist_x;
	}
	else
	{
		g->r.step_x = 1;
		g->r.side_x = (g->r.cur_map_x - g->player.x + 1.0) * g->r.delta_dist_x;
	}
	if (g->r.ray_y < 0)
	{
		g->r.step_y = -1;
		g->r.side_y = (g->player.y - g->r.cur_map_y) * g->r.delta_dist_y;
	}
	else
	{
		g->r.step_y = 1;
		g->r.side_y = (g->r.cur_map_y - g->player.y + 1.0) * g->r.delta_dist_y;
	}
}

//decides which side of the tile we hit
//wall_dist is the distance between the wall and the cam vector
//wall dist is perpendicular to prevent fish eye effect
void	set_side_hit(t_game *g)
{
	if (g->r.side_hit == E_OR_W)
	{
		g->r.wall_dist = g->r.side_x - g->r.delta_dist_x;
		if (g->r.ray_x > 0)
			g->r.side_hit = EAST;
		else
			g->r.side_hit = WEST;
	}
	else
	{
		g->r.wall_dist = g->r.side_y - g->r.delta_dist_y;
		if (g->r.ray_y > 0)
			g->r.side_hit = SOUTH;
		else
			g->r.side_hit = NORTH;
	}
}

/// Line height and on-screen span(top & bottom pixel row)
void	init_pixel_fill(t_game *g)
{
	const int	center_line = HEIGHT / 2;

	g->l.line_height = (int)(HEIGHT / g->r.wall_dist);
	if (g->l.line_height < 1)
		g->l.line_height = 1;
	g->l.top_row = center_line - (g->l.line_height / 2);
	if (g->l.top_row < 0)
		g->l.top_row = 0;
	g->l.bottom_row = center_line + (g->l.line_height / 2);
	if (g->l.bottom_row >= HEIGHT)
		g->l.bottom_row = HEIGHT - 1;
}
