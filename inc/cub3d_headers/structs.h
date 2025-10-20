/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:29:47 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/20 01:45:11 by tutku            ###   ########.fr       */
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

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bpp; //bits_per_pixel
	int		line_len;
	int		endian; //tells how colors are stored in memory
} t_img_data;


typedef struct s_gfx
{
	void		*mlx;
	void		*win;
	t_img_data	image;
	t_img_data	north;
	t_img_data	south;
	t_img_data	east;
	t_img_data	west;
}	t_gfx;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
} t_textures;

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
	t_textures	*textures;
	t_map		*map;
	t_gfx		gfx;
	t_player	player;
	int			ceiling;
	int			floor;
} t_game;

#endif

