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
	return (char tet_array);
}

int check_tet_format(char *str)
{
	while (*str)
	{	
		if(!check_tet(str))
			return (0);
		str = str + 21;
	}
	return (1);
}

int		check_board(char **board, char *str int row, int col)
{
	int i;
	int tmp_col;

	i =0;
	tmp_col = col;
	while (str[i])
	{
		if (i % 4 == 0)
		{
			row++;
			tmp_col = col;
		}
		if (*str < 0)
			return (0);
		if(board[row][col] != '.' && (str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
		col++;
	}
	return (1)
}

char	put_tet(char **board, char *str, int row, int col)
{
	int i;
	int tmp_col;

	i = 0;
	tmp_col = col;
	while (*str)
	{
		if (i % 4 == 0)
		{
			row++;
			tmp_col = col;
		}
		if (*str >= 'A' && *str <= 'Z')
		{
			board[row][tmp_col] = *str;
		}
		i++;
		tmp_col;
	}
	return (1)
}

void	remove_tet(char **board, char *str, int row, int col)
{
	int i;
	char c;

	i = 0;
	while (board[row])
	{
		while (board[row][col])
		{
			if (board[row][col] == c)
				board[row][col] = '.';
			col++;
		}
		row++;
		col = 0;
	}
}


