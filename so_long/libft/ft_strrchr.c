/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evalorie <evalorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:00:22 by evalorie          #+#    #+#             */
/*   Updated: 2022/07/26 15:00:23 by evalorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pointer;

	pointer = (char *)s + ft_strlen((char *)s);
	while (*pointer != (unsigned char)c)
	{
		if (pointer == (char *)s)
			return (NULL);
		pointer--;
	}
	return (pointer);
}
