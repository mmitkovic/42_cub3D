/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:10:46 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/10 18:06:06 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	start_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	if (load_textures(data))
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "Cub3D by H&M");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (0);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	if (!data->img.mlx_img)
		return (clean_exit(data), 0);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian); // get image data address
	render_frame(data);
	// mlx_loop_hook(data->mlx_ptr, render_frame, data);
	mlx_hook(data->win_ptr, EVT_KEYPRESS, MASK_KEYPRESS, &handle_keypress,
		data);
	mlx_hook(data->win_ptr, EVT_KEYRELEASE, MASK_KEYRELEASE, &handle_keyrelease, data);
	mlx_hook(data->win_ptr, EVT_DESTROY, 0, &handle_close_win, data);
	//mlx_hook(data->win_ptr, 4, (1L<<2), &handle_mouse_press, data);
	//mlx_hook(data->win_ptr, 5, 0, &handle_mouse_press, data);
	//mlx_hook(data->win_ptr, 6, (1L<<8), &handle_mouse_move, data);
	mlx_loop(data->mlx_ptr);
	return (1);
}
