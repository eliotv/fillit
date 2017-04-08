/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:38:05 by blee              #+#    #+#             */
/*   Updated: 2017/04/06 18:58:17 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char	*readfile(char *file)
{
	int		fd;
	int		ret;
	char	*tetstr;

	tetstr = ft_strnew(546);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, tetstr, 545);
	tetstr[ret] = '\0';
	if (close(fd) == -1)
		return (NULL);
	return (tetstr);
}

char	**call_reader(char *file, int *size)
{
	char	*tet_str;
	char	**tet_array;
	char	**valid;

	tet_str = readfile(file);
	*size = tet_counter(tet_str);
	valid = set_valid();
	tet_array = NULL;
	if (check_tet_format(tet_str))
		tet_array = ft_scan(*size, valid, tet_str);
	return (tet_array);
}

char	**solve_board(char **tet_array, int size)
{
	char	**board;

	board = create_board(size);
	board = loop_recursion(board, tet_array, size);
	return (board);
}

void	print_board(char** board)
{
	int i = 0;

	while (board[i])
	{
		ft_putstr(board[i]);
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	char	**tet_array;
	char	**board;
	int		size;

	size = 0;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit [source_file]\n");
		return (0);
	}
	else if (ac == 2)
	{
		tet_array = call_reader(av[1], &size);
		print_board(tet_array);
		ft_putchar('\n');
		//board = create_board(3);
		//printf("%d\n", check_board(board, tet_array[0], 0, 0));
		board = solve_board(tet_array, size);
		print_board(board);
		//board = NULL;
	}
	return (0);
}
