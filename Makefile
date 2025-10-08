NAME	= cub3d
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INC		= -Iinclude -Imlx -Ilibft/include -Iget_next_line
GNLPATH = ./get_next_line
SRCS	= src/main.c \
			src/core/init.c \
			src/core/utils.c \
			src/input/hooks.c \
			src/input/movement.c \
			src/parsing/parse_header.c \
			src/parsing/parse_file.c \
			src/parsing/validate_walls.c \
			src/parsing/validate.c \
			src/render/draw.c \
			src/render/texture.c \
			src/parsing/parser_help.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			src/render/window.c \
			src/core/cleanup.c \
			src/parsing/parse_map.c \
			src/render/raycast_setup.c \
			src/render/raycast.c

OBJSDIR	= obj
OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)
GNL = $(GNLPATH)/get_next_line.c $(GNLPATH)/get_next_line_utils.c
GNLOBJS = $(GNL:.c=.o)

LIBFT_D	= libft
LIBFT_L	= $(LIBFT_D)/libft.a
LIBFT_F	= -L$(LIBFT_D) -lft

MLX_DIR	= minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLG	= -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_L) $(GNLOBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_F) $(MLX_FLG) -o $@

$(OBJSDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT_L):
	$(MAKE) -C $(LIBFT_D)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJSDIR) $(GNLOBJS)
	$(MAKE) clean -C $(LIBFT_D)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_D)

re: fclean all

.PHONY: all run clean flcean re
