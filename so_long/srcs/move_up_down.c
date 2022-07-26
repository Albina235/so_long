/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <evalorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:43:13 by evalorie          #+#    #+#             */
/*   Updated: 2022/07/26 14:43:18 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_map *map)
{
	map->map[map->play_coord.y - 1][map->play_coord.x] = 'P';
	map->map[map->play_coord.y][map->play_coord.x] = '0';
	map->play_coord.y--;
	steps(map);
}

void	move_player_up(t_map *map)
{
	if (map->map[map->play_coord.y - 1][map->play_coord.x] == '0')
		move_up(map);
	else if (map->map[map->play_coord.y - 1][map->play_coord.x] == 'C')
	{
		move_up(map);
		map->coin--;
	}
	else if (map->map[map->play_coord.y - 1][map->play_coord.x] == 'E' && \
			map->coin == 0)
		end_game();
}

void	move_down(t_map *map)
{
	map->map[map->play_coord.y + 1][map->play_coord.x] = 'P';
	map->map[map->play_coord.y][map->play_coord.x] = '0';
	map->play_coord.y++;
	steps(map);
}

void	move_player_down(t_map *map)
{
	if (map->map[map->play_coord.y + 1][map->play_coord.x] == '0')
		move_down(map);
	else if (map->map[map->play_coord.y + 1][map->play_coord.x] == 'C')
	{
		move_down(map);
		map->coin--;
	}
	else if (map->map[map->play_coord.y + 1][map->play_coord.x] == 'E' &&
			map->coin == 0)
		end_game();
}
