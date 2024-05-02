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

typedef struct	s_vars {
	int	fd;
	char	*line;
	void	*mlx;
	void	*win;
	int map_index;
	t_char chars;
	int index;
	int count;
	char **map;
    int x_player_p;
    int y_player_p;
	void	*file;
	int height;
	int width;
	int			moves;
	int i;
	int j;
}				t_vars;



#endif