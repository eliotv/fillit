/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:30:16 by blee              #+#    #+#             */
/*   Updated: 2017/04/06 18:45:07 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

char	**create_board(int size)
{
	char	**board;
	char	*row;
	int		i;

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
	board[i] = NULL;
	return (board);
}

void	free_board(char **board)
{
	int i;

	i = 0;
	while (board[i])
	{
		free(board[i]);
		i++;
	}
	free(board);
}

void	valid_tets(char **str)
{
	ft_strcpy(str[0], "###...#");
	ft_strcpy(str[1], ".#...#..##");
	ft_strcpy(str[2], "#...###");
	ft_strcpy(str[3], "##..#...#");
	ft_strcpy(str[4], "###.#");
	ft_strcpy(str[5], "##...#...#");
	ft_strcpy(str[6], "..#.###");
	ft_strcpy(str[7], "#...#...##");
	ft_strcpy(str[8], "###..#");
	ft_strcpy(str[9], ".#..##...#");
	ft_strcpy(str[10], ".#..###");
	ft_strcpy(str[11], "#...##..#");
	ft_strcpy(str[12], ".##.##");
	ft_strcpy(str[13], "#...##...#");
	ft_strcpy(str[14], "##..##");
	ft_strcpy(str[15], "#...#...#...#");
	ft_strcpy(str[16], "####");
	ft_strcpy(str[17], ".#..##..#");
	ft_strcpy(str[18], "##...##");
	str[19] = NULL;
}

char	**set_valid(void)
{
	char	**valid;
	int		i;

	i = 0;
	valid = (char**)malloc(sizeof(char*) * 20);
	if (!valid)
		return (NULL);
	while (i < 19)
	{
		valid[i] = ft_strnew(15);
		i++;
	}
	valid_tets(valid);
	return (valid);
}

int		set_boardsize(int size)
{
	int		i;

	i = 2;
	size *= 4;
	while (i * i < size)
		i++;
	return (i);
}
