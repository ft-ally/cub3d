/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:29:47 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/22 19:10:43 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCTS_H
# define STRUCTS_H

#include "cub3d.h"

typedef struct s_img t_img;
typedef struct s_gfx t_gfx;
typedef struct s_map t_map;
typedef struct s_ray t_ray;
typedef struct s_player t_player;
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
	double	wall_dist;//calculated distance to wall
} t_ray;

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
	t_map		*map;
	t_player	player;
	t_ray		r;
	t_gfx		gfx;
	char		direction;
	char		*textures[4];
	int			dir_x;
	int			dir_y;
	int			ceiling_rgb;
	int			floor_rgb;
	int			is_hit_wall;
} t_game;

//typedef struct	s_line
//{
//	int	x; //the x coordinate of line relative to screen
//	int	y; //the current pixel index of the line (along y axis)
//	int	y0; //y start index of drawing texture
//	int	y1; //y end index of drawing texture
//	int	tex_x; //x coordinate of texture to draw
//	int	tex_y; //y coordinate of texture to draw
//} t_line;

#endif
