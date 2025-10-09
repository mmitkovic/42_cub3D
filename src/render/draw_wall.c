/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:50:15 by hgatarek          #+#    #+#             */
/*   Updated: 2025/10/09 15:24:32 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img	*get_correct_texture(t_data *data)
{
	t_ray *ray;

	ray = data->raycast;
	if (ray->horizontal == 1) // horizontal wall (X-axis)
	{
		// We need to check if the ray is pointing left or right.
		if (ray->raydir_x > 0)
		{
			// Ray is pointing right, so it must have hit a WEST wall.
			return (&data->texture[2]);
		}
		else
		{
			// Ray is pointing left, so it must have hit an EAST wall.
			return (&data->texture[3]);
		}
	}
	else if (ray->vertical == 1) //Vertial wall was hit, its horizontal hit):
	{
		// We need to check if the ray is pointing up or down.
		if (ray->raydir_y > 0)
		{
			// Ray is pointing down, so it must have hit a NORTH wall.
			return (&data->texture[0]);
		}
		else
		{
			// Ray is pointing up, so it must have hit a SOUTH wall.
			return (&data->texture[1]);
		}
	}
	return (NULL);
}

// void	put_pixel(t_img *img, int x, int y, unsigned int color)
// {
// 	char	*pixel_addr;

// 	// Safety check 1: Ensure the image buffer exists.
// 	if (!img || !img->addr)
// 		return;

// 	// Safety check 2: Ensure the coordinates are within the window bounds.
// 	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
// 		return;

// 	// Calculate the memory address of the target pixel.
// 	// This formula works for any bit depth (bpp) and line length.
// 	pixel_addr = img->addr + (y * img->line_len + x * (img->bpp / 8));

// 	// Place the color into the memory location.
// 	// We cast the char pointer to an unsigned int pointer to write the
// 	// full color value at once.
// 	*(unsigned int *)pixel_addr = color;
// }

void	draw_textured_slice(t_data *data, t_ray **ray, int x)
{
	t_img	*texture;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
	int		y;

	// 1. Select the correct texture
	texture = get_correct_texture(data);
	if (!texture)
		return ;
	// 2. Calculate the X-coordinate on the texture (tex_x)
	// This uses wall_x, the 0.0-1.0 hit coordinate.
	tex_x = (int)((*ray)->wall_x * TEX_SIZE/*(double)texture->w*/);

	// Optional but recommended: Flip the texture coordinate if the ray
	// hit a certain side. This prevents a "mirroring" effect.
	if (((*ray)->horizontal == 1 && (*ray)->raydir_x > 0) || ((*ray)->vertical == 1 && (*ray)->raydir_y < 0))
		tex_x = TEX_SIZE - tex_x - 1;

	// 3. Set up for calculating the Y-coordinate on the texture (tex_y)
	// 'step' is how much we move in the texture for each 1-pixel step on the screen.
	step = 1.0 * TEX_SIZE / (*ray)->line_height;
	// 'tex_pos' is the starting vertical texture coordinate. We start it
	// off the top of the wall slice to handle cases where the player is very close.
	tex_pos = ((*ray)->draw_start - WIN_H / 2 + (*ray)->line_height / 2) * step;

	// 4. Loop through every vertical pixel of the wall slice
	y = (*ray)->draw_start;
	while (y < (*ray)->draw_end)
	{
		// 5. Get the exact Y-coordinate on the texture
		// We cast tex_pos to an int and use a bitwise AND to keep it within
		// the texture's height, which is safer than the modulo operator (%).
		tex_y = (int)tex_pos & (texture->h - 1);
		tex_pos += step; // Move down the texture for the next screen pixel

		// 6. Get the color of the pixel from the texture's data buffer
		char *pixel_addr = texture->addr + (tex_y * texture->line_len + tex_x * (texture->bpp / 8));
		unsigned int color = *(unsigned int *)pixel_addr;

		// Optional: Make Y-side walls darker for better definition
		if ((*ray)->vertical == 1)
			color = (color >> 1) & 8355711; // A trick to divide RGB by 2

		// 7. Put the pixel onto your main image bufferc
		put_pixel(data, x, y, color);
		y++;
	}
}

void	set_texture_x(t_data *data)
{
	t_ray *ray;

	ray = data->raycast;
	ray->tex_x = (int)(ray->wall_x * TEX_SIZE/*(double)(data->img->w)*/);
	if (ray->vertical == 1 && ray->raydir_x > 0)
		ray->tex_x = TEX_SIZE/*data->img->w*/ - ray->tex_x - 1;
	if (ray->horizontal == 1 && ray->raydir_y < 0)
		ray->tex_x = TEX_SIZE/*data->img->w*/ - ray->tex_x - 1;
	return ;
}

void	set_wall_pixel_x(t_data *data)
{
	t_ray *ray;

	ray = data->raycast;
	if (ray->vertical)
		ray->wall_x = data->pos_y + ray->perp_dist * ray->raydir_y;
	else if (ray->horizontal)
		ray->wall_x = data->pos_x + ray->perp_dist * ray->raydir_x;
	ray->wall_x = ray->wall_x - floor((ray->wall_x));
	return ;
}
void draw_wall(t_data *data)
{
	t_ray *ray;

	ray = data->raycast;
	ray->line_height = WIN_H / ray->perp_dist;
	ray->draw_start = -(ray->line_height) / 2 + WIN_H / 2;
    if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_H / 2;
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H - 1;	
}