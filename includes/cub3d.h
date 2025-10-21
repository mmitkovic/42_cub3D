/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:03:16 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/21 11:29:55 by mmitkovi         ###   ########.fr       */
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
# include <sys/time.h>
# include <unistd.h>

# define WIN_W 1000
# define WIN_H 800
# define TEX_SIZE 128
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define R_ARW 65363
# define L_ARW 65361
# define EVT_KEYPRESS 2
# define EVT_KEYRELEASE 3
# define EVT_DESTROY 17
# define MASK_KEYPRESS (1L << 0)
# define MASK_KEYRELEASE (1L << 1)
# define WALK_SPEED 4
# define ROT_SPEED 0.02

typedef struct s_parser
{
	char		*n_path;
	char		*s_path;
	char		*w_path;
	char		*e_path;
	int			floor;
	int			ceiling;
	int			w;
	int			h;
	char		**map;
}				t_parser;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			w;
	int			h;
}				t_img;

typedef struct s_ray
{
	double		raydir_x;
	double		raydir_y;
	double		angle;
	double		camera_x;
	double		delta_distx;
	double		delta_disty;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	double		side_disty;
	double		side_distx;
	int			hit;
	double		perp_dist;
	double		line_height;
	double		wall_x;
	double		draw_start;
	double		draw_end;
	int			tex_x;
	int			tex_y;
	int			side;
}				t_ray;

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
	int			pl_mv_f;
	int			pl_mv_b;
	int			pl_mv_l;
	int			pl_mv_r;
	int			pl_rot_l;
	int			pl_rot_r;
	double		pos_x;
	double		pos_y;
	double		plane_x;
	double		plane_y;
	double		dir_x;
	double		dir_y;
	char		player_letter;
	double		delta_time;
	double		last_time;
	double		walk_speed;
	int			cant_move_forward;
	t_ray		*raycast;
	t_img		img;
	t_parser	*parser;
	t_img		texture[4];
}				t_data;

/* --- CORE --- */
// src/core/cleanup.c
int				clean_exit(t_data *data);
void			drain_out_gnl(int fd);
void			free_split(char **array);
void			free_parser(t_parser *parser);

// src/core/init.c
void			init(t_parser *parser, t_data *data);
void			init_parser(t_parser *parser);
void			init_data(t_data *data);
void			init_img(t_img *img);
int				read_map(t_parser *parser, t_data *data);

// src/core/utils.c
char			*trim_newline(char *str);
char			*skip_white(char *line);
int				is_it_whitespace(t_parser *parser);
char			*skip_white_after(char *line);

/* --- INPUT --- */
// src/input/hooks.c
int				handle_keypress(int keycode, void *param);
int				handle_keyrelease(int keycode, void *param);

// src/input/movement_rotate.c
void			handle_rotation(t_data *data);
void			rotate_left(t_data *data);
void			rotate_right(t_data *data);

// src/input/movement.c
void			move_forward(t_data *data);
void			move_back(t_data *data);
void			move_right(t_data *data);
void			move_left(t_data *data);
void			handle_movement(t_data *data);

/* --- PARSING --- */
// src/parsing/map_info.c
void			map_size(t_parser *parser);

// src/parsing/parse_file.c
int				check_ext(char *str);

// src/parsing/parse_header.c
int				dispatch_colour_parser(t_data *data, char *trim, int *elements);
int				check_textures_color(t_parser *pars, t_data *data);
void			init_for_parse(int *elements, int *i, char **line);
int				parse_textures(t_data *data, t_parser *parser, char *trim);
int				parse_colours(t_data *data, t_parser *pars, char *trim);

// src/parsing/parse_map.c
char			**extend_the_map(char **old_map, char *line);
int				add_another_line(t_parser *parser, char *line);
int				parse_map(t_parser *parser, t_data *data);
int				parse_n_s(t_data *data, t_parser *pars, char *trim);
int				parse_w_e(t_data *data, t_parser *parser, char *trim);

// src/parsing/parser_help.c
int				are_only_digits(char **array);
char			**split_by_colour(t_parser *parser, char *trim, char letter);
int				convert_to_int(t_parser *pars, char **array, char lett);
int				is_line_nul(char *trim, char **line, t_data *data);
char			**split_c(char *ceil, char *trim, t_parser *pars, char **array);

// src/parsing/validate_walls_utils.c
int check_outer_wall(char **map);
int	is_invalid_wall(char **map, int i, int j);

// src/parsing/validate_walls.c
int				check_hole_ver(char **map, int i, int j);
int				check_hole_hor(char *line);
int				validate_hor(char **map);
int				validate_ver(char **map);
int				check_walls(char **map);

// src/parsing/validate.c
void			assign_position(t_data *data, int i, int j, int *player);
int				check_num_player(t_data *data, char **map);
int				check_valid_character(char *line);
int				map_check(t_data *data, char **map);

/* --- RENDER --- */
// src/render/draw_wall.c
t_img			*get_correct_texture(t_data *data);
void			draw_texture_slice(t_data *data, int x);
void			set_texture_x(t_data *data);
void			set_wall_pixel_x(t_data *data);
void			draw_wall(t_data *data);

// src/render/draw.c
int				render_frame(void *parm);
void			put_pixel(t_data *data, int x, int y, unsigned int color);
void			draw_floor_ceiling(t_data *data);

// src/render/frames.c
double			get_time(void);
double			calc_timeframe(t_data *data);

// src/render/raycast_setup.c
void			setup_ray(t_data *data, int x);
void			init_camera_plane(t_data *data);
void			init_direction_vector(t_data *data);
void			distribute_raycast(t_data *data);
void			init_raycast(t_ray *raycast);

// src/render/raycast.c
void			calculate_perpdist(t_data *data);
void			set_delta_dist(t_data *data);
void			set_step(t_data *data);
int				check_guards(t_data *data);
void			apply_dda(t_data *data);

// src/render/textures.c
int				load_texture(t_data *data, t_img *tex_img, char *path);
int				load_textures(t_data *data);

// src/render/window.c
int				start_window(t_data *data);

// src/main.c
int				malloc_structs(t_parser **parser, t_data **data);
int				input_check(int ac, char **av);
int				main(int ac, char **av);

#endif
