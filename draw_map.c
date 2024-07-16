/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:22:23 by souzddou          #+#    #+#             */
/*   Updated: 2024/06/27 22:12:04 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	put_in_medium(t_vars *vars, void *img, int a, int b)
{
	int	cy;
	int	cx;

	if (img)
	{
		if (vars->map[b][a] == 'C')
			cy = 11;
		else
			cy = 0;
		if (vars->map[b][a] == 'C')
			cx = 11;
		else
			cx = 0;
		mlx_put_image_to_window(vars->mlx, vars->win, img, a * S + cx, b * S
			+ cy);
	}
}

void	check_image(t_vars *vars, void *img, int x, int y)
{
	if (vars->map[y][x] == 'C')
	{
		img = vars->chars.gain;
	}
	if (x == vars->x_player_p && y == vars->y_player_p)
		img = vars->chars.player[vars->index];
	if (vars->map[y][x] == 'E')
		img = vars->chars.door;
	if (x == vars->x_player_p && y == vars->y_player_p)
		img = vars->chars.player[vars->index];
	put_in_medium(vars, img, x, y);
}

void	extra_draw(t_vars *vars, t_walls *charr)
{
	(void)charr;
	charr->u = 1;
	charr->d = 1;
	charr->l = 1;
	charr->r = 1;
	if (!vars->j || vars->map[vars->j - 1][vars->i] == '1')
		charr->u = 0;
	if (!vars->i || vars->map[vars->j][vars->i - 1] == '1')
		charr->l = 0;
	if (vars->j + 1 == vars->hm || vars->map[vars->j + 1][vars->i] == '1')
		charr->d = 0;
	if (vars->i + 1 == vars->wm || vars->map[vars->j][vars->i + 1] == '1')
		charr->r = 0;
}

void	draw_map(t_vars *vars)
{
	t_walls	charr;
	void	*img;

	vars->j = 0;
	while (vars->j < vars->hm)
	{
		vars->i = 0;
		while (vars->i < vars->wm)
		{
			img = NULL;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->chars.space,
				(vars->i) * S, (vars->j) * S);
			if (vars->map[vars->j][vars->i] == '1')
			{
				extra_draw(vars, &charr);
				img = getwall(vars, charr);
			}
			check_image(vars, img, vars->i, vars->j);
			vars->i++;
		}
		vars->j++;
	}
}
