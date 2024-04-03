/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:12:53 by souzddou          #+#    #+#             */
/*   Updated: 2024/03/07 10:13:06 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void cleanup_images(t_vars *vars) {
    int i = 0;
	if (vars->mlx)
	{
        if (vars->chars.wall) mlx_destroy_image(vars->mlx, vars->chars.wall);
        while (i < 4)
		{
            if (vars->chars.wall1[i]) mlx_destroy_image(vars->mlx, vars->chars.wall1[i]);
            if (vars->chars.wall2[i]) mlx_destroy_image(vars->mlx, vars->chars.wall2[i]);
            if (vars->chars.wall3[i]) mlx_destroy_image(vars->mlx, vars->chars.wall3[i]);
			i++;
        }
		i = 0;
        while (i < 2)
		{
			if (vars->chars.wall_2[i]) mlx_destroy_image(vars->mlx, vars->chars.wall_2[i]);
			i++;
		}
        if (vars->chars.wall4) mlx_destroy_image(vars->mlx, vars->chars.wall4);
		i = 0;
		while (i < 2)
		{
			if (vars->chars.player[i]) mlx_destroy_image(vars->mlx, vars->chars.player[i]);
			i++;
		}
        if (vars->chars.space) mlx_destroy_image(vars->mlx, vars->chars.space);
        if (vars->chars.gain) mlx_destroy_image(vars->mlx, vars->chars.gain);
        if (vars->chars.col) mlx_destroy_image(vars->mlx, vars->chars.col);
        if (vars->chars.door) mlx_destroy_image(vars->mlx, vars->chars.door);
    }
}

void cleanup_and_exit(t_vars *vars)
{
    cleanup_images(vars); 

}