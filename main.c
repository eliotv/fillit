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

char	*readfile(char *file, int *tet_count)
{
	int		fd;
	int		ret;
	char	*tetstr;

	tetstr = ft_strnew(546);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error\n");
		return (NULL);
	}
	ret = read(fd, tetstr, 545);
	tetstr[ret] = '\0';
	*tet_count = (ret + 1) / 21;
	if (close(fd) == -1)
	{
		ft_putstr("close() error\n");
		return (NULL);
	}
	return (tetstr);
}

int	main(int ac, char **av)
{
	char	*tet_str;
	int		tet_count;
	char	**tet_array;

	tet_count = 0;
	if (ac == 2)
	{
		tet_str = readfile(av[1], &tet_count);
		/*
		if(check_tet_format(tet_str))
			tet_array = ft_scan(tet_count, tet_str, valid);
		*/
		printf("%d", tet_count);
	}
	return (0);
}
