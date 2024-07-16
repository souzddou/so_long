/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:38:15 by souzddou          #+#    #+#             */
/*   Updated: 2024/06/27 22:08:51 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char	*ft_strdup(char *src)
{
	size_t	i;
	size_t	size;
	char	*ls;

	i = 0;
	size = 0;
	while (src[size] != '\0')
		size++;
	ls = malloc((size + 1) * sizeof(char));
	if (!ls)
		return (NULL);
	while (src[i] != '\0')
	{
		ls[i] = (char)src[i];
		i++;
	}
	ls[i] = '\0';
	return (ls);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return (1);
		}
		i++;
	}
	if ((char)c == s[i])
		return (1);
	return (0);
}

int	ft_lenwidth1(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	free_map(char **map, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
