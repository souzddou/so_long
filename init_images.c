/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:59:45 by souzddou          #+#    #+#             */
/*   Updated: 2024/06/27 22:07:36 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_wall1(t_vars *vars, int img_width, int img_height)
{
	vars->chars.wall1[0] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/1/1.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.wall1[0]);
	vars->chars.wall1[1] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/1/2.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.wall1[1]);
	vars->chars.wall1[2] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/1/3.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.wall1[2]);
	vars->chars.wall1[3] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/1/4.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.wall1[3]);
}

void	init_wall2(t_vars *vars, int img_width, int img_height)
{
	vars->chars.wall2[0] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/2/1.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.wall2[0]);
	vars->chars.wall2[1] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/2/2.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.wall2[1]);
	vars->chars.wall2[2] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/2/3.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.wall2[2]);
	vars->chars.wall2[3] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/2/4.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.wall2[3]);
	vars->chars.wall_2[0] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/ud.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.wall_2[0]);
	vars->chars.wall_2[1] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/lr.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.wall_2[1]);
}

void	init_wall3(t_vars *vars, int img_width, int img_height)
{
	vars->chars.wall3[0] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/3/1.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.wall3[0]);
	vars->chars.wall3[1] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/3/2.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.wall3[1]);
	vars->chars.wall3[2] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/3/3.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.wall3[2]);
	vars->chars.wall3[3] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/3/4.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.wall3[3]);
}

void	init_others(t_vars *vars, int img_width, int img_height)
{
	vars->chars.space = mlx_xpm_file_to_image(vars->mlx, "textures/space.xpm",
			&img_width, &img_height);
	check_image_fail(vars->chars.space);
	vars->chars.gain = mlx_xpm_file_to_image(vars->mlx, "textures/gain.xpm",
			&img_width, &img_height);
	check_image_fail(vars->chars.gain);
	vars->chars.door = mlx_xpm_file_to_image(vars->mlx, "textures/door.xpm",
			&img_width, &img_height);
	check_image_fail(vars->chars.door);
	vars->chars.player[0] = mlx_xpm_file_to_image(vars->mlx,
			"textures/player.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.player[0]);
	vars->chars.player[1] = mlx_xpm_file_to_image(vars->mlx,
			"textures/W/os.xpm", &img_width, &img_height);
	check_image_fail(vars->chars.player[1]);
	vars->chars.wall4 = mlx_xpm_file_to_image(vars->mlx, "textures/W/4.xpm",
			&img_width, &img_height);
	check_image_fail(vars->chars.wall4);
}

void	init_images(t_vars *vars)
{
	int	img_width;
	int	img_height;

	vars->chars.wall = mlx_xpm_file_to_image(vars->mlx, "textures/wall1.xpm",
			&img_width, &img_height);
	check_image_fail(vars->chars.wall);
	check_image_fail(vars->chars.wall1);
	init_wall1(vars, img_width, img_height);
	init_wall2(vars, img_width, img_height);
	init_wall3(vars, img_width, img_height);
	init_others(vars, img_width, img_height);
}
