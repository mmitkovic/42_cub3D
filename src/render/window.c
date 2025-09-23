/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:10:46 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/09/23 09:14:04 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Make clean_exit function that
// destroys the window and cleans the memory properly

static int	handle_close_win(int keysym, t_data *data)
{
	if (keysym == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

static int	handle_keyrelease(int keysym, void *data)
{
    printf("Keyrelease: %d\n", keysym);
    return (0);
}

static int handle_keypress(int keysym, t_data *data)
{
	printf("Keypress: %d\n", keysym);
	return (0);
}

static int handle_no_event(void *data)
{
	return (0);
}

int	start_window(t_data *data)
{
	// init window
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "Cub3D by H&M");
	if (!data->win_ptr)
	{
		// simplify by adding clean_exit function
		free(data->mlx_ptr);
		return (0);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
		&data->img.line_len, &data->img.endian);
	//set hooks
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, &data);
	mlx_hook(data->win_ptr, EVT_KEYPRESS, MASK_KEYPRESS, &handle_keypress, &data);
	mlx_hook(data->win_ptr, EVT_KEYRELEASE, MASK_KEYRELEASE, &handle_keyrelease, &data);
	mlx_hook(data->win_ptr, EVT_DESTROY, MASK_KEYPRESS, &handle_close_win, &data);
	mlx_loop(data->mlx_ptr);
	return (1);
}
