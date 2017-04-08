#include "fillit.h"

int     ft_strcmp_tet(const char *big, const char *little)
{
	int	i;
	int	j;
	int max;

	i = 0;
	max = 21;
	if (!little)
		return (0);
	while (i < max)
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (!little[j + 1])
				return (1);
			j++;
			if (big[i + j] == '\n')
				i++;
		}
		i++;
	}
    return (0);
}

int check_valid(char *src, char **valid)
{
    int     i;

    i = -1;
    while (++i < 19)
    {
        if (ft_strcmp_tet(src, valid[i]))
            return (i);
    }
    return (-1);
}

char *set_letter(char *str, int j)
{
	int		i;
	char	c;

	i = 0;
	c = 'A' + j;
	while (str[i])
	{
		if(str[i] == '#')
			str[i] = c;
		i++;
	}
	return (str);
}

char    **ft_scan(int tet_count, char** valid, char *tet_str)
{
	int     i;
	int     tet_id;
	char    **tet_array;
	
	i = 0;
	if(!(tet_array = (char**)malloc(sizeof(char*) * (tet_count + 1))))
		return (NULL);
	while (i < tet_count)
	{
		tet_id = check_valid(tet_str, valid);
		if (tet_id == -1)
			return (NULL);
		else
		{
			if (!(tet_array[i] = ft_strnew(15)))
				return (NULL);
			ft_strcpy(tet_array[i], valid[tet_id]);
			set_letter(tet_array[i], i);
			i++;
		}
		tet_str += 21;
	}
	tet_array[i] = NULL;
	return (tet_array);
}
