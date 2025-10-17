/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:47:42 by tutku             #+#    #+#             */
/*   Updated: 2025/10/18 00:40:32 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	load_xpm(t_game *game, t_img_data *xpm_array, int i)
// {
// 	xpm_array->img = mlx_xpm_file_to_image(game->gfx.mlx, 
// 						get_filepath(i), WIDTH, HEIGHT);
// 	if (!xpm_array->img)
// 		return ()
// }

// static int	xpm_file_to_image(t_game *game, char *filename, void *img)
// {
// 	img = mlx_xpm_file_to_image(game->gfx.mlx, filename, WIDTH, HEIGHT);
// 	if (!img)
// 	return (print_error("Image reading failed!\n"));
// }

// static int	load_xpm_files(t_game *game)
// {
// 	game->gfx.north.img = mlx_xpm_file_to_image(game->gfx.mlx, 
// 		game->textures->north, WIDTH, HEIGHT);
// 	if (!game->gfx.north.img)
// 		return (print_error("Image reading failed!\n"));
// 	// game->gfx.north.img->addr = mlx_get_data_addr(xpm_arr->img, &xpm_arr->bits_per_pixel, //change
// 	// 	&xpm_arr->line_length, &xpm_arr->endian);
// 	game->gfx.south.img = mlx_xpm_file_to_image(game->gfx.mlx, 
// 		game->textures->south, WIDTH, HEIGHT);
// 	if (!game->gfx.south.img)
// 		return (print_error("Image reading failed!\n"));
// 	game->gfx.east.img = mlx_xpm_file_to_image(game->gfx.mlx, 
// 		game->textures->east, WIDTH, HEIGHT);
// 	if (!game->gfx.east.img)
// 		return (print_error("Image reading failed!\n"));
// 	game->gfx.west.img = mlx_xpm_file_to_image(game->gfx.mlx, 
// 		game->textures->west, WIDTH, HEIGHT);
// 	if (!game->gfx.west.img)
// 		return (print_error("Image reading failed!\n"));
// }

/// Address of pixel(x, y) = Start of image
/// + (bytes to skip whole rows) (Jump down y rows)
/// + (bytes to skip pixels in the row)(Move right x pixels in that row)

static void	put_pixel(t_game *game, int x, int y, int rgb_val)
{
	char	*dest;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dest = game->gfx.image.addr
		+ (y * game->gfx.image.line_len + x * game->gfx.image.bpp / 8);
	*(int *)dest = rgb_val;
}

void	color_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (HEIGHT / 2))
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(game, x, y, game->ceiling);
			x++;
		}
		y++;
	}
}

void	color_floor(t_game *game)
{
	int	x;
	int	y;

	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(game, x, y, game->floor);
			x++;
		}
		y++;
	}
}

static int	pressed_esc(t_game *game)
{
	//free everything
	ft_free_mlx(game, ESC_PRESS);
	exit(0);
}

static int key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_free_mlx(game, ESC_PRESS);
		exit(0);
	}
	return (SUCCESS);
}

int	init_mlx(t_game *game)
{
	game->gfx.mlx = mlx_init();
	if (!game->gfx.mlx)
		return (free(game->gfx.mlx), print_error("Error initializing mlx"));
	game->gfx.win = mlx_new_window(game->gfx.mlx, WIDTH, HEIGHT, "Cub3D"); //fix later
	if (!game->gfx.win)
		return (ft_free_mlx(game, WIN_FAIL));
	// load_xpm_files(game);
	game->gfx.image.img = mlx_new_image(game->gfx.mlx, WIDTH, HEIGHT);
	game->gfx.image.addr = mlx_get_data_addr(
		game->gfx.image.img,
		&game->gfx.image.bpp,
		&game->gfx.image.line_len,
		&game->gfx.image.endian);
	color_ceiling(game);
	color_floor(game);
	mlx_put_image_to_window(game->gfx.mlx, game->gfx.win, game->gfx.image.img, 0, 0);
	mlx_key_hook(game->gfx.win, key_hook, game);
	mlx_hook(game->gfx.win, 17, 0, pressed_esc, game);
	mlx_loop(game->gfx.mlx);
	return (SUCCESS);
}


/*

steps for mlx:
m.mlx = mlx_init();
m.win = mlx_new_window(m.mlx, WIDTH, HEIGHT, "single wall"); //destroy display if fails
m.img.img = mlx_new_image(m.mlx, WIDTH, HEIGHT);
m.img.addr = mlx_get_data_addr(m.img.img, &m.img.bpp, &m.img.line_len, &m.img.endian);
background -> ceiling and floor

*/