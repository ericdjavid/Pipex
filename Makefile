# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 23:51:19 by edjavid           #+#    #+#              #
#    Updated: 2021/09/27 23:51:20 by edjavid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

SRC =   ft_pipex.c          		        \
		utils/ft_split.c					\
		ft_execute.c				        \
		utils/ft_substr.c					\
		utils/ft_strjoin.c				    \
		utils/ft_putstr_fd.c                \
		ft_errors.c                         \
		utils/ft_bzero.c                    \
		ft_free.c                           \

INC =   ft_pipex.h             				\


all: $(NAME)

$(NAME):
	gcc -g $(FLAGS) -o $(NAME) $(SRC)

skiperror:
	gcc -ggdb -o $(NAME) $(SRC) -g

clean:
	@rm -rf *.o
	@rm -rf utils/*.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

reskiperror: fclean skiperror

.PHONY: all skiperror clean fclean re
