/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:29:47 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/15 17:22:59 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_assets
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
} t_assets;

typedef struct s_map
{
	
} t_map;

typedef struct s_game
{
	char		direction;
	int			dir_x;
	int			dir_y;
	t_assets	*assets;
	t_map		*map;
} t_game;



