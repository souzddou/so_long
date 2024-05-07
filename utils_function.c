/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:20:46 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/07 13:47:45 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_count_c(t_vars *vars)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (y < vars->hm)
	{
		x = 0;
		while (x < vars->wm)
		{
			if (vars->map[x][y] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	init_player_pos(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->hm)
	{
		x = 0;
		while (x < vars->wm)
		{
			if (vars->map[y][x] == 'P')
			{
				vars->x_player_p = x;
				vars->y_player_p = y;
			}
			if (vars->map[y][x] == 'C')
				vars->coins++;
			x++;
		}
		y++;
	}
}

int	ft_lenheight(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i] != NULL)
		i++;
	return (i);
}

int	ft_lenwidth(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			j++;
		}
		i++;
	}
	return (j);
}

void	print_error(char *s)
{
	ft_printf("%s", s);
	exit(1);
}
