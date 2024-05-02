/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:40:03 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/02 22:50:11 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"includes/so_long.h"

int check_chars(t_vars	*vars)
{
  int i;
  int j;

  i = 0;
while (vars->map[i])
{
	j = 0;
	while (vars->map[i][j])
	{
		if (vars->map[i][j] != 'E' && vars->map[i][j] != '1'
				&& vars->map[i][j] != 'P' && vars->map[i][j] != 'C' && vars->map[i][j] != '0')
				return(1);
		j++;
	}
	i++;
}
return(0);
}

int	ft_search(t_vars	*vars, char c)
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

void	check_missing(t_vars	*vars)
{
	if (ft_search(vars, 'E') || ft_search(vars, 'C')
		|| ft_search(vars, 'P') || ft_search(vars, '1'))
		{
			print_error("character is missing");
		}
}

void    parsing(t_vars  *vars)
{
	parsing2(vars);
	check_missing(vars);
	if (check_chars(vars) == 1)
		{
			print_error("foreign character");
		}
}