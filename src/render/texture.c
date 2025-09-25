/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:17:18 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/09/25 17:17:04 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	load_texture(t_data *data, t_img *tex_img, char *path)
{
	tex_img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &tex_img->w,
			&tex_img->h);
	if (!tex_img->mlx_img)
		return (1);
	tex_img->addr = mlx_get_data_addr(tex_img->mlx_img, &tex_img->bpp,
			&tex_img->line_len, &tex_img->endian);
	return (0);
}
int	load_textures(t_data *data)
{
	if (load_texture(data, &data->texture[0], data->parser->n_path))
		return (1);
	if (load_texture(data, &data->texture[1], data->parser->s_path))
		return (1);
	if (load_texture(data, &data->texture[2], data->parser->w_path))
		return (1);
	if (load_texture(data, &data->texture[3], data->parser->e_path))
		return (1);
	return (0);
}
