/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:08:48 by souzddou          #+#    #+#             */
/*   Updated: 2024/03/13 05:13:44 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main() 
{
    t_vars  vars;

    int fd = open("map.bar", O_RDONLY);
	if (fd < 0)
		return (0);
    
    read_from_file(&vars, fd);
    // printf("%d",parsing(&vars));
    display_map(vars);

    return 0;

}
