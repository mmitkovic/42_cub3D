/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:21:20 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/09/25 14:57:28 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  WASD, rotate, collision

#include "../../includes/cub3d.h"

int	handle_close_win(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}
int	handle_keyrelease(int keycode, void *param)
{
	t_data	*data;
	
	(void)keycode;
	data = (t_data *)param;
	return (0);
}

int handle_keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_ESC)
		clean_exit(data);
	if (keycode == KEY_W)
		printf("Keypress: %d\n", keycode);
	if (keycode == KEY_A)
		printf("Keypress: %d\n", keycode);
	if (keycode == KEY_S)
		printf("Keypress: %d\n", keycode);
	if (keycode == KEY_D)
		printf("Keypress: %d\n", keycode);
	if (keycode == R_ARW)
		printf("Keypress: %d\n", keycode);
	if (keycode == L_ARW)
		printf("Keypress: %d\n", keycode);
	return (0);
}
