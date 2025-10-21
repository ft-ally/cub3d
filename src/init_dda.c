/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:53:00 by tutku             #+#    #+#             */
/*   Updated: 2025/10/21 19:48:40 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_game *g, int x)
{
	g->r.camera_x = ((2.0 * x) / (double)WIDTH) - 1;
	g->r.ray_x = g->player.dir_x + (g->player.plane_x * g->r.camera_x);
	g->r.ray_y = g->player.dir_y + (g->player.plane_y * g->r.camera_x);
	g->r.cur_map_x = (int)g->player.x;
	g->r.cur_map_y = (int)g->player.y;
}

void	get_dist_to_next_grid(t_game *g)
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

//loop that increments the ray with 1 square every time, until a wall is hit
//jump to next map square, either in x-direction, or in y-direction
//side_hit = 0-> hit a vertical wall (crossed x gridline)
//side_hit = 1-> hit a horizontal wall (crossed y gridline)
void	start_dda(t_game *g)
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
		if (g->r.cur_map_y < 0 || g->r.cur_map_y >= g->map->height
			|| g->r.cur_map_x < 0 || g->r.cur_map_x >= g->map->width)
			break ;
		if (g->map->map_grid[g->r.cur_map_y][g->r.cur_map_x] == '1')
			g->is_hit_wall = 1;
	}
}

int	init_dda(t_game *game)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{	
		init_ray(game, x);
		get_dist_to_next_grid(game);
		set_moving_direction(game);
		start_dda(game);
	}
	return (SUCCESS);
}
