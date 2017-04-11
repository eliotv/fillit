/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:46:30 by evanheum          #+#    #+#             */
/*   Updated: 2017/04/10 16:49:22 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		recursion(char **board, char **tet_array, int row, int col)
{
	if (!*tet_array)
		return (0);
	while (board[row])
	{
		col = 0;
		while (board[row][col])
		{
			if (check_board(board, *tet_array, row, col))
			{
				put_tet(board, *tet_array, row, col);
				if (recursion(board, (tet_array + 1), 0, 0))
				{
					remove_tet(board, *tet_array, 0, 0);
				}
				else
					return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

char	**loop_recursion(char **board, char **tet_array, int size)
{
	while (recursion(board, tet_array, 0, 0))
	{
		size++;
		free_board(board);
		board = create_board(size);
	}
	return (board);
}
