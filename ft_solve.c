#include "./libft/libft.h"

char ft_scan(int row, int tet_count, char **tet_array)
{
	char **valid;
	int i;
	
	i = -1;
	valid = (char**)malloc(sizeof(char*) * 20);
	while (++i < 19)
		valid[i] = ft_strnew(15);
	valid = valid_tets();

	if(!(tet_array = (char**)malloc(sizeof(char*) * tet_count)))
		return (NULL);
	while (tet_count--)
	{
		if (i = cmp_tet_input(tet, valid))
		{
			if (!(tet_array[row] = ft_strnew(15)))
				retrun (NULL);
			tet_array[row] = ft_strcpy(valid[i]);
			row++;
		}
	}
}
