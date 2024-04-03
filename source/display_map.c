/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:47:47 by souzddou          #+#    #+#             */
/*   Updated: 2024/03/13 05:09:49 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"includes/so_long.h"

// int	update(t_vars *vars)
// {
// 	if (!vars)
// 		exit(0);
// 	if (vars->enemy->count)
// 		move_enemy(vars);
// 	animate_enemy(vars, vars->enemy->dir);
// 	mlx_clear_window(vars->mlx, vars->win);
// 	draw_map(vars);
// 	return (0);
// }

void    display_map(t_vars  vars)
{
    
    vars.index = 0;

    vars.mlx = mlx_init();

    vars.win = mlx_new_window(vars.mlx, WM * 45 , HM * 45 , "aheesu");

    init_images(&vars);

	init_player_pos(&vars);
    // init_enemy(&vars);
	
	mlx_key_hook(vars.win, key_hook, &vars);
    // mlx_loop_hook((&vars)->mlx, update, &vars);
    mlx_loop(vars.mlx);
}