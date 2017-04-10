#include "fillit.h"

int	check_board(char **board, char *str, int row, int col)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((i % 4 == 0) && i)
		{
			row++;
			col -= 4;
		}
		if (!board[row])
			return (0);
		if(board[row][col] != '.' && (str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
		col++;
	}
	return (1);
}

void	put_tet(char **board, char *str, int row, int col)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((i % 4 == 0) && i)
		{
			row++;
			col -= 4;
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			board[row][col] = str[i];
		}
		i++;
		col++;
	}
}

void	remove_tet(char **board, char *valid, int row, int col)
{
	int		i;
	char	c;

	i = 0;
	while (*valid == '.')
		valid++;
	c = *valid;
	while (board[row])
	{
		while (board[row][col] && (i < 4))
		{
			if (board[row][col] == c)
			{
				board[row][col] = '.';
				i++;
			}
			col++;
		}
		row++;
		col = 0;
	}
}
