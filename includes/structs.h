#ifndef STRUCT_H
#define STRUCT_H

# include <mlx.h>
#include <unistd.h>
#include <fcntl.h>

#define WM 25
#define HM 9
#define S 45

typedef char bool;
#define true 1
#define false 0

typedef struct s_char 
{
	void *wall1[4];
	void *wall2[4];
	void *wall_2[2];
	void *wall3[4];
	void *wall4;
	void *enemyy;
    void *wall;
	void *game_over;
	void *space;
	void *gain;
	void *col;
	void *door;
	void *player[2];
}           t_char;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		mov_up;
	int		mov_down;
	int		mov_left;
	int		mov_right;
	void	*img;
	int		count;
	int		dir;
	t_list	sprites;
}				t_enemy;

// typedef struct s_map
// {
// 	int		fd;
// 	char	**matrix;
// 	char	*line;
// 	// void	*img_ptr;
// 	int		img_width;
// 	int		img_height;
// 	int		width;
// 	int		height;
// 	int		counter;
// 	int		x;
// 	int		y;
// 	int		coins;
// 	int		coins_counter;
// 	int		exits;
// 	void	*wall_img;
// 	void	*empty_img;
// 	void	*c_img;
// 	void	*exit_img;
// }				t_map;


// typedef struct s_player
// {
// 	int		x;
// 	int		y;
// 	int		score;
// 	int		count;
// 	void	*img;
// 	int		width;
// 	int		height;
// 	void	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	int		go_up;
// 	int		go_down;
// 	int		go_left;
// 	int		go_right;
// 	void	*img_up;
// 	void	*img_down;
// 	void	*img_left;
// 	void	*img_right;
// 	void	*img_closed;
// 	t_list	sprites;
// }				t_player;

typedef struct	s_vars {
	int	fd;
	char	*line;
	void	*mlx;
	void	*win;
	int map_index;
	t_char chars;
	int index;
	int count;
	char map[HM][WM];
    int x_player_p;
    int y_player_p;
	t_enemy	*enemy;
	void	*file;
	int height;
	int width;
	int			moves;
	int i;
	int j;
}				t_vars;



#endif