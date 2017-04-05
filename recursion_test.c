#include "fillit.h"

int		recursion(char **board, char **valid, int row, int col)
{
	if (!*valid)
		return (0);
	while (board[row])
	{
		col = 0;
		while (board[row][col])
		{
			if (check_board(board, *valid, row, col))
			{
				put_tet(board, *valid, row, col);
				if (recursion (board, (valid + 1), 0, 0))
					remove_tet(board, *valid, 0 , 0);
				else
					return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

char	**loop_recursion(char **board, char **valid, int size)
{
	while (recursion(char board, valid, 0, 0))
	{
		size++;
		free_board(board);
		board = create_board(size);
	}
	return (board);
}
