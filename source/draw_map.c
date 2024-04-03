/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:22:23 by souzddou          #+#    #+#             */
/*   Updated: 2024/03/13 06:42:37 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void m_m(t_vars *vars, void *img, int a, int b)
{
	if (a == vars->x_player_p && b == vars->y_player_p)
		img = vars->chars.player[vars->index];
	if (img)
			{
                int cy;
				if (vars->map[b][a] == 'C')
					cy = 11;
				else
					cy = 0;
                int cx;
				if (vars->map[b][a] == 'C')
					cx = 11;
				else
					cx = 0;
                mlx_put_image_to_window(vars->mlx, vars->win, img, a * S + cx, b * S + cy);
            }
}

void c_c(t_vars *vars, void *img, int x, int y)
{

	
	if (vars->map[y][x] == 'C')
				img = vars->chars.gain;
            if (x == vars->x_player_p && y == vars->y_player_p)
				img = vars->chars.player[vars->index];
            if (vars->map[y][x] == 'E')
				img = vars->chars.door;
			if (vars->map[y][x] == 'O')
			{
				vars->enemy->y = y;
				vars->enemy->x = x;
				img = vars->chars.enemyy;
			}
			m_m(vars, img, x, y);
}

// static char	*if_positive(int n, int count)
// {
// 	char	*str;

// 	str = (char *)malloc(sizeof(char) * (count + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	str[count] = '\0';
// 	while (count)
// 	{
// 		str[--count] = (n % 10) + '0';
// 		n /= 10;
// 	}
// 	return (str);
// }

// size_t	getlen(int n)
// {
// 	size_t	len;

// 	if (n == 0)
// 		return (1);
// 	len = 0;
// 	while (n)
// 	{
// 		n /= 10;
// 		len++;
// 	}
// 	return (len);
// }

// char	*ft_itoa(int n)
// {
// 	unsigned int	num;
// 	char			*str;
// 	int				count;

// 	str = NULL;
// 	count = getlen(n);
// 	if (n < 0)
// 	{
// 		str = (char *)malloc(sizeof(char) * (count + 2));
// 		if (str == NULL)
// 			return (NULL);
// 		num = n * -1;
// 		str[count + 1] = '\0';
// 		while (count)
// 		{
// 			str[count] = (num % 10) + '0';
// 			count--;
// 			num /= 10;
// 		}
// 		str[0] = '-';
// 		return (str);
// 	}
// 	return (if_positive(n, count));
// }

// void draw_score(t_vars *vars)
// {
//     int x;
//     int y;
//     char *moves;

//     moves = ft_itoa(vars->moves);
//     x = 3 * S + S/2;
//     y = S / 2;
//     mlx_string_put(vars->mlx, vars->win, x, y, 0xE1CEFF, "Moves: ");
//     mlx_string_put(vars->mlx, vars->win, x + 45, y, 0xE1CEFF, moves);

//     free(moves);
// }



// int	create_map(char *map_path, t_vars *vars)
// {

// 	vars->fd = open(map_path, O_RDONLY);
// 	if (vars->fd == -1)
// 		return (0);
// 	while ((vars->line = get_next_line(vars->fd)))
// 	{
// 		vars->map[vars->j] = ft_strdup(vars->line);
// 		free(vars->line);
// 		vars->j++;
// 	}
// 	vars->map[vars->j] = NULL;
// 	free(vars->line);
// 	close(vars->fd);
// 	return (1);
// }

void draw_map(t_vars *vars)
{
	vars->j = 0;
	while(vars->j < HM)
	{
		vars->i = 0;
		while(vars->i < WM)
		{
            void *img = NULL;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->chars.space, (vars->i) * S, (vars->j) * S);
            if (vars->map[vars->j][vars->i] == '1')
			{
				bool u, d, l, r;
				u = d = l = r = true;
				if (!vars->j || vars->map[vars->j - 1][vars->i] == '1')
					u = false;
				if (!vars->i || vars->map[vars->j][vars->i - 1] == '1')
					l = false;
				if (vars->j + 1 == HM || vars->map[vars->j + 1][vars->i] == '1')
					d = false;
				if (vars->i + 1 == WM || vars->map[vars->j][vars->i + 1] == '1')
					r = false;
				img = getWall(u, d, l, r, vars);
			}
			c_c(vars, img, vars->i, vars->j);
			vars->i++;
        }
		vars->j++;
    }
	// draw_score(vars);
}
