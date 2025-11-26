/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:12:39 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/11/26 14:44:54 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INIT_H
# define MLX_INIT_H

# define NORTH 0
# define SOUTH 1
# define EAST  2
# define WEST  3
# define E_OR_W 4
# define N_OR_S 5

# define WIDTH 1920
# define HEIGHT 1080
# define FOV 60
# define HFOV 30

# define WIN_FAIL 1
# define ESC_PRESS 2

# define KEY_ESC 65307

/*=========|init_background.c|========*/
void	img_put_px(t_img *img, int x, int y, int color);
void	color_floor(t_game *game);
void	color_ceiling(t_game *game);

/*=========|init_dda.c|========*/
int		init_dda(t_game *g);

/*=========|init_game.c|========*/
int		init_game(t_game *game);

/*=========|init_mlx.c|========*/
int		init_mlx(t_game *game);

/*=========|init_test.c|========*/
int		setup_map_writable(t_game *game);
int		init_test(t_game *game);
void	free_map(t_map *m);

/*=========|init_player.c|========*/ //move to cub3d.h
int		init_player_pos(t_game *game);

/*=========|init_movements.c|========*/
void	init_movements(int keycode, t_game *game);

/*=========|render_wall_textures.c|========*/
void	render_textured_column(t_game *g, int x);

/*=========|utils_dda.c|========*/
void	init_ray(t_game *g, int x);
void	get_dist_to_next_grid(t_game *g);
void	set_moving_direction(t_game *g);
void	set_side_hit(t_game *g);
void	init_pixel_fill(t_game *g);

/*=========|utils_render_wall_textures.c|========*/
int		flip_texture(t_img	*texture, t_game *g);

/*=========|free.c|========*/
int		free_loaded_textures(t_game *game, int range, int status);
int		ft_free_mlx(t_game *game, int error_type);

#endif
