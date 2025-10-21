/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:29:47 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/21 15:46:23 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCTS_H
# define STRUCTS_H

#include "cub3d.h"

# define NORTH 0
# define SOUTH 1
# define EAST  2
# define WEST  3

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

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	
} t_player;

typedef struct s_game
{
	char		direction;
	int			dir_x;
	int			dir_y;
	t_map		*map;
	t_gfx		gfx; //not a pointer, no malloc
	t_player	player;
	int			ceiling_rgb;
	int			floor_rgb;
} t_game;

#endif