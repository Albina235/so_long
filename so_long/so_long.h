/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <evalorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:40:42 by evalorie          #+#    #+#             */
/*   Updated: 2022/07/26 14:40:43 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>

//img
# define WALL	"img/wall.xpm"
# define FLOOR	"img/floor.xpm"
# define PLAYER	"img/rabbit.xpm"
# define EXIT	"img/door.xpm"
# define COIN1	"img/carrot1.xpm"
# define COIN2	"img/carrot2.xpm"
# define ENEMY	"img/fire.xpm"

// keys
# define ESC	53
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2

# define IMG_X	40
# define IMG_Y	40

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*coin;
	void	*coin1;
	void	*coin2;
	void	*fire;
}			t_img;

typedef struct s_map
{
	void		*mlx;
	void		*win;
	char		**map;
	int			length;
	int			width;
	int			coin;
	int			steps;
	int			enemy;
	t_vector	play_coord;
	t_vector	enem_coord[10];
	t_img		img;
}				t_map;

/*keys.c*/
int		draw_map(t_map *map);
int		keys(int key, t_map *map);
void	steps(t_map *map);
int		end_game(void);

/*move_up_down.c*/
void	move_player_up(t_map *map);
void	move_player_down(t_map *map);

/*move_left_right*/
void	move_player_right(t_map *map);
void	move_player_left(t_map *map);

/*parser_errors*/
void	check_argc(int ac, char **av);
void	ft_error(char *str);
void	error_fd(void);
void	free_map(t_map *map);

/*parser_chek*/
void	check_map_whole(t_map *map, char *av);
void	check_map_line(t_map *map);
void	init_player(t_map *map, int i, int j, int *p);
void	check_map_arg(t_map *map, int i, int j);
void	check_map_border(t_map *map, int i, int j);

/*parser_init*/
char	*get_line(char **av);
t_map	*init_map(char *line);
void	init_sprites(t_map *map);
void	init_enemy(t_map *map);

#endif
