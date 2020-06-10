CC=clang
CFLAGS=-Wall -Wextra -Werror
EXEC=cub3D
SRCS=	src/main.c					\
		src/mlx_funcs.c				\
		src/structs_funcs.c			\
		src/raycast.c				\
		src/print.c					\
		src/parsing_funcs.c			\
		src/parsing_map.c			\
		src/parsing_main.c			\
		src/get_next_line.c			\
		src/get_next_line_utils.c	\
		src/move.c					\
		src/debug.c					\
		src/dda.c					\
		src/textures.c				\
		src/map_allocation.c		\
		src/save.c					\
		src/parsing_funcs2.c		\

OBJ= $(SRCS:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) lib/mlx/libmlx.a lib/libft/libft.a -lm -lbsd -lX11 -lXext

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean

clean:
	rm -rf src/*.o

fclean: clean
	rm -rf $(EXEC)

re: fclean all
