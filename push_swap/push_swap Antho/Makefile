NAME	= push_swap
SRC		= src/main.c\
		  src/stack.c\
		  src/utils.c\
		  src/error_management.c
OBJS	= $(SRC:.c=.o)
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
LIB		= -L LIB -lftprintf
INCLUDE	= -I include
.c.o:
	${CC} -g -c $< -o ${<:.c=.o} ${LIB} ${INCLUDE}
$(NAME): ${OBJS}
	cd LIB;make
	${CC} ${OBJS} -o ${NAME} ${LIB} ${INCLUDE}
all: ${NAME}
clean:
	cd LIB;make clean
	${RM} ${OBJS}
fclean: clean
	cd LIB;make fclean
	${RM} ${NAME}
re: fclean all