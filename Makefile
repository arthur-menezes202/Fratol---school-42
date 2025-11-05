NAME = fractol
FLAGS = -Wall -Werror -Wextra
CC = cc

#includes
INCLUDES = -I/usr/include
SRCDIR = .

LIBFT = libft/libft.a
LIBFT_DIR = libft

MINILIBX = Imlx_linux/libmlx.a
MINILIBX_DIR = Imlx_linux


LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

SRCS = $(SRCDIR)/./ft_atod.c \
        $(SRCDIR)/./main.c \
        $(SRCDIR)/./mouse.c \
        $(SRCDIR)/./calculate.c \
        $(SRCDIR)/./is_double.c \
        $(SRCDIR)/./iterations_fractol.c \
        $(SRCDIR)/./my_mlx_pixel_put.c \
        $(SRCDIR)/./start_fractol.c \
        $(SRCDIR)/./creat_color.c

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