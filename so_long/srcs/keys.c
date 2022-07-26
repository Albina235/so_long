/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <evalorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:38:10 by evalorie          #+#    #+#             */
/*   Updated: 2022/07/26 14:38:11 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.wall, j * 40, i * 40);
	else if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.floor, j * 40, i * 40);
	else if (map->map[i][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.player, j * 40, i * 40);
	else if (map->map[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.exit, j * 40, i * 40);
	else if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.coin1, j * 40, i * 40);
}

int	draw_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			draw(map, i, j);
	}
	return (0);
}

int	keys(int key, t_map *map)
{
	if (key == UP)
		move_player_up(map);
	else if (key == DOWN)
		move_player_down(map);
	else if (key == RIGHT)
		move_player_right(map);
	else if (key == LEFT)
		move_player_left(map);
	else if (key == ESC)
		end_game();
	draw_map(map);
	return (0);
}

void	steps(t_map *map)
{
	map->steps++;
}

int	end_game(void)
{
	exit(0);
	return (0);
}
