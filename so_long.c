/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:08:48 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/02 22:53:21 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main(int ac, char **av) 
{
    t_vars  vars;

    if (ac != 2)
    {
        printf("Error\nArguments not valid!");
        return (1);
    }
    int fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
    read_from_file(&vars, fd);
    parsing(&vars);
    display_map(vars);

    return 0;
}

