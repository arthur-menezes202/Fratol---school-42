#name of the project
NAME = libft.a

# compilers and flags
CC = cc
FLAGS = -Wall -Werror -Wextra

#directories
SRCDIR = .
INCLUDES = .

#all .c

SRCS =	$(SRCDIR)/ft_isalpha.c \
		$(SRCDIR)/ft_isdigit.c \
		$(SRCDIR)/ft_putstr_fd.c \
		$(SRCDIR)/ft_isalnum.c \
		$(SRCDIR)/ft_isascii.c \
		$(SRCDIR)/ft_memcpy.c \
		$(SRCDIR)/ft_isprint.c \
		$(SRCDIR)/ft_strlen.c \
		$(SRCDIR)/ft_strlcat.c \
		$(SRCDIR)/ft_memset.c \
		$(SRCDIR)/ft_bzero.c \
		$(SRCDIR)/ft_strlcpy.c \
		$(SRCDIR)/ft_memmove.c \
		$(SRCDIR)/ft_toupper.c \
		$(SRCDIR)/ft_tolower.c \
		$(SRCDIR)/ft_strchr.c \
		$(SRCDIR)/ft_strrchr.c \
		$(SRCDIR)/ft_strncmp.c \
		$(SRCDIR)/ft_memchr.c \
		$(SRCDIR)/ft_memcmp.c \
		$(SRCDIR)/ft_strnstr.c \
		$(SRCDIR)/ft_atoi.c \
		$(SRCDIR)/ft_calloc.c \
		$(SRCDIR)/ft_strdup.c \
		$(SRCDIR)/ft_substr.c \
		$(SRCDIR)/ft_strjoin.c \
		$(SRCDIR)/ft_strtrim.c \
		$(SRCDIR)/ft_itoa.c \
 		$(SRCDIR)/ft_strmapi.c \
 		$(SRCDIR)/ft_striteri.c \
 		$(SRCDIR)/ft_putchar_fd.c \
 		$(SRCDIR)/ft_putendl_fd.c \
 		$(SRCDIR)/ft_putnbr_fd.c \
 		$(SRCDIR)/ft_split.c \
		$(SRCDIR)/ft_printf/ft_printf.c\
		$(SRCDIR)/ft_printf/write_hexadecimal.c\
		$(SRCDIR)/ft_printf/write_ints.c\
		$(SRCDIR)/ft_printf/write_pointer.c\
		$(SRCDIR)/ft_printf/write_strings.c\
		$(SRCDIR)/ft_lstnew_bonus.c \
		$(SRCDIR)/ft_lstadd_front_bonus.c \
		$(SRCDIR)/ft_lstsize_bonus.c \
		$(SRCDIR)/ft_lstlast_bonus.c \
		$(SRCDIR)/ft_lstadd_back_bonus.c \
		$(SRCDIR)/ft_lstdelone_bonus.c \
		$(SRCDIR)/ft_lstclear_bonus.c \
		$(SRCDIR)/ft_lstiter_bonus.c \
		$(SRCDIR)/ft_lstmap_bonus.c \

OBJ = $(SRCS:$(SRCDIR)/%.c=%.o)

%.o: $(SRCDIR)/%.c
	$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re bonus