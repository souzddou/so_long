/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:20:46 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/03 14:32:19 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int ft_count_C(char map[WM][HM])
{
    int count;
	int x;
	int y;

	count = 0;
	y = 0;
    while (y < HM)
	{
		x = 0;
		while ( x < WM)
		{
            if (map[x][y] == 'C')
                count++;
			x++;
		}
		y++;
    }
    return count;
}

void init_player_pos(t_vars *vars)
{
	int y;
	int x;
	y = 0;
	while (y < HM)
	{
        x = 0;
		while (x < WM)
		{
			if (vars->map[y][x] == 'P')
			{
				vars->x_player_p = x;
				vars->y_player_p = y;
			}
			x++;
		}
		y++;
	}
}

int	ft_len(t_vars	*vars)
{
	int	i;

	i = 0;
	while (vars->map[i] != NULL)
		i++;
	return (i);
}

int	ft_lenv2(t_vars	*vars)
{
	int i;
	int j;

	i = 0;
	while(vars->map[i])
	{
		j = 0;
		while(vars->map[i][j])
		{
			j++;
		}
		i++;
	}
	return (j);
}

void	print_error(char	*s)
{
	printf("%s", s);
    exit(1);
}