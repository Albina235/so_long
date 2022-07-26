/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_right_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <evalorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:49:30 by evalorie          #+#    #+#             */
/*   Updated: 2022/07/26 14:49:31 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_map *map)
{
	map->map[map->play_coord.y][map->play_coord.x + 1] = 'P';
	map->map[map->play_coord.y][map->play_coord.x] = '0';
	map->play_coord.x++;
	steps(map);
}

void	move_player_right(t_map *map)
{
	if (map->map[map->play_coord.y][map->play_coord.x + 1] == '0')
		move_right(map);
	else if (map->map[map->play_coord.y][map->play_coord.x + 1] == 'C')
	{
		move_right(map);
		map->coin--;
	}
	else if (map->map[map->play_coord.y][map->play_coord.x + 1] == 'E' &&
		map->coin == 0)
		end_game();
	else if (map->map[map->play_coord.y][map->play_coord.x + 1] == 'X')
		end_game();
}

void	move_left(t_map *map)
{
	map->map[map->play_coord.y][map->play_coord.x - 1] = 'P';
	map->map[map->play_coord.y][map->play_coord.x] = '0';
	map->play_coord.x--;
	steps(map);
}

void	move_player_left(t_map *map)
{
	if (map->map[map->play_coord.y][map->play_coord.x - 1] == '0')
		move_left(map);
	else if (map->map[map->play_coord.y][map->play_coord.x - 1] == 'C')
	{
		move_left(map);
		map->coin--;
	}
	else if (map->map[map->play_coord.y][map->play_coord.x - 1] == 'E' &&
		map->coin == 0)
		end_game();
	else if (map->map[map->play_coord.y][map->play_coord.x - 1] == 'X')
		end_game();
}
