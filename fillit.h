#ifndef FILLIT_H
# define FILLIT_H
#include "libft/libft.h"

typedef	enum	e_bool;
{
		false, 
		true
}				t_bool;

char	**create_board(int size);
void	free_board(char **board);
void	valid_tets(char **str);
char	**set_valid();
int	check_tet(char *str);
int	check_board(charr **board, char *str, int row, int col);
void	put_tet(char **board, char *str, int row, int col);
void	remove_tet(char **board, char c, int row, int col);
int	checkline(char *str);
int	check_tet(char *str);
int	check_tet_format(char *str);
int	ft_strcmp_tet(const char *str1, const char *str2);
void	valid_tets(char **str);
int cmp_tet_input(char *src);
int	readfile(char *file, int *tet_count);
char	**ft_scan(int tet_count, char *str, char **valid);
t_bool	recursion(char **board, char **tet_array, int row, int col);

#endif
