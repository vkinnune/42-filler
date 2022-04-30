#include "filler.h"

int	checkspot(t_game *gameinfo, int starty, int startx)
{
	int	y;
	int	x;
	int	overlap;

	y = 0;
	x = 0;
	overlap = 0;
	while ((y + starty) != (starty + gameinfo->piece_y))
	{
		if (gameinfo->board[y + starty][x + startx] == gameinfo->player && gameinfo->piece[y][x] == '*')
			overlap++;
		if (gameinfo->heatmap[y + starty][x + startx] == -1 && gameinfo->piece[y][x] == '*')
			return (0);
		x++;
		if ((x + startx) == (startx + gameinfo->piece_x))
		{
			y++;
			x = 0;
		}
	}
	if (overlap == 1)
		return (1);
	else
		return (0);
}

void	solve(t_game *gameinfo, t_pos pos[1000])
{
	int	y;
	int	x;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	bzero(pos, sizeof(t_pos) * 1000);
	while ((y + gameinfo->piece_y) != gameinfo->rows)
	{
		if ((x + gameinfo->piece_x) == gameinfo->cols)
		{
			y++;
			x = 0;
		}
		if (checkspot(gameinfo, y, x))
		{
			pos[i].heat = gameinfo->heatmap[y][x];
			pos[i].y = y;
			pos[i++].x = x;
		}
		x++;
	}
}

void	findbestpos(t_game *gameinfo, t_pos *pos)
{
	t_pos	best;
	int	i;

	i = 0;
	best.x = 0;
	best.y = 0;
	best.heat = 0;
	while (pos[i].heat != 0)
	{
		if (pos[i].heat > 0)
			best = pos[i];
		i++;
	}
	ft_putnbr(best.y);
	ft_putchar(' ');
	ft_putnbr(best.x);
	ft_putchar('\n');
}

int	main()
{
	t_game	gameinfo;
	t_pos	pos[1000];

	gameinfo.player = 0;
	while (1)
	{
		if (!gameinfo.player)
			player(&gameinfo);
		size(&gameinfo);
		board(&gameinfo);
		piece(&gameinfo);
		map_piece(&gameinfo);
		setheatmap(&gameinfo);
		createheatmap(&gameinfo);
		solve(&gameinfo, pos);
		findbestpos(&gameinfo, pos);
	}
}

/*
	int y, x;
	y = 0;
	x = 0;
	while (y != gameinfo->rows)
	{
		if (x == gameinfo->cols)
		{
			printf("\n");
			x = 0;
			y++;
		}
		printf("%3d", gameinfo->heatmap[y][x]);
		x++;
	}
	*/

