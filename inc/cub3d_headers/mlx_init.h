/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:12:39 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/10/18 00:29:37 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INIT_H
# define MLX_INIT_H

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

/*=========|init_game.c|========*/
int	init_game(t_game *game);

/*=========|init_mlx.c|========*/
int	init_mlx(t_game *game);
int	ft_free_mlx(t_game *game, int error_type);

#endif
