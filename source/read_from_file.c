/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:54:47 by souzddou          #+#    #+#             */
/*   Updated: 2024/03/13 06:21:41 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"includes/so_long.h"

void    read_from_file(t_vars *vars, int fd)
{
    char *s;
    int i;

    i = 0;
    while ((s = get_next_line(fd)) && i < HM)
	{
        strcpy(vars->map[i], s);
		free(s);
        i++;
    }
}

// char	*ft_strdup(const char *str)
// {
// 	int		i;
// 	int		len;
// 	char	*new_str;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	new_str = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!(new_str))
// 		return (NULL);
// 	i = 0;
// 	while (str[i])
// 	{
// 		new_str[i] = str[i];
// 		i++;
// 	}
// 	new_str[i] = '\0';
// 	return (new_str);
// }

// int	create_map(t_vars *vars)
// {

// 	vars->fd = open("map.bar", O_RDONLY);
// 	if (vars->fd == -1)
// 		return (0);
	
//     char *s;
//     int i;

//     i = 0;
//     while ((s = get_next_line(vars->fd)) && i < HM)
// 	{               
//         strcpy(vars->line, s);  
// 		free(s);
//         i++;
//     }
	
//     while ((vars->line = get_next_line(vars->fd)))
// 	{
// 		vars->map[vars->j] = ft_strdup(vars->line);
// 		free(vars->line);
// 		vars->j++;
// 	}
// 	vars->map[vars->j] = NULL;
// 	free(vars->line);
// 	close(vars->fd);
// 	return (1);
// }