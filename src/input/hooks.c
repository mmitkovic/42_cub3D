/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:20:51 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/09 16:25:54 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	handle_mouse_move(int x, int y, void *param)
{
	(void)param;
	printf("Mouse moved to: %d, %d\n", x, y);
	return (0);
}

int handle_mouse_press(int button, int x, int y, void *param)
{
	(void)param;
	printf("Mouse button %d pressed at: %d, %d\n", button, x, y);
    return (0);
}

int	handle_close_win(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
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
	(void)keycode;
	
	// reset pos to 0 on release.
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
		move_back(data);
	if (keycode == KEY_D)
		printf("Keypress: %d\n", keycode);
	if (keycode == R_ARW)
		printf("Keypress: %d\n", keycode);
	if (keycode == L_ARW)
		printf("Keypress: %d\n", keycode);
	return (0);
}
