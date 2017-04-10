#include "fillit.h"

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
	if ((str[i] == '\n' && str[i + 1]) || !str[i])
		return (1);
	return (0);
}

int		check_tet_format(char *str)
{
	while (*str)
	{
		if (!check_tet(str))
			return (0);
		str = str + 21;
	}
	return (1);
}

int tet_counter(char *str)
{
	int i;

	i = ft_strlen(str);
	i = (i + 1) / 21;
	return (i);
}
