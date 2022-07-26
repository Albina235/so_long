/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <evalorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:51:15 by evalorie          #+#    #+#             */
/*   Updated: 2022/07/26 14:51:16 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_argc(int ac, char **av)
{
	if (ac != 2)
	{
		write (1, "Wrong number of arguments.\n", 27);
		exit(EXIT_SUCCESS);
	}
	if (ft_strrchr(av[1], '/') && ft_strlen(ft_strrchr(av[1], '/')) <= 5)
	{
		write (1, "It\'s not a map.\n", 15);
		exit(EXIT_SUCCESS);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
	{
		write (1, "Use files with \'ber\' extension.\n", 33);
		exit(EXIT_SUCCESS);
	}
	if (open(av[1], O_DIRECTORY) != -1)
	{
		write(1, "ERROR! Can\'t open file(((\n", 26);
		exit(EXIT_FAILURE);
	}
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_SUCCESS);
}

void	error_fd(void)
{
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(".\n", 2);
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
		free(map->map[i]);
	free(map->map);
	free(map);
}
