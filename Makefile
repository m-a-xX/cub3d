SRC=    src/ft_recursive_power.c       		\
		src/get_next_line.c      \
		src/get_next_line_utils.c      \
		src/ft_count_convers.c      \
		src/main.c    \
		src/parse_cub.c       \
		src/parse_funcs.c    	\
		src/strjoin_free_nl.c     \
		
NAME= cub3d

OBJETS= ${SRC:.c=.o}


gcc=gcc -Werror -Wall -Wextra

%.o: %.c
	${gcc} -o $@ -c $<

$(NAME):    make -C lib/Libft
			${OBJETS}
			$(gcc) $(OBJETS) lib/Libft/libft.a -o $(NAME)

all: ${NAME}

re: fclean all

clean:
		rm -f ${OBJETS}
		make clean -C lib/Libft

fclean: clean
		rm -f ${NAME}
		make fclean -C lib/Libft

.PHONY: all clean fclean re