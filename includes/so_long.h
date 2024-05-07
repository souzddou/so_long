/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:54:28 by souzddou          #+#    #+#             */
/*   Updated: 2024/05/07 13:26:46 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"
# include "structs.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define ENEMY_LEFT "./character/enemy.xpm"
# define ENEMY_RIGHT "./character/enemy.xpm"

void	free_map(char **map, int len);
void	free_mapv2(t_vars *vars);
void	ft_map_v2(char **map, t_vars *vars);
int		check_agharas(t_vars *vars);
int		ft_lenwidth1(char *s);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_lenheight(t_vars *vars);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
size_t	ft_strlen(char *s);
int		ft_lenwidth(t_vars *vars);
void	parsing2(t_vars *vars);
void	ft_bzero(void *s, size_t n);
void	parsing(t_vars *vars);
char	*ft_strdup(char *src);
void	print_error(char *s);
void	ft_check_space(char *str);

void	draw_map(t_vars *vars);
int		ft_strchr(const char *s, int c);
int		check_chars(t_vars *vars);
char	**ft_split(char const *s, char c);

int		key_hook(int keycode, t_vars *vars);
void	read_from_file(t_vars *vars, int fd);
void	init_images(t_vars *vars);
void	display_map(t_vars vars);
void	init_wall1(t_vars *vars, int img_width, int img_height);
void	init_wall2(t_vars *vars, int img_width, int img_height);
void	init_wall3(t_vars *vars, int img_width, int img_height);
void	init_others(t_vars *vars, int img_width, int img_height);
void	image_wall(t_vars vars, int img_width, int img_height);
int		ft_count_c(t_vars *vars);
void	check_keycode(t_vars *vars, int keycode);
void	cleanup_images(t_vars *vars);
void	cleanup_and_exit(t_vars *vars);
void	init_player_pos(t_vars *vars);
void	*getwall(t_vars *vars, t_walls charr);

#endif