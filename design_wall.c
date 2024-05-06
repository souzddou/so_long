/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:25:45 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/04 18:38:55 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	*f1(t_vars *vars, t_walls charr)
{
	if (charr.u)
		return (vars->chars.wall1[0]);
	if (charr.r)
		return (vars->chars.wall1[1]);
	if (charr.d)
		return (vars->chars.wall1[2]);
	if (charr.l)
		return (vars->chars.wall1[3]);
	return (NULL);
}

void	*f2(t_vars *vars, t_walls charr)
{
	if (charr.u && charr.l)
		return (vars->chars.wall2[0]);
	if (charr.r && charr.u)
		return (vars->chars.wall2[1]);
	if (charr.r && charr.d)
		return (vars->chars.wall2[2]);
	if (charr.d && charr.l)
		return (vars->chars.wall2[3]);
	if (charr.u && charr.d)
		return (vars->chars.wall_2[0]);
	if (charr.l && charr.r)
		return (vars->chars.wall_2[1]);
	return (NULL);
}

void	*f3(t_vars *vars, t_walls charr)
{
	if (charr.u && charr.l && charr.r)
		return (vars->chars.wall3[0]);
	if (charr.u && charr.d && charr.r)
		return (vars->chars.wall3[1]);
	if (charr.d && charr.l && charr.r)
		return (vars->chars.wall3[2]);
	if (charr.u && charr.l && charr.d)
		return (vars->chars.wall3[3]);
	return (NULL);
}

void	*f4(t_vars *vars, t_walls charr)
{
	if (charr.u && charr.l && charr.d && charr.r)
		return (vars->chars.wall4);
	return (NULL);
}

void	*getwall(t_vars *vars, t_walls charr)
{
	void	*res;

	res = NULL;
	res = f4(vars, charr);
	if (res)
		return (res);
	res = f3(vars, charr);
	if (res)
		return (res);
	res = f2(vars, charr);
	if (res)
		return (res);
	res = f1(vars, charr);
	if (res)
		return (res);
	return (vars->chars.wall);
}
