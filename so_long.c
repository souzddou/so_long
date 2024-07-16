/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:08:48 by souzddou          #+#    #+#             */
/*   Updated: 2024/07/03 15:03:02 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_check_spacee(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '\n')
	{
		free(s);
		print_error("Eroor");
	}
	i = 1;
	while (s[i])
	{
		if ((s[i] == '\n' && s[i + 1] == '\n'))
		{
			free(s);
			print_error("Eroor");
		}
		i++;
	}
	if (s[i - 1] == '\n')
	{
		free(s);
		print_error("Eroor");
	}
}

int	ft_check_extension(char *map_name)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	if (!map_name)
		return (1);
	while (map_name[i])
	{
		if (map_name[i] == '.' && map_name[i + 1] == '.')
			a++;
		if (a == 1)
			print_error("Eroor");
		if (map_name[i] == '.' && map_name[i + 1] == 'b' && map_name[i
				+ 2] == 'e'
			&& map_name[i + 3] == 'r' && map_name[i + 4] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	game(char *s)
{
	t_vars	vars;
	int		fd;

	vars.coins = 0;
	vars.moves = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
		print_error("Error");
	read_from_file(&vars, fd);
	vars.wm = ft_lenwidth(&vars);
	vars.hm = ft_lenheight(&vars);
	parsing(&vars);
	vars.coins = 0;
	display_map(vars);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (ft_check_extension(av[1]) == 1)
		print_error("Eroor");
	game(av[1]);
}
