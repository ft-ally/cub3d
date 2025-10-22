/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:53:00 by tutku             #+#    #+#             */
/*   Updated: 2025/10/22 17:45:55 by tcakir-y         ###   ########.fr       */
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

static void	init_ray(t_game *g, int x)
{
	g->r.camera_x = ((2.0 * x) / (double)WIDTH) - 1;
	g->r.ray_x = g->player.dir_x + (g->player.plane_x * g->r.camera_x);
	g->r.ray_y = g->player.dir_y + (g->player.plane_y * g->r.camera_x);
	g->r.cur_map_x = (int)g->player.x;
	g->r.cur_map_y = (int)g->player.y;
}

static void	get_dist_to_next_grid(t_game *g)
{
	if (g->r.ray_x == 0)
		g->r.delta_dist_x = 1e30;
	else
		g->r.delta_dist_x = fabs(1.0 / g->r.ray_x);
	if (g->r.ray_y == 0)
		g->r.delta_dist_y = 1e30;
	else
		g->r.delta_dist_y = fabs(1.0 / g->r.ray_y);
}

///step_x(left/right) step_y(up/down) holds-> which side we're moving
//if step_y == -1 (going up, smaller y)
///side_x side_y-> dist from cur_pos to first hor. or vert. grid ray will hits
static void	set_moving_direction(t_game *g)
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

//loop that increments the ray with 1 square every time, until a wall is hit
//jump to next map square, either in x-direction, or in y-direction
//side_hit = 0-> hit a vertical wall (crossed x gridline)
//side_hit = 1-> hit a horizontal wall (crossed y gridline)
static void	start_dda(t_game *g)
{
	g->is_hit_wall = 0;
	while (g->is_hit_wall != 1)
	{
		if (g->r.side_x < g->r.side_y)
		{
			g->r.side_x += g->r.delta_dist_x;
			g->r.cur_map_x += g->r.step_x;
			g->r.side_hit = 0;
		}
		else
		{
			g->r.side_y += g->r.delta_dist_y;
			g->r.cur_map_y += g->r.step_y;
			g->r.side_hit = 1;
		}
		if (g->r.cur_map_y < 0 || g->r.cur_map_y >= g->map->height //check if needed
			|| g->r.cur_map_x < 0 || g->r.cur_map_x >= g->map->width)
			break ;
		if (g->map->map_grid[g->r.cur_map_y][g->r.cur_map_x] == '1')
			g->is_hit_wall = 1;
	}
}

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
		if (g->r.side_hit == 0)
			g->r.wall_dist = g->r.side_x - g->r.delta_dist_x;
		else
			g->r.wall_dist = g->r.side_y - g->r.delta_dist_y;
		
	}
	return (SUCCESS);
}
