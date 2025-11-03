NAME = fractol
# FLAGS = -Wall -Werror -Wextra
FLAGS = 
CC = cc -O3

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

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all