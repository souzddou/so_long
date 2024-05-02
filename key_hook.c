/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:06:18 by souzddou          #+#    #+#             */
/*   Updated: 2024/03/14 02:34:09 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void mini_check(t_vars *vars, int x, int y)
{	
	if (vars->map[y][x] != '1')
	{
		if (vars->map[y][x] == 'C')
		{
			vars->map[y][x] = '0';
		}
		vars->x_player_p = x;	
        vars->y_player_p = y;
    }
	if (vars->map[y][x] == 'O')
	{
		printf("sorry, you lose");
		exit(1);	
	}	
	if (vars->map[y][x] == 'E' )
	{
		printf("congrats mr you win");
		cleanup_images(vars);
        mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
        free(vars->mlx);
		exit(1);
	}
}

void	check_keycode(t_vars	*vars, int	keycode)
{
	int new_x = vars->x_player_p;
	int new_y = vars->y_player_p;

	if (keycode == 'd')
	{	
		vars->index = 0;
		new_x++;
	}
	if (keycode == 'w')new_y--;
	if (keycode == 's') new_y++;
	if (keycode == 'a') 
	{	
		vars->index = 1;
		new_x--;
	}
	mini_check(vars, new_x, new_y);
	if (keycode == 65307)
	{
		cleanup_and_exit(vars);
        mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
        free(vars->mlx);
		exit(1);
	}
}

int	key_hook(int	keycode, t_vars	*vars)
{
	check_keycode(vars, keycode);
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
	return (0);
}