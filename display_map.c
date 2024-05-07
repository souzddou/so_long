/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:47:47 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/07 12:48:53 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_exit(t_vars *vars)
{
	free_map(vars->map, vars->hm);
	cleanup_and_exit(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(1);
}

void	display_map(t_vars vars)
{
	vars.index = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (vars.wm) * 45, (vars.hm) * 45,
			"aheesu");
	init_images(&vars);
	init_player_pos(&vars);
	mlx_hook(vars.win, 17, 0, ft_exit, &vars);
	mlx_hook(vars.win, 2, 1, key_hook, &vars);
	draw_map(&vars);
	mlx_loop(vars.mlx);
}
