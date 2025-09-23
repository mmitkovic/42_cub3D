/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:17:18 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/09/22 17:27:39 by mmitkovi         ###   ########.fr       */
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
int	load_textures()
{
	// load texture at the [0]
	// load texture at the [1]
	// load texture at the [2]
	// load texture at the [3]
}
