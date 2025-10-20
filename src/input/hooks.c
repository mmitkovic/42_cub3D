/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:20:51 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/17 11:59:57 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	handle_close_win(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	clean_exit(data);
	return (0);
}

int	handle_keyrelease(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_ESC)
		clean_exit(data);
	if (keycode == KEY_W)
		data->pl_mv_f = 0;
	if (keycode == KEY_A)
		data->pl_mv_l = 0;
	if (keycode == KEY_S)
		data->pl_mv_b = 0;
	if (keycode == KEY_D)
		data->pl_mv_r = 0;
	if (keycode == R_ARW)
		data->pl_rot_r = 0;
	if (keycode == L_ARW)
		data->pl_rot_l = 0;
	return (0);
}

int	handle_keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_ESC)
		clean_exit(data);
	if (keycode == KEY_W)
		data->pl_mv_f = 1;
	if (keycode == KEY_A)
		data->pl_mv_l = 1;
	if (keycode == KEY_S)
		data->pl_mv_b = 1;
	if (keycode == KEY_D)
		data->pl_mv_r = 1;
	if (keycode == R_ARW)
		data->pl_rot_r = 1;
	if (keycode == L_ARW)
		data->pl_rot_l = 1;
	return (0);
}
