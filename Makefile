# includes:
LIBFT = libft/libft.a
MLX42 = MLX42/libmlx42.a

NAME = so_long

SRC = checker.c error.c map.c\
		render.c so_long.c sprites.c\
		verify.c
CC = gcc

CCFLAGS = -Wall -Werror -Wextra -g

OBJS = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CCFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@make -C MLX42
	@gcc $(CCFLAGS) $(OBJS) $(LIBFT) $(MLX42) -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
	@echo "Se ha compilado perfectamente ✅"

clean:
	@rm -f $(OBJS)
	@make clean -C libft
	@make clean -C MLX42
	@echo "Se ha borrado todo :D"


fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@make clean -C MLX42
	@echo "Se ha borrado todo :D"

	
re: fclean all

.PHONY: all fclean clean re