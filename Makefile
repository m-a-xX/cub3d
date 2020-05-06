CC=clang
CFLAGS=-Wall -Wextra -Werror
EXEC=cub3d
SRCS=	src/main.c			\
		src/mlx_funcs.c		\
		src/structs_funcs.c	\

OBJ= $(SRCS:.c=.o)

all: $(EXEC)

cub3d: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) lib/mlx/libmlx.a -lm -lbsd -lX11 -lXext

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean

clean:
	rm -rf src/*.o

fclean: clean
	rm -rf $(EXEC)