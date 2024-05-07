/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:40:03 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/07 14:35:01 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_check_duplication(t_vars *vars)
{
	static int	player;
	static int	ex;
	int			i;
	int			j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
				player++;
			else if (vars->map[i][j] == 'E')
				ex++;
			if (player > 1 || ex > 1)
			{
				free_map(vars->map, vars->hm);
				print_error("there is a duplicate character");
			}
			j++;
		}
		i++;
	}
}

int	check_chars(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] != 'E' && vars->map[i][j] != '1'
				&& vars->map[i][j] != 'P' && vars->map[i][j] != 'C'
				&& vars->map[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_find(t_vars *vars, char c)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == c)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_missing(t_vars *vars)
{
	if (ft_find(vars, 'E') || ft_find(vars, 'C') || ft_find(vars, 'P')
		|| ft_find(vars, '1'))
	{
		free_map(vars->map, vars->hm);
		print_error("character is missing");
	}
}

void	parsing(t_vars *vars)
{
	parsing2(vars);
	ft_check_duplication(vars);
	check_missing(vars);
	if (check_chars(vars) == 1)
	{
		free_map(vars->map, vars->hm);
		print_error("foreign character");
	}
	if (check_road(vars) == 1)
	{
		free_map(vars->map, vars->hm);
		free_map(vars->mapv2, vars->hm);
		print_error("there no way to exit");
	}
	free_map(vars->mapv2, vars->hm);
}
