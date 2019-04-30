# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 13:27:57 by mwunsch           #+#    #+#              #
#    Updated: 2018/11/29 13:07:52 by mwunsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_atoi.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_memcmp.c \
		ft_bzero.c \
		ft_memset.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strlcat.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strsplit.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c \
		ft_wordcount.c \
		ft_arrdel.c \
		ft_delimcount.c \
		ft_lstdelprintcont.c \
		ft_matrix.c \
		ft_strrejoin.c

OBJS = $(SRC:.c=.o)

INCLUDES = libft.h

all: $(NAME) 

$(NAME): $(OBJS)
	@echo "Libft: Building library"
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS): %.o: %.c
	@gcc -Wall -Wextra -O3 -c $< -I $(INCLUDES) -o $@

clean:
	@echo "Libft: Deleting binaries"
	@rm -f $(OBJS)

fclean: clean
	@echo "Libft: Deleting library"
	@rm -f libft.a

re: fclean all

