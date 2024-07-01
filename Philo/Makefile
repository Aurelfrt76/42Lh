# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afromont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 12:52:20 by afromont          #+#    #+#              #
#    Updated: 2024/03/08 14:53:39 by afromont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror -I./include -g -pthread -fsanitize=thread
CC = cc

SRC = src/actions.c src/init.c src/main.c src/threads.c src/utils.c
OBJ = $(SRC:.c=.o)

all:		$(NAME)

%.o:		%.c
			$(CC)  $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			$(RM) -f $(OBJ)

fclean:		clean
			$(RM) -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re

