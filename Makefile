# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 13:27:57 by mwunsch           #+#    #+#              #
#    Updated: 2019/01/07 19:54:21 by mwunsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ./fdir/fillit.c ./fdir/fillit_tools.c ./fdir/fillit_recursion.c

OBJS = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS)
	@echo "Fillit: Compiling..."
	@make --directory ./libft
	@gcc -o $(NAME) -Wextra -Wall -Werror $(OBJS) -L./libft -lft
	@echo "Fillit: Compilation completed"

$(OBJS): %.o: %.c
	@gcc -Wall -Werror -Wextra -O3 -c $< -o $@

clean:
	@echo "Fillit: Deleting binaries"
	@rm -f $(OBJS)
	@make clean --directory ./libft

fclean: clean
	@echo "Fillit: Deleting program"
	@rm -f $(NAME)
	@make fclean --directory ./libft

re: fclean all
