/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:29:47 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 13:44:14 by tcakir-y         ###   ########.fr       */
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
	int		bits_per_pixel;
	int		line_len;
	int		endian;
} t_img_data;


typedef struct s_gfx
{
	void		*mlx;
	void		*win;
	t_img_data	image;
}	t_gfx;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
} t_colors;

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
	
} t_map;

typedef struct s_game
{
	char		direction;
	int			dir_x;
	int			dir_y;
	t_colors	ceiling;
	t_colors	floor;
	t_textures	*textures;
	t_map		*map;
	t_gfx		gfx;
} t_game;

#endif

