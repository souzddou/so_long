/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:33:44 by souzddou          #+#    #+#             */
/*   Updated: 2024/03/11 03:51:20 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/so_long.h"

void	entre_map(char *map)
{
	int		fd;
	char	*line;
	char	*join;
	char	**split;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	join = NULL;
	while (line)
	{
		join = ft_gnl_strjoin(join, line);
		line = get_next_line(fd);
	}
	split = ft_split(join, '\n');
	free(join);
	display_map(split, map);
	free_split(split);
	close(fd);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
		error_map("you need a map.\n", "no map");
	if (ac > 2)
		error_map("you need just one map.\n", "no map");
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		error_map("map have a wrong extention.\n", av[1]);
	// valid_map(av[1]);
	entre_map(av[1]);
	return (0);
}

void draw_map(t_vars *vars)
{
	vars->j = 0;
	while(vars->j < HM)
	{
		vars->i = 0;
		while(vars->i < WM)
		{
            void *img = NULL;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->chars.space, vars->i * S, vars->j * S);
            if (vars->map[vars->j][vars->i] == '1')
			{
				bool u, d, l, r;
				u = d = l = r = true;
				if (!vars->j || vars->map[vars->j - 1][vars->i] == '1')
					u = false;
				if (!vars->i || vars->map[vars->j][vars->i - 1] == '1')
					l = false;
				if (vars->j + 1 == HM || vars->map[vars->j + 1][vars->i] == '1')
					d = false;
				if (vars->i + 1 == WM || vars->map[vars->j][vars->i + 1] == '1')
					r = false;
				img = getWall(u, d, l, r, vars);
			}
			c_c(vars, img, vars->i, vars->j);
			vars->i++;
        }
		vars->j++;
    }
	// draw_score(vars);
}
