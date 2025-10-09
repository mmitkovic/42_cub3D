/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:12:57 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/08 09:05:19 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double 	walk_speed;
	double	turn_speed;
	int		walk_direction; // -1 for back, +1 for front
	int		turn_direction; // -1 for left, +1 for right
} t_player;

typedef struct  s_ray
{
	double ray_angle;
	double wall_hit_x;
	double wall_hit_y;
	double distance;
	int was_hit_ver;
	int is_ray_up;
	int is_ray_down;
	int is_ray_left;
	int is_ray_right;
	int wall_hit_content; // what is the ray hitiing (1, E, W, ...)
} t_ray;

# endif