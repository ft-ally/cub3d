/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:29:47 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/21 19:58:49 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCTS_H
# define STRUCTS_H

#include "cub3d.h"

typedef struct s_img_data t_img_data;
typedef struct s_gfx t_gfx;
typedef struct s_colors t_colors;
typedef struct s_textures t_textures;
typedef struct s_map t_map;
typedef struct s_game t_game;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp; //bits_per_pixel
	int		line_len;
	int		endian; //tells how colors are stored in memory
	int		w; //texture width
	int		h; //texture height
} t_img;

typedef struct s_gfx
{
	void	*mlx;
	void	*win;
	t_img	image;
	t_img	wall[4];
}	t_gfx;

typedef struct s_map
{
	char	**map_grid;
	int		width;
	int		height;
	
} t_map;

typedef struct s_ray
{
	double	camera_x;//Horizontal coord. of camera plane for this column [-1,1]
	double	ray_x;//direction vector of the ray through this column
	double	ray_y;//direction vector of the ray through this column
	int		cur_map_x;//int coord. of the map square ray is currently inside
	int		cur_map_y;
	double	delta_dist_x;//length to next x/y gridline
	double	delta_dist_y;
	int		step_x;//tells if we move right/left
	int		step_y;//tells if we move up/down
	int		side_x;//dist. from player's cur position to first horiz. gridline
	int		side_y;//dist. from player's cur position to first vert. gridline
	int		side_hit;
} t_ray;
/* add later
perp_dist → corrected distance to wall
*/


typedef struct s_player
{
	double	x;//player pos x
	double	y;//player pos y
	double	dir_x;//unit vector pointing in the direction the player is facing
	double	dir_y;//unit vector pointing in the direction the player is facing
	double	plane_x;//a vector perpendicular to dir
	double	plane_y;//a vector perpendicular to dir
} t_player;

typedef struct s_game
{
	char		direction;
	int			dir_x;
	int			dir_y;
	char		*textures[4];
	t_map		*map;
	t_gfx		gfx;
	t_player	player;
	int			ceiling_rgb;
	int			floor_rgb;
	t_ray		r;
	int			is_hit_wall;
} t_game;

#endif

