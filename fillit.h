#ifndef FILLIT_H
# define FILLIT_H
#include "libft/libft.h"
#include <fcntl.h>

char	**create_board(int size);
void	free_board(char **board);
void	valid_tets(char **str);
char	**set_valid();
int	check_tet(char *str);
int	check_board(char **board, char *str, int row, int col);
void	put_tet(char **board, char *str, int row, int col);
void	remove_tet(char **board, char *valid, int row, int col);
int	checkline(char *str);
int	check_tet(char *str);
int	check_tet_format(char *str);
int	ft_strcmp_tet(const char *str1, const char *str2);
void	valid_tets(char **str);
int cmp_tet_input(char *src);
char	**ft_scan(int tet_count, char *str, char **valid);
int	recursion(char **board, char **tet_array, int row, int col);
char **loop_recursion(char **board, char **tet_array, int size);
char	*readfile(char *file);
char	**call_reader(char *file, int *size);
char	**solve_board(char **tet_array, int size);
int	tet_counter(char *str);
char *set_letter(char *str, int j);

#endif
