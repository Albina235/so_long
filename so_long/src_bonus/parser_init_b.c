/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <evalorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:54:16 by evalorie          #+#    #+#             */
/*   Updated: 2022/07/26 14:54:17 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_line(char **av)
{
	int		fd;
	char	*new_line;
	char	*line;
	char	*tmp;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "ERROR\n", 6);
		exit(EXIT_FAILURE);
	}
	new_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = new_line;
		new_line = ft_gnl_strjoin(new_line, line);
		free(tmp);
		free(line);
	}
	close(fd);
	return (new_line);
}

t_map	*init_map(char *line)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = ft_split(line, '\n');
	i = 0;
	while (map->map[i] != NULL)
		i++;
	map->width = i;
	map->length = ft_strlen(map->map[0]);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, IMG_X * map->length, \
											IMG_Y * map->width, "so_long");
	map->coin = 0;
	map->steps = 0;
	map->enemy = 0;
	free(line);
	return (map);
}

void	init_sprites(t_map *map)
{
	int	x;
	int	y;

	x = 40;
	y = 40;
	map->img.wall = mlx_xpm_file_to_image(map->mlx, WALL, &x, &y);
	map->img.floor = mlx_xpm_file_to_image(map->mlx, FLOOR, &x, &y);
	map->img.player = mlx_xpm_file_to_image(map->mlx, PLAYER, &x, &y);
	map->img.exit = mlx_xpm_file_to_image(map->mlx, EXIT, &x, &y);
	map->img.coin1 = mlx_xpm_file_to_image(map->mlx, COIN1, &x, &y);
	map->img.coin2 = mlx_xpm_file_to_image(map->mlx, COIN2, &x, &y);
	map->img.fire = mlx_xpm_file_to_image(map->mlx, ENEMY, &x, &y);
	if (!map->img.wall || !map->img.floor || !map->img.player || !map->img.exit \
			|| !map->img.exit || !map->img.coin1 || !map->img.coin2)
		ft_error("Can\'t open sprites file(\n");
	map->img.coin = map->img.coin2;
}

void	init_enemy(t_map *map)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'X')
			{
				map->enem_coord[k].x = j;
				map->enem_coord[k].y = i;
				k++;
			}
		}
	}
}
