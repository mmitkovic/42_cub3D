/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:14:31 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/09/26 11:20:28 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	drain_out_gnl(int fd)
{
	char	*line;

	if (fd < 0)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
}

void	clean_exit(t_data *data)
{
	int	i;

	i = 0;
	if (data->mlx_ptr)
	{
		while (i < 4)
		{
			if (data->texture[i].mlx_img)
				mlx_destroy_image(data->mlx_ptr, data->texture[i].mlx_img);
			i++;
		}
		if (data->img.mlx_img)
			mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_loop_end(data->mlx_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->parser)
	{
		free_parser(data->parser);
		//free(data->parser);
	}
	free(data);
	exit (0);
}
