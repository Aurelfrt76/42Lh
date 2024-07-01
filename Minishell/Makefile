NAME	= minishell
SRC		= src/main.c\
		  src/init.c\
		  src/heredoc/heredoc.c\
		  src/parsing/checking.c\
		  src/parsing/parsing.c\
		  src/parsing/parsing_utils.c\
		  src/parsing/env_parsing.c\
		  src/parsing/redir_parsing.c\
		  src/parsing/quote_cleaning.c\
		  src/stack_env/stack.c\
		  src/stack_env/stack_env.c\
		  src/executing/executing.c\
		  src/executing/exec_cmd.c\
		  src/executing/built_in/built_in0.c\
		  src/executing/built_in/built_in1.c\
		  src/executing/built_in/utils_cmd.c\
		  src/executing/error_exec.c
OBJS	= $(SRC:.c=.o)
CC		= cc
RM		= rm -f
CFLAGS	+= -Wall -Werror -Wextra -g
LIBFT	= -LLIB/libft -lft
GC = -LLIB/GC -lgarb_collect
READLINE = -lreadline
INCLUDES = -I./includes
all: ${NAME}
%.o: %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
$(NAME): ${OBJS}
	cd LIB/libft;make
	cd LIB/GC;make
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIBFT} ${GC} ${READLINE}
debug: ${OBJS}
	cd LIB/libft;make
	cd LIB/GC;make debug
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIBFT} ${GC} ${READLINE}
clean:
	cd LIB/libft;make clean
	cd LIB/GC; make clean
	${RM} ${OBJS}
fclean: clean
	cd LIB/libft;make fclean
	cd LIB/GC; make fclean
	${RM} ${NAME}
re: fclean all
debre: fclean debug
