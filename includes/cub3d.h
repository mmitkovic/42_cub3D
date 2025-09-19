/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:03:16 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/09/19 12:57:05 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
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

typedef struct s_map
{
	/* map data */
}			t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}			t_data;

#endif
