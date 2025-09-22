NAME	= cub3d
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INC		= -Iinclude -Imlx

SRCS	= src/main.c \
			src/core/init.c

OBJSDIR	= obj
OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)

MLX_DIR	= minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLG	= -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLG) -o $@

$(OBJSDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all run clean flcean re
