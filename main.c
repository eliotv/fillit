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

int	readfile(char *file)
{
	int		fd;
	int		ret;
	char	tetstr[546];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error\n");
		return (1);
	}
	ret = read(fd, tetstr, 545);
	tetstr[ret] = '\0';
	ft_putstr(tetstr);
	if (close(fd) == -1)
	{
		ft_putstr("close() error\n");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		readfile(av[1]);
	}
	return (0);
}
