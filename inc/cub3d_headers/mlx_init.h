/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:12:39 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/10/20 20:01:03 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INIT_H
# define MLX_INIT_H

# define NORTH 0
# define SOUTH 1
# define WEST  2
# define EAST  3

# define WIDTH 1920
# define HEIGHT 1080
# define FOV 60
# define HFOV 30

# define WIN_FAIL 1
# define ESC_PRESS 2

# define UP	         119
# define DOWN        115
# define LEFT        97
# define RIGHT       100
# define KEY_ESC     65307
# define ARROW_UP    65362
# define ARROW_DOWN  65364
# define ARROW_LEFT  65361
# define ARROW_RIGHT 65363

/*=========|init_background.c|========*/
void	color_floor(t_game *game);
void	color_ceiling(t_game *game);

/*=========|init_game.c|========*/
int	init_game(t_game *game);

/*=========|init_mlx.c|========*/
int	load_xpm_files(t_game *game);
int	init_mlx(t_game *game);
int	ft_free_mlx(t_game *game, int error_type);

/*=========|init_test.c|========*/
int setup_map_writable(t_game *game);
int init_test(t_game *game);
void free_map(t_map *m);

/*=========|init_player.c|========*/ //move to cub3d.h
int	init_player_pos(t_game *game);

/*=========|free.c|========*/
int	free_loaded_textures(t_game *game, int range, int status);

#endif
