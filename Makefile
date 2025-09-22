NAME	= cub3d
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INC		= -Iinclude -Imlx -Ilibft/include

SRCS	= src/main.c \

OBJSDIR	= obj
OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)

LIBFT_D	= libft
LIBFT_L	= $(LIBFT_D)/libft.a
LIBFT_F	= -L$(LIBFT_D) -lft

MLX_DIR	= minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLG	= -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_L)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_F) $(MLX_FLG) -o $@

$(OBJSDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT_L):
	$(MAKE) -C $(LIBFT_D)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJSDIR)
	$(MAKE) clean -C $(LIBFT_D)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_D)
	$(MAKE) fclean -C $(MLX_DIR)

re: fclean all

.PHONY: all run clean flcean re
