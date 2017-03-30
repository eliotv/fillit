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

char    **create_board(int size)
{
    char    **board;
    char    *row;
    int     i;
    i = 0;
    if (!(board = (char**)malloc(sizeof(char**) * (size + 1))))
        return (NULL);
    row = ft_strnew(size);
    ft_memset(row, '.', size);
    while (i < size)
    {
        board[i] = ft_strnew(size);
        ft_strcpy(board[i], row);
        i++;
    }
    board[i] = '\0';
    return (board);
}

void	**free_board(char **board)
{
	int i;

	i = 0;
	while(board[i])
	{
		free(board[i]);
		i++;
	}
	free(board);
}

char 
