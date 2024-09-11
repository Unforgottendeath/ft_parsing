CC = cc
NAME = cub

SRC = main.c \
		upload_content.c \
		ft_free_parsing.c \
		ft_parsing.c \
		get_next_line.c \
		get_next_line_utils.c \
		utils.c \
		ft_split.c \
		ft_verify_content.c \
		ft_verify_data.c \
		ft_verify_textures.c \
		ft_verify_floor_ceil.c

LIB = parsing.h

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c   $< -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
