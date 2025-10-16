/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:24:29 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/16 18:51:35 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

#include "structs.h"
#include "libft.h"
// #include "mlx.h"
// #include "mlx_init.h"

# define SUCCESS 0
# define ERROR 1
# define WIDTH 1920
# define HEIGHT 1080

/*========|init_program.c|=======*/
int		init_program(t_game *game, int argc, char **argv);

/*================|||PARSING|||==============*/

/*=======|get_identifier.c|======*/
int		get_identifier(t_game *game, int fd);

/*=======|get_map.c|=============*/
int		get_map(t_game *game, int fd);
int		count_rows_map(t_map *map, int fd);

/*========|get_rgb.c|===========*/
int		get_rgb(t_game *game, char *rgb_string, char *id);

/*=========|parse_file.c|========*/
int		parse_file(t_game *game, char *file);


/*================|||UTILS|||==============*/

/*=========|utils_free.c|========*/
void free_textures(t_game *g);
void free_array(char **array);
void free_all(t_game *game);

/*=========|utils_error.c|========*/
int		print_error(char *str);

/* ====utils_string.c====*/
long	ft_atol(char *str);
char	*ft_strcpy(char *dest, char *src);

/*========|utils_tests.c|========*/
void	print_extracted_data(t_game *game);

# endif