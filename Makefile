NAME = fractol
# FLAGS = -Wall -Werror -Wextra
FLAGS = 
CC = cc -g3

#includes
INCLUDES = -I/usr/include
SRCDIR = .

LIBFT = libft/libft.a
LIBFT_DIR = libft

MINILIBX = Imlx_linux/libmlx.a
MINILIBX_DIR = Imlx_linux


LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

SRCS = $(wildcard *.c)

OBJ = $(SRCS:%.c=%.o)

all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(MINILIBX) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C Imlx_linux fclean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C Imlx_linux fclean

re: fclean all