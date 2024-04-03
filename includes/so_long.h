#ifndef SO_LONG_H
#define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include"structs.h"
# include <stdlib.h>
# include <string.h>
// # include "libft/libft.h"
# include <fcntl.h>


typedef char bool;
#define true 1
#define false 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif


# define ENEMY_LEFT "./character/enemy.xpm"
# define ENEMY_RIGHT "./character/enemy.xpm"

void	init_enemy(t_vars *vars);
void	get_enemy_cords(t_vars *vars);
void	move_enemy(t_vars *vars);
void	animate_enemy(t_vars *vars, int dir);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int	update(t_vars *vars);


void    draw_map(t_vars *vars);
int    parsing(t_vars  *vars);
int key_hook(int	keycode, t_vars	*vars);
void    read_from_file(t_vars *vars, int fd);
void	init_images(t_vars	*vars);
void    display_map(t_vars  vars);
void	init_wall1(t_vars	*vars, int img_width, int img_height);
void    init_wall2(t_vars	*vars, int img_width, int img_height);
void	init_wall3(t_vars	*vars, int img_width, int img_height);
void	init_others(t_vars	*vars, int img_width, int img_height);
void    image_wall(t_vars vars, int img_width, int img_height);
int ft_count_C(char map[WM][HM]);
void    check_keycode(t_vars	*vars, int	keycode);
void    cleanup_images(t_vars *vars);
void    cleanup_and_exit(t_vars *vars);
void    init_player_pos(t_vars *vars);
void    *getWall(bool u, bool d, bool l, bool r, t_vars *vars);

#endif