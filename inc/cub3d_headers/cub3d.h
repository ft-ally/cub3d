/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:24:29 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/15 17:20:03 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "structs.h"
#include "libft.h"
#include "mlx.h"

#define SUCCESS 0
#define ERROR 1

/*=========|check_input.c|========*/
int	check_valid_input(int argc, char *map_name);

/*=========|parse_map.c|========*/
int	parse_map(t_game *game, t_map *map, char *file);

/*=========|utils_error.c|========*/
int	print_error(char *str);

# endif