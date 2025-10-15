/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:29:47 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/15 19:27:07 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCTS_H
# define STRUCTS_H

#include "cub3d.h"

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
} t_img_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;
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
	t_mlx		vis;
} t_game;

#endif

