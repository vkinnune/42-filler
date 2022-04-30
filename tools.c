#include "filler.h"

int	ft_out(char *reason)
{
	char	*p;

	p = reason;
	while (*p)
	{
		write(1, p, 1);
		p++;
	}
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	player(t_game *gameinfo)
{
	char	c;

	c = '.';
	while (!isdigit(c))
		read(STDIN_FILENO, &c, 1);
	if (c == '1')
		gameinfo->player = 'O';
	else if (c == '2')
		gameinfo->player = 'X';
	else
		ft_out("ERROR ON PLAYER");
}

int	parsenum(t_game *gameinfo, char c)
{
	int	num;

	num = 0;
	while (isdigit(c))
	{
		num *= 10;
		num += c - '0';
		read(0, &c, 1);
	}
	return (num);
}

void	size(t_game *gameinfo)
{
	char	c;

	c = '.';
	while (!isdigit(c))
		read(0, &c, 1);
	gameinfo->rows = parsenum(gameinfo, c);
	read(0, &c, 1);
	gameinfo->cols = parsenum(gameinfo, c);
}

void	board(t_game *gameinfo)
{
	int	y;
	int	x;
	char	c;

	y = 0;
	x = 0;
	c = 'a';
	while (!strchr("XxOo.", c))
		read(0, &c, 1);
	while (y != gameinfo->rows)
	{
		if (strchr("XxOo.", c))
		{
			//printf("%c");
			gameinfo->board[y][x] = toupper(c);
			x++;
		}
		if (x == gameinfo->cols)
		{
			//printf("\n");
			x = 0;
			y++;
		}
		read(0, &c, 1);
	}
}

void	map_piece(t_game *gameinfo)
{
	int	y;
	int	x;
	char	c;

	y = 0;
	x = 0;
	c = 'a';
	bzero(gameinfo->piece, sizeof(100 * 100));
	while (y != gameinfo->piece_y)
	{
		if (strchr("*.", c))
		{
			gameinfo->piece[y][x] = c;
			x++;
		}
		if (x == gameinfo->piece_x)
		{
			x = 0;
			y++;
		}
		read(0, &c, 1);
	}

}

void	piece(t_game *gameinfo)
{
	char	c;

	while (!isdigit(c))
		read(0, &c, 1);
	gameinfo->piece_y = parsenum(gameinfo, c);
	read(0, &c, 1);
	gameinfo->piece_x = parsenum(gameinfo, c);
}

