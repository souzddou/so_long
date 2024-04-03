/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:56:48 by souzddou          #+#    #+#             */
/*   Updated: 2024/03/12 03:45:50 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"includes/so_long.h"

void	init_enemy(t_vars*vars)
{
	vars->enemy = malloc(sizeof(t_enemy));
	get_enemy_cords(vars);
	vars->enemy->img = mlx_xpm_file_to_image(vars->mlx,
			ENEMY_LEFT,
			&vars->mapp->img_width, &vars->mapp->img_height);
}

void	get_enemy_cords(t_vars  *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->mapp->height)
	{
		j = 0;
		while (j < vars->mapp->width)
		{
			if (vars->mapp->matrix[i][j] == 'N')
			{
				vars->enemy->x = j;
				vars->enemy->y = i;
				vars->enemy->count++;
			}
			j++;
		}
		i++;
	}
}

static int	check_player(t_vars*vars)
{
	if (vars->win)
	{
		if ((vars->player->x == vars->enemy->x + 1 && vars->player->y
				== vars->enemy->y)
			|| (vars->player->x == vars->enemy->x - 1 && vars->player->y
				== vars->enemy->y)
			|| (vars->player->x == vars->enemy->x && vars->player->y
				== vars->enemy->y))
			printf("You lose!\n");
	}
	return (0);
}

static void	move(t_vars*vars, int left, int right)
{
	if (left)
	{
		animate_enemy(vars, 1);
		vars->enemy->dir = 1;
		check_player(vars);
		if (vars->mapp->matrix[vars->enemy->y][vars->enemy->x + 1] == 'C')
			vars->mapp->coins_counter++;
		vars->mapp->matrix[vars->enemy->y][vars->enemy->x + 1] = 'N';
		vars->mapp->matrix[vars->enemy->y][vars->enemy->x] = '0';
		vars->enemy->x++;
	}
	else if (right)
	{
		animate_enemy(vars, 0);
		vars->enemy->dir = 0;
		check_player(vars);
		if (vars->mapp->matrix[vars->enemy->y][vars->enemy->x - 1] == 'C')
			vars->mapp->coins_counter++;
		vars->mapp->matrix[vars->enemy->y][vars->enemy->x - 1] = 'N';
		vars->mapp->matrix[vars->enemy->y][vars->enemy->x] = '0';
		vars->enemy->x--;
	}
}

void	move_enemy(t_vars*vars)
{
	if (vars->enemy->mov_right && vars->mapp->matrix[vars->enemy->y]
		[vars->enemy->x + 1] != '1'
		&& vars->mapp->matrix[vars->enemy->y][vars->enemy->x + 1] != 'E')
		move(vars, 1, 0);
	else
	{
		check_player(vars);
		vars->enemy->mov_right = 0;
		vars->enemy->mov_left = 1;
	}
	if (vars->enemy->mov_left && vars->mapp->matrix[vars->enemy->y]
		[vars->enemy->x - 1] != '1'
		&& vars->mapp->matrix[vars->enemy->y][vars->enemy->x - 1] != 'E')
		move(vars, 0, 1);
	else
	{
		check_player(vars);
		vars->enemy->mov_right = 1;
		vars->enemy->mov_left = 0;
	}	
}