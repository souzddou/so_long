/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_agharas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:12:30 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/07 13:47:23 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:43:58 by mnachit           #+#    #+#             */
/*   Updated: 2024/02/17 13:48:42 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	ft_flood_fill(int x, int y, t_vars *vars)
{
	if (x < 0 || x >= 9 || y < 0 || y >= 25 || vars->mapv2[x][y] == '1'
		|| vars->mapv2[x][y] == 'E' || vars->mapv2[x][y] == 'V')
		return ;
	vars->mapv2[x][y] = 'V';
	ft_flood_fill(x - 1, y, vars);
	ft_flood_fill(x + 1, y, vars);
	ft_flood_fill(x, y - 1, vars);
	ft_flood_fill(x, y + 1, vars);
}

static int	path_to_exit(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->mapv2[i])
	{
		j = 0;
		while (vars->mapv2[i][j])
		{
			if (vars->mapv2[i][j] == 'C')
				return (1);
			if (vars->mapv2[i][j] == 'E' && (vars->mapv2[i - 1][j] != 'V'
					&& vars->mapv2[i + 1][j] != 'V' && vars->mapv2[i][j
					- 1] != 'V' && vars->mapv2[i][j + 1] != 'V'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_agharas(t_vars *vars)
{
	ft_map_v2(vars->map, vars);
	vars->x_player_p = 0;
	vars->y_player_p = 0;
	init_player_pos(vars);
	ft_flood_fill(vars->y_player_p, vars->x_player_p, vars);
	if (path_to_exit(vars) == 1)
		return (1);
	return (0);
}
