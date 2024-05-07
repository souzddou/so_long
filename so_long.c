/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:08:48 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/07 11:59:51 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	game(char *s)
{
	t_vars	vars;
	int		fd;

	vars.coins = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
		return ;
	read_from_file(&vars, fd);
	parsing(&vars);
	vars.coins = 0;
	display_map(vars);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\nArguments not valid!");
		return (1);
	}
	(void)ac;
	game(av[1]);
}
