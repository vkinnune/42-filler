#include "filler.h"

void	setheatmap(t_game *gameinfo)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y != gameinfo->rows)
	{
		if (x == gameinfo->cols)
		{
			x = 0;
			y++;
		}
		if (toupper(gameinfo->board[y][x]) == 'X' && gameinfo->player == 'O')
			gameinfo->heatmap[y][x] = -1;
		else if (toupper(gameinfo->board[y][x]) == 'O' && gameinfo->player == 'X')
			gameinfo->heatmap[y][x] = -1;
		else
			gameinfo->heatmap[y][x] = 0;
		x++;
	}
}

void	fillheatmap(int heatmap[100][100], int starty, int startx)
{
	int	y;
	int	x;
	int	heat;
	int	minus;

	minus = -1;
	heat = 1;
	while (minus != -25)
	{
		y = starty + minus;
		x = startx + minus;
		while (y != ((starty + minus * -1)))
		{
			while (x != (((startx + minus * -1) + 1)))
			{
				x++;
				if (heatmap[y][x] == 0)
					heatmap[y][x] = heat;
			}
			x = startx + minus;
			y++;
		}
		heat++;
		minus--;
	}
}

void	createheatmap(t_game *gameinfo)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y != gameinfo->rows)
	{
		if (x == gameinfo->cols)
		{
			x = 0;
			y++;
		}
		if (gameinfo->heatmap[y][x + 1] == -1)
			fillheatmap(gameinfo->heatmap, y, x);
		x++;
	}
}

