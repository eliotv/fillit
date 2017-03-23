/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_tet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:22:38 by evanheum          #+#    #+#             */
/*   Updated: 2017/03/21 17:05:02 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include <stdio.h>
int checkline(char *str)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (str[i] != '.' || str[i] != '#')
			return (0);
		i++;
	}
	if (str[i] != '\n')
		return (0);
	else
		return (1);
}
int checktet(char *str)
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
		if (i % 5 == 0 )
			if (!checkline(&str[i]))
				return (0);
		i++;
	}
	if (str[i] != '\n')
		return (0);
	return (1);

}
int main()
{
	char str[] = "....'\n'....'\n'....'\n'....'\n''\n'";
	char str2[] = "....'\n'";

	printf("%d", checkline(str2));

	return (0);
}