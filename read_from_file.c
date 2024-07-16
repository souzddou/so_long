/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:54:47 by souzddou          #+#    #+#             */
/*   Updated: 2024/07/03 11:25:04 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!line)
	{
		line = (char *)malloc(1 * sizeof(char));
		line[0] = '\0';
	}
	if (!line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(line) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (line)
		while (line[++i] != '\0')
			str[i] = line[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(line) + ft_strlen(buff)] = '\0';
	free(line);
	return (str);
}

void	read_from_file(t_vars *vars, int fd)
{
	char	*str;
	char	*res;
	char	**strs;

	str = get_next_line(fd);
	if (!str)
		print_error("Eroor");
	res = ft_strdup("");
	while (str)
	{
		res = ft_strjoin(res, str);
		free(str);
		str = get_next_line(fd);
	}
	ft_check_spacee(res);
	strs = ft_split(res, '\n');
	free(res);
	vars->map = strs;
}

void	ft_map_v2(char **map, t_vars *vars)
{
	int		i;
	char	**copy;

	copy = NULL;
	i = 0;
	copy = (char **)malloc(sizeof(char *) * (vars->hm + 1));
	while (i < vars->hm)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	vars->mapv2 = copy;
}

void	check_image_fail(void *s)
{
	if (!s)
		print_error("Error");
}
