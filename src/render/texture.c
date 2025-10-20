/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:17:18 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/19 20:29:19 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	load_texture(t_data *data, t_img *tex_img, char *path)
{
	if (!path || !data || !tex_img)
		return (printf("Error: NULL parameter in load_texture\n"), 1);
	tex_img->w = 0;
	tex_img->h = 0;
	tex_img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &tex_img->w,
			&tex_img->h);
	if (!tex_img->mlx_img)
		return (1);
	tex_img->addr = mlx_get_data_addr(tex_img->mlx_img, &tex_img->bpp,
			&tex_img->line_len, &tex_img->endian);
	if (!tex_img->addr)
	{
		printf("Error: Failed to get texture address\n");
		mlx_destroy_image(data->mlx_ptr, tex_img->mlx_img);
		return (1);
	}
	return (0);
}

int	load_textures(t_data *data)
{
	if (!data || !data->parser)
		return (printf("Error\n NULL data or parser\n"), 1);
	if (load_texture(data, &data->texture[0], data->parser->n_path))
		return (printf("Error\nFailed to load N text.\n"), clean_exit(data), 1);
	if (load_texture(data, &data->texture[1], data->parser->s_path))
		return (printf("Error\nFailed to load S text.\n"), clean_exit(data), 1);
	if (load_texture(data, &data->texture[2], data->parser->w_path))
		return (printf("Error\nFailed to load W text.\n"), clean_exit(data), 1);
	if (load_texture(data, &data->texture[3], data->parser->e_path))
		return (printf("Error\nFailed to load E text\n"), clean_exit(data), 1);
	return (0);
}
