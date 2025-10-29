/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_map_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:34:07 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/29 18:58:31 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_top_bottom(char **map, int height)
{
	int	j;

	j = 0;
	while(map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
			return (print_error("Map top not closed"));
		j++;
	}
	j = 0;
	while (map[height - 1][j])
	{
		if (map[height - 1][j] != '1' && map[height - 1][j] != ' ' && map[height-1][j] != '\0')
			return (print_error("Map bottom not closed"));
		j++;
	}
	return (SUCCESS);
}

int	check_first_last(char **map, int width)
{
	int	i;
	int	j;
	int	last;

	i = 0;
	j = 0;
	while(map[i])
	{
		last = width;
		j = 0;
		while (ft_isspace(map[i][j]))
			j++;
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (print_error("Map left side not closed"));
		while (last >= 0 && ft_isspace(map[i][last]))
			last--;
		if (map[i][last] != '1' && map[i][last] != ' ' && map[i][last] != '\0')
			return (print_error("Map right side not closed"));
		i++;
	}
	return (SUCCESS);
}

void	set_spawn(t_game *game, char **map, int i, int j)
{
	game->direction = map[i][j];
	game->dir_x = j;
	game->dir_y = i;
}

