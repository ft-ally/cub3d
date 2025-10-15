/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:24:29 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/15 19:26:53 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

#include "structs.h"
#include "libft.h"
#include "mlx.h"
#include "mlx_init.h"

# define SUCCESS 0
# define ERROR 1
# define WIDTH 1920
# define HEIGHT 1080


/*=========|init_program.c|========*/
int	init_program(t_map *map, t_game *game, int argc, char **argv);

/*=========|get_texture.c|========*/
int	get_texture(t_game *game, int fd);

/*=========|parse_file.c|========*/
int	parse_file(t_game *game, t_map *map, char *file);

/*=========|utils_error.c|========*/
int	print_error(char *str);

# endif