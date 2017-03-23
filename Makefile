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
SRC = 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAG) $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
