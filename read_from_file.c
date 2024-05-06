/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:54:47 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/05 18:31:24 by souzddou         ###   ########.fr       */
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
	char	*s;
	int		i;
	char	*rd;
	char	**strs;

	rd = NULL;
	i = 0;
	s = ft_strdup("");
	while (s)
	{
		rd = ft_strjoin(rd, s);
		free(s);
		s = get_next_line(fd);
		i++;
	}
	strs = ft_split(rd, '\n');
	free(rd);
	vars->map = strs;
	vars->wm = ft_lenwidth(vars);
	vars->hm = ft_lenheight(vars);
}
