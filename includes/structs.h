/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:56:47 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/07 11:50:28 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>

# define S 45

typedef struct s_char
{
	void	*wall1[4];
	void	*wall2[4];
	void	*wall_2[2];
	void	*wall3[4];
	void	*wall4;
	void	*enemyy;
	void	*wall;
	void	*game_over;
	void	*space;
	void	*gain;
	void	*col;
	void	*door;
	void	*player[2];
}			t_char;

typedef struct s_vars
{
	int		fd;
	int		hm;
	int		wm;
	int		coins;
	char	*line;
	void	*mlx;
	void	*win;
	int		map_index;
	t_char	chars;
	int		index;
	int		count;
	char	**map;
	char	**mapv2;
	int		x_player_p;
	int		y_player_p;
	void	*file;
	int		height;
	int		width;
	int		moves;
	int		i;
	int		j;
}			t_vars;

typedef struct s_walls
{
	int		u;
	int		l;
	int		d;
	int		r;
}			t_walls;

#endif