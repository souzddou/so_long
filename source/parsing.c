/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:40:03 by souzddou          #+#    #+#             */
/*   Updated: 2024/03/14 22:25:30 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"includes/so_long.h"

void	check_char_cond(char map, t_char *check, char *name)
{
	if (map != '0' && map != '1' && map != 'E'
		&& map != 'C' && map != 'P' && map != 'Y')
	{
		write(2, "character doesn't exist : ", 27);
		write(2, &map, 1);
		write(2, ".\n", 2);
		exit(1);
	}
	if (map == 'P' && !check->p)
		error_map("more than one player.\n", name);
	if (map == 'P' && check->p)
		check->p = 0;
	if (map == 'E' && check->e)
		check->e = 0;
	if (map == 'C' && check->c)
		check->c = 0;
}
