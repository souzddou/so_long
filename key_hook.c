/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:06:18 by souzddou          #+#    #+#             */
/*   Updated: 2024/06/27 22:08:47 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	print_moves(int x, int y, t_vars *vars)
{
	if (x != vars->prev_x || y != vars->prev_y)
	{
		vars->moves++;
		ft_printf("Moves : %d\n", vars->moves);
	}
}

void	mini_check(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] != '1' && vars->map[y][x] != 'E')
	{
		if (vars->map[y][x] == 'C')
		{
			vars->map[y][x] = '0';
			vars->coins--;
		}
		vars->x_player_p = x;
		vars->y_player_p = y;
		print_moves(x, y, vars);
	}
	if (vars->map[y][x] == 'E' && vars->coins == 0)
	{
		ft_printf("Moves : %d\n", vars->moves + 1);
		ft_printf("Congrats Mr You Win");
		free_map(vars->map, vars->hm);
		cleanup_images(vars);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(1);
	}
}

void	extra_fun(t_vars *vars, int x, int y, int keycode)
{
	int	new_x;
	int	new_y;

	new_y = y;
	new_x = x;
	mini_check(vars, new_x, new_y);
	if (keycode == 65307)
	{
		free_map(vars->map, vars->hm);
		cleanup_and_exit(vars);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(1);
	}
}

void	check_keycode(t_vars *vars, int keycode)
{
	int	new_x;
	int	new_y;

	new_x = vars->x_player_p;
	new_y = vars->y_player_p;
	vars->prev_x = vars->x_player_p;
	vars->prev_y = vars->y_player_p;
	if (keycode == 'd')
	{
		vars->index = 0;
		new_x++;
	}
	if (keycode == 'w')
		new_y--;
	if (keycode == 's')
		new_y++;
	if (keycode == 'a')
	{
		vars->index = 1;
		new_x--;
	}
	extra_fun(vars, new_x, new_y, keycode);
}

int	key_hook(int keycode, t_vars *vars)
{
	check_keycode(vars, keycode);
	mlx_clear_window(vars->mlx, vars->win);
	draw_map(vars);
	return (0);
}
