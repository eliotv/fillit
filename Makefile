# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evanheum <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 14:43:34 by evanheum          #+#    #+#              #
#    Updated: 2017/03/21 14:48:54 by evanheum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFLAG = -Wall -Wextra -Werror
SRC = create_board.c \
	  ft_count_tet.c \
	  main.c \
	  check_format.c \
	  recursion.c \
	  valid_tet.c \
	  ft_solve.c \


FIL = fillit.h

LIB = libft

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAG) $< -o $@

$(NAME): 
	@make -C $(LIB) re
	@ gcc $(CFLAG) -L  $(LIB) -lft *.c -I $(LIB) -I $(FIL) -o $(NAME)

clean:
	@make -C $(LIB) clean

fclean: clean
	@make -C $(LIB) fclean
	@bin/rm -f $(NAME)

re: fclean all

.MCM: all clean fclean re
