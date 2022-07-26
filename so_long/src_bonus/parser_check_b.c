/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <evalorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:50:05 by evalorie          #+#    #+#             */
/*   Updated: 2022/07/26 14:50:54 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_whole(t_map *map, char *av)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		error_fd();
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		i++;
		if (!line)
			break ;
		free(line);
	}
	if (i != map->width + 1)
		ft_error("empty lines in file(\n");
	close(fd);
}

void	check_map_line(t_map *map)
{
	char	*line;
	int		i;
	int		j;

	line = "01CPEX";
	i = -1;
	while (map->map[++i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!ft_strchr(line, map->map[i][j]))
				ft_error("invalid characters in the map(\n");
			j++;
		}
		if (map->length != j)
			ft_error("the map is\'t rectangual\n");
	}
}

void	init_player(t_map *map, int i, int j, int *p)
{
	map->play_coord.x = j;
	map->play_coord.y = i;
	*p += 1;
}

void	check_map_arg(t_map *map, int i, int j)
{
	int	player;
	int	ex;

	player = 0;
	ex = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
				init_player(map, i, j, &player);
			else if (map->map[i][j] == 'C')
				map->coin++;
			else if (map->map[i][j] == 'E')
				ex++;
			else if (map->map[i][j] == 'X')
				map->enemy++;
		}
	}
	if (player != 1 || map->coin <= 0 || ex <= 0)
		ft_error("invalid map(\n");
}

void	check_map_border(t_map *map, int i, int j)
{
	while (map->map[0][++j])
	{
		if (map->map[0][j] != '1')
			ft_error("border error(\n");
	}
	j = -1;
	while (map->map[map->width - 1][++j])
	{
		if (map->map[map->width - 1][j] != '1')
			ft_error("border error(\n");
	}
	while (map->map[++i] && i < map->width - 1)
	{
		if (map->map[i][0] != '1')
			ft_error("border error(\n");
		else if (map->map[i][map->length - 1] != '1')
			ft_error("border error(\n");
	}
}
