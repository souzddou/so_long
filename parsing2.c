/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:56:42 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/07 12:48:08 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_checkwallv0(t_vars *vars)
{
	int	i;

	i = 1;
	while (i < ft_lenheight(vars) - 1)
	{
		if (vars->map[i][0] != '1')
		{
			free_map(vars->map, vars->hm);
			print_error("is not closed1");
		}
		i++;
	}
	i = 0;
	while (vars->map[0][i])
	{
		if (vars->map[0][i] != '1')
		{
			free_map(vars->map, vars->hm);
			print_error("is not closed2");
		}
		i++;
	}
}

void	ft_checkwallv1(t_vars *vars)
{
	int	i;
	int	len;

	len = ft_lenheight(vars) - 1;
	i = 0;
	while (vars->map[len][i])
	{
		if (vars->map[len][i] != '1')
		{
			free_map(vars->map, vars->hm);
			print_error("is not closed3");
		}
		i++;
	}
	i = 1;
	while (i < ft_lenheight(vars) - 1)
	{
		if (vars->map[i][ft_strlen(vars->map[0]) - 1] != '1')
		{
			free_map(vars->map, vars->hm);
			print_error("is not closed4");
		}
		i++;
	}
}

int	is_rectangular(t_vars *vars)
{
	int	i;

	i = 1;
	while (i < vars->hm)
	{
		if (ft_lenwidth1(vars->map[i]) != vars->wm)
			return (0);
		i++;
	}
	return (1);
}

void	check(t_vars *vars)
{
	if (is_rectangular(vars) == 0)
	{
		free_map(vars->map, vars->hm);
		print_error("the map is not rectangular");
	}
}

void	parsing2(t_vars *vars)
{
	check(vars);
	ft_checkwallv0(vars);
	ft_checkwallv1(vars);
}
