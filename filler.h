#ifndef FILLER_H
# define FILLER_H

#include "gnl/libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct s_game
{
	char	player;
	int	rows;
	int	cols;
	int	piece_y;
	int	piece_x;
	char	piece[100][100];
	char	board[1000][1000];
	int	heatmap[100][100];
}	t_game;

typedef struct s_pos
{
	int	y;
	int	x;
	int	heat;
}	t_pos;

int	parsenum(t_game *gameinfo, char c);
void	player(t_game *gameinfo);
void	size(t_game *gameinfo);
void	board(t_game *gameinfo);
void	map_piece(t_game *gameinfo);
void	piece(t_game *gameinfo);
void	setheatmap(t_game *gameinfo);
void	fillheatmap(int heatmap[100][100], int starty, int startx);
void	createheatmap(t_game *gameinfo);

#endif

