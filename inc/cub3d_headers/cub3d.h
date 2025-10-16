/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:24:29 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 17:18:02 by aalombro         ###   ########.fr       */
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

/*=========|free.c|========*/
void free_textures(t_game *g);
void free_array(char **array);
void free_all(t_game *game);

/*========|init_program.c|=======*/
int		init_program(t_game *game, int argc, char **argv);

/*=======|get_identifier.c|======*/
int		get_identifier(t_game *game, int fd);

/*========|get_rgb.c|=========*/
int		get_rgb(t_game *game, char *rgb_string, char *id);


/*=========|parse_file.c|========*/
int		parse_file(t_game *game, char *file);

/*=========|utils_error.c|========*/
int		print_error(char *str);

/* ====utils.c====*/
long	ft_atol(char *str);

/*======get_map.c=====*/
int		get_map(t_game *game, int fd);
int		count_rows_map(t_map *map, int fd);


/*============|tests.c|===========*/
void	print_extracted_data(t_game *game);

# endif