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

SRC =   ft_pipex.c          		        \
		utils/ft_bzero.c					\
		utils/ft_split.c					\
		ft_execute.c				        \
		utils/ft_substr.c					\
		utils/ft_strjoin.c				    \
		utils/ft_putstr_fd.c                 \
		ft_errors.c                         \

INC =   ft_pipex.h             		\

all: $(NAME)

$(NAME):
	gcc -g -fsanitize=address $(FLAGS) -o $(NAME) $(SRC) $(INC)

skiperror:
	gcc -ggdb -o $(NAME) $(SRC) -g $(INC)

clean:
	@rm -rf *.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all skiperror clean fclean re
