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
		utils/ft_bzero.c					\
		utils/ft_split.c					\
		ft_execute.c				        \
		utils/ft_substr.c					\
		utils/ft_strjoin.c				    \
		utils/ft_putstr_fd.c                \
		ft_errors.c                         \

INC =   ft_pipex.h             				\


all: $(OBJS)
	gcc $(FLAGS) -o pipex -ggdb $(OBJS)

skiperror: $(OBJS)
	gcc  -ggdb -o pipex $(OBJS) 

clean:
	@rm -rf *.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all skiperror clean fclean re
