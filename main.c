/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:38:05 by blee              #+#    #+#             */
/*   Updated: 2017/03/23 18:59:45 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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

	valid = set_valid();
	tet_str = readfile(file);
	*size = ft_scan(tet_count(tet_str));
	if (check_tet_format(tet_str))
		tet_array = ft_scan(*size, tet_str, valid);
	return (tet_array);
}

char	**solve_board(char **tet_array, int size)
{
	char	**board;

	board = create_board(size);
	loop_recursion(board, tet_array, size);
	return (board);
}

int		main(int ac, char **av)
{
	char	**tet_array;
	char	**board;
	int		size;

	size = 0;
	if (ac == 2)
	{
		tet_array = call_reader(av[1], size);
		board = solve_board(tet_array, size);
		print_board(board);
	}
	return (0);
}
