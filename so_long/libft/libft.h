/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <evalorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:00:36 by evalorie          #+#    #+#             */
/*   Updated: 2022/07/26 15:01:55 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>

# define BUFFER_SIZE 100

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);

size_t	ft_gnl_strlen(const char *str);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strdup(const char *s1);
char	*get_next_line(int fd);

#endif
