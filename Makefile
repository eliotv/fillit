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

CFLAG = gcc -Wall -Wextra -Werror

SRC = check_format.c \
      create_board.c \
      ft_solve.c \
      main.c \
      recursion_test.c \
      valid_tet.c \

FILH = fillit.h

LIBDIR = libft


all: $(NAME)

$(NAME): 
	@make -C $(LIBDIR) re
	@$(CFLAG) -L $(LIBDIR) -lft $(SRC) -I $(LIBDIR) -I $(FILH) -o $(NAME)

clean:
	@make -C $(LIBDIR) clean

fclean: clean
	@make -C $(LIBDIR) fclean
	@/bin/rm -f $(NAME)

re: fclean all

.MCM: all clean fclean re
