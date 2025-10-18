/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:20:51 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/18 18:02:13 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int handle_keypress(int keycode, void *param)
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
