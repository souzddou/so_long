/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:25:45 by souzddou          #+#    #+#             */
/*   Updated: 2024/03/07 10:26:11 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void *getWall(bool u, bool d, bool l, bool r, t_vars *vars)
{
	if (u && d && l && r)
		return vars->chars.wall4;
	if (u && l && r)
		return vars->chars.wall3[0];
	if (u && d && r)
		return vars->chars.wall3[1];
	if (d && l && r)
		return vars->chars.wall3[2];
	if (u && l && d)
		return vars->chars.wall3[3];
	
	if (u && l)
		return vars->chars.wall2[0];
	if (u && r)
		return vars->chars.wall2[1];
	if (r && d)
		return vars->chars.wall2[2];
	if (d && l)
		return vars->chars.wall2[3];

	if (u && d)
		return vars->chars.wall_2[0];
	if (l && r)
		return vars->chars.wall_2[1];

	if (u)
		return vars->chars.wall1[0];
	if (r)
		return vars->chars.wall1[1];
	if (d)
		return vars->chars.wall1[2];
	if (l)
		return vars->chars.wall1[3];
	return vars->chars.wall;
}