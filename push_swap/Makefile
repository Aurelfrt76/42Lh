NAME	= push_swap
SRC		= src/main.c\
		  src/stack.c\
		  src/stack_instruc.c\
		  src/algo.c\
		  src/algo_utils.c\
		  src/utils.c
OBJS	= $(SRC:.c=.o)
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
LIB		= -LLIB -lftprintf
$(NAME): ${OBJS}
	cd LIB;make
	${CC} ${OBJS} -o ${NAME} ${LIB}
all: ${NAME}
clean:
	cd LIB;make clean
	${RM} ${OBJS}
fclean: clean
	cd LIB;make fclean
	${RM} ${NAME}
re: fclean all
