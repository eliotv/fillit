#
#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evanheum <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 14:43:34 by evanheum          #+#    #+#              #
#*   Updated: 2017/04/06 15:30:02 by evanheum         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAG += -Wall -Wextra -Werror
CFLAG += -I libft/

SRC = check_format.c \
      create_board.c \
      ft_solve.c \
      main.c \
      recursion_test.c \
      valid_tet.c \

OBJ = $(SRC:.c=.o) 

LIBDIR = libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(LIBDIR):
	@make -C libft

$(NAME): $(LIBDIR) $(OBJ)
	@gcc $(OBJ) $(LIBDIR) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
