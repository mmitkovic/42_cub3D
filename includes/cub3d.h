/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:03:16 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/06 16:41:20 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <inttypes.h>
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

// typedef struct s_vector
// {
// 	int	x;
// 	int y;
// } t_vector; // the position of the player is always vector

typedef struct s_parser
{
	char		*n_path;
	char		*s_path;
	char		*w_path;
	char		*e_path;
	int			floor;
	int			ceiling;
	char		**map;
}				t_parser;

// typedef struct s_map
// {
// 	int		player_x;
// 	int		player_y;

// 	/* map data */
// }			t_map;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int 		line_len; // length of a line in bytes
	int			endian;
	int			w;
	int			h;    				//maybe the texture array should go here as a NEXT pointer (linked list)?
}				t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fd;
	int			elem_no;
	int			elem_so;
	int			elem_we;
	int			elem_ea;
	int			elem_f;
	int			elem_c;
	int			pos_x;
	int			pos_y;
	int			plane_x;
	int			plane_y;
	char		player_letter;
	t_img		img;
	t_parser	*parser;
	t_img		texture[4];  		//<-- doesnt it have to be initialised?
}				t_data;

// src/core/cleanup.c
void			clean_exit(t_data *data);
void			drain_out_gnl(int fd);
void			free_split(char **array);
void			free_parser(t_parser *parser);

// src/input/hooks.c
int				handle_keypress(int keycode, void *param);
int				handle_keyrelease(int keycode, void *param);
int				handle_close_win(int keycode, t_data *data);
int				handle_mouse_move(int x, int y, void *param);
int				handle_mouse_press(int keycode, int x, int y, void *param);

// src/parsing/validate_walls.c
int	check_walls(char **map);

// src/parsing/validate.c
int				map_check(t_data *data, char **map);

// src/render/textures.c
int				load_texture(t_data *data, t_img *tex_img, char *path);
int				load_textures(t_data *data);

// src/input/movement.c

// init.c
void			init(t_parser *parser, t_data *data);
void			init_parser(t_parser *parser);
void			init_data(t_data *data);
void			init_img(t_img *img);
int				read_map(t_parser *parser, t_data *data);

// parse_file.c
int				check_ext(char *str);

// parse_header.c
int				dispatch_colour_parser(t_data *data, char *trim, int *elements);
int				check_textures_color(t_parser *pars, t_data *data);
void			init_for_parse(int *elements, int *i, char **line);
int				parse_textures(t_data *data, t_parser *parser, char *trim);
int				parse_colours(t_data *data, t_parser *pars, char *trim);

// parser_help.c
int				are_only_digits(char **array);
char			**split_by_colour(t_parser *parser, char *trim, char letter);
int				convert_to_int(t_parser *pars, char **array, char lett);
int				is_line_nul(char *trim, char **line, t_data *data);
char 			**split_c(char *ceil, char *trim, t_parser *pars, char **array);

// parse_map.c
char			**extend_the_map(char **old_map, char *line);
int				add_another_line(t_parser *parser, char *line);
int				parse_map(t_parser *parser, t_data *data);
int				parse_n_s(t_data *data, t_parser *pars, char *trim);
int				parse_w_e(t_data *data, t_parser *parser, char *trim);


// utils.c
char			*trim_newline(char *str);
char			*skip_white(char *line);
int				is_it_whitespace(t_parser *parser);
char			*skip_white_after(char *line);

// render
int				render_frame(void *parm);
void			put_pixel(t_data *data, int x, int y, unsigned int color);
int				start_window(t_data *data);

#endif
