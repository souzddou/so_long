/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:22:23 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/02 16:26:13 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void m_m(t_vars *vars, void *img, int a, int b)
{
	if (a == vars->x_player_p && b == vars->y_player_p)
		img = vars->chars.player[vars->index];
	if (img)
			{
                int cy;
				if (vars->map[b][a] == 'C')
					cy = 11;
				else
					cy = 0;
                int cx;
				if (vars->map[b][a] == 'C')
					cx = 11;
				else
					cx = 0;
                mlx_put_image_to_window(vars->mlx, vars->win, img, a * S + cx, b * S + cy);
            }
}

void c_c(t_vars *vars, void *img, int x, int y)
{

	
	if (vars->map[y][x] == 'C')
				img = vars->chars.gain;
            if (x == vars->x_player_p && y == vars->y_player_p)
				img = vars->chars.player[vars->index];
            if (vars->map[y][x] == 'E')
				img = vars->chars.door;
			m_m(vars, img, x, y);
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
			mlx_put_image_to_window(vars->mlx, vars->win, vars->chars.space, (vars->i) * S, (vars->j) * S);
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
}
