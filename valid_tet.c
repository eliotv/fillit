#include "fillit.h"

int     ft_strcmp_tet(const char *str1, const char *str2)
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

char	**ft_scan(int tet_count, char *str, char **valid)
{
	char	**tet_array;
	int		i;
	int		row;

	i = 0;
	row = 0;
	if(!(tet_array = (char**)malloc(sizeof(char*) * tet_count + 1)))
		return (NULL);
	while (tet_count--)
	{
		i = check_valid(str, valid);
		if (i != -1)
		{
			if (!(tet_array[row] = ft_strnew(15)))
				return (NULL);
			ft_strcpy(tet_array[row], set_letter(valid[i], row));
			row++;
		}
		else
			return (NULL);
		str += 21;
	}
	tet_array[row] = NULL;
	return (tet_array);
}

char *set_letter(char *str, int j)
{
	int i;
	char c;

	c = 'A' + j;
	i = 0;
	while (str[i])
	{
		if(str[i] == '#')
			str[i] = c;
		i++;
	}
	return (str);
}
