/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_tet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:22:38 by evanheum          #+#    #+#             */
/*   Updated: 2017/04/06 18:48:49 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		checkline(char *str)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (str[i] == '.' || str[i] == '#')
			i++;
		else
			return (0);
	}
	if (str[i] == '\n')
		return (1);
	return (0);
}

int		check_tet(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (str[i] == '#')
			count++;
		if (count > 4)
			return (0);
		if (i % 5 == 0)
			if (!checkline(&str[i]))
				return (0);
		i++;
	}
	if (str[i] != '\n')
		return (0);
	return (1);

}

int		ft_strcmp_tet(const char *str1, const char *str2)
{
    while (*str1 && *str2 && *str1 == *str2) 
	{
        str1++;
        str2++;
        if (*str1 == '\n')
            str1++;
        if (*str2 == '\0')
            return (1);
    }
    return (0);

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

int		check_valid(char *src, char **valid)
{
	int		i;

	i = -1;
	while (++i < 19)
	{
		if (ft_strcmp_tet(src, valid[i]))
			return (i);
	}
	return (-1);
}
