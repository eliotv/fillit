/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:30:16 by blee              #+#    #+#             */
/*   Updated: 2017/03/24 17:20:41 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

char	**create_board(int size)
{
	char **board;
	int row;
	int col;

	row = 0;
	col = 0;
	if (!(board = (char**)malloc(sizeof(char**) * size)))
		return (NULL);
	while (row < size)
	{
		col = 0;
		if (!(board[row] = ft_strnew(size)))
			return (NULL);
		while (col < size)
		{
			board[row][col] = '.';
			col++;
		}
		board[row][col] = '\0';
		row++;
	}
	return (board);
}
