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

#include "./libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	readfile(char *file, int *tet_count)
{
	int		fd;
	char	tetstr[546];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error\n");
		return (1);
	}
	*tet_count = read(fd, tetstr, 545);
	tetstr[ret] = '\0';
	*tet_count = ret / 21;
	if (close(fd) == -1)
	{
		ft_putstr("close() error\n");
		return (1);
	}
	return (tetstr);
}

int	main(int ac, char **av)
{
	char	*tet_str;
	int		tet_count;

	tet_count = 0;
	if (ac == 2)
	{
		tet_str = readfile(av[1], tet_count);
		ft_scan(0, tet_count, tet_str);
	}
	return (0);
}
