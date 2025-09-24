/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:03:16 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/09/24 14:12:35 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_W 800
# define WIN_H 600
// keycodes
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define R_ARW 65363
# define L_ARW 65361
// Events
# define EVT_KEYPRESS 2
# define EVT_KEYRELEASE 3
# define EVT_DESTROY 17
// Masks
# define MASK_KEYPRESS (1L << 0)
# define MASK_KEYRELEASE (1L >> 1)

typedef struct s_vector
{
	int	x;
	int y;
} t_vector; // the position of the player is always vector

typedef struct s_parser
{
	char	*n_path;
	char	*s_path;
	char	*w_path;
	char	*e_path;
	int		floor;
	int		ceiling;
	char	**map;
}			t_parser;

typedef struct s_map
{
	int		player_x;
	int		player_y;
	
	/* map data */
}			t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len; // length of a line in bytes
	int		endian;
	int		w;
	int		h;
}			t_img;
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_img	textures[4];
}			t_data;

// init.c
void		init_parser(t_parser *parser);
int			read_map(t_parser *parser, int fd);

//parse_file.c
int 		check_ext(char *str);

//parse_header.c
int			check_textures_color(t_parser *pars, int fd);
int			parse_textures(t_parser *parser, char *trim);
int			parse_colours(t_parser *pars, char *trim);

//parse_helper.c
int			convert_to_int(t_parser *pars, char **array, char lett);

//utils.c
char		*skip_whitespaces(char *line);
int			is_it_whitespace(t_parser *parser);

// render
int	render_frame(t_parser *pars, t_data *data, t_img *img);
void put_pixel(t_data *data, int x, int y, unsigned int color);
int	start_window(t_data *data);
void 		free_split(char **array);
void		free_parser(t_parser *parser);

#endif
