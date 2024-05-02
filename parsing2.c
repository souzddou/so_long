/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:56:42 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/02 22:49:18 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"includes/so_long.h"

void	ft_check_duplication(t_vars *vars)
{
	static int	player;
	static int	Ex;
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
				Ex++;
			if (player > 1 || Ex > 1)
			{
				printf("there is a duplicate character");
                exit(1);
			}
			j++;
		}
		i++;
	}
}

void    ft_checkwallv0(t_vars   *vars)
{
    int	i;

	i = 1;
	while (i < ft_len(vars) - 1)
	{
		if (vars->map[i][0] != '1')
		{
			print_error("is not closed1");
		}
        if (vars->map[0][i] != '1')
        {
            print_error("is not closed2");
        }
		i++;
	}
}

void	ft_checkwallv1(t_vars    *vars)
{
	int	i;
    int len;
	
    len = ft_len(vars) - 1;
    i = 0;
    while (vars->map[len][i])
    {
		if (vars->map[len][i] != '1')
		{
			print_error("is not closed3");
		}
        i++;
    }
    i = 1;
    while (i < ft_len(vars) - 1)
	{
		if (vars->map[i][ft_strlen(vars->map[0])] != '1')
		{
			print_error("is not closed4");
		}
		i++;
	}
   
}

void    parsing2(t_vars *vars)
{
    ft_check_duplication(vars);
    ft_checkwallv0(vars);
    ft_checkwallv1(vars);
}