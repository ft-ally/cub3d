/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:24:29 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 13:44:57 by tcakir-y         ###   ########.fr       */
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

/*=========|free.c|========*/
void free_textures(t_game *g);
void free_array(char **array);
void free_all(t_game *game);

/*=========|init_program.c|========*/
int	init_program(t_game *game, int argc, char **argv);

/*=========|get_identifier.c|========*/
int	get_identifier(t_game *game, int fd);

/*=========|parse_file.c|========*/
int	parse_file(t_game *game, char *file);

/*=========|utils_error.c|========*/
int	print_error(char *str);

# endif