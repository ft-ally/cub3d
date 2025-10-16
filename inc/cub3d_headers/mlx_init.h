/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:12:39 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/10/16 13:59:49 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INIT_H
# define MLX_INIT_H

# define WIDTH 1920
# define HEIGHT 1080
# define FOV 60
# define HFOV 30

# define WIN_FAIL 1
# define ESC 2

/*=========|init_game.c|========*/
int	init_game(t_game *game);

#endif