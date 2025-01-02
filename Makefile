NAME = so_long
LIBFT = ./libft/libft.a
SRC = ./src/so_long.c ./src/map.c ./src/render.c ./src/eve.c ./src/errors_map.c ./src/errors_map2.c ./src/errors_map3.c ./src/player_actions.c ./src/init_player.c ./src/validate_path.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
#prerequisite
all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lmlx -lXext -lX11 -o $(NAME)
clean:
	rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: fclean clean all re
