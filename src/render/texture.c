/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:17:18 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/06 09:17:02 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	load_texture(t_data *data, t_img *tex_img, char *path)
{
	if (!path || !data || !tex_img)
		return (1);
	tex_img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &tex_img->w,
			&tex_img->h);
	if (!tex_img->mlx_img)
		return (1);
	// Validate texture dimensions
	if (tex_img->w <= 0 || tex_img->h <= 0)
	{
		mlx_destroy_image(data->mlx_ptr, tex_img->mlx_img);
		return (1);
	}
	tex_img->addr = mlx_get_data_addr(tex_img->mlx_img, &tex_img->bpp,
			&tex_img->line_len, &tex_img->endian);
	if (!tex_img->addr)
	{
		mlx_destroy_image(data->mlx_ptr, tex_img->mlx_img);
		return (1);
	}
	return (0);
}

int	load_textures(t_data *data)
{
	int	i;

	i = 0;
	if (!data || !data->parser)
		return (1);
	if (load_texture(data, &data->texture[i++], data->parser->n_path) ||
		load_texture(data, &data->texture[i++], data->parser->s_path) ||
		load_texture(data, &data->texture[i++], data->parser->w_path) ||
		load_texture(data, &data->texture[i++], data->parser->e_path))
	{
		printf("Error\nTexture loading failure");
		clean_exit(data);
	}
	// {
	// 	// Cleanup already loaded textures
	// 	while (--i >= 0)
	// 		mlx_destroy_image(data->mlx_ptr, data->texture[i].mlx_img);
	// 	return (1);
	// }
	return (0);
}
