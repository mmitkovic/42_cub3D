/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:07:28 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/07 16:33:25 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

long	get_time(void)
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

static float calc_timeframe(t_data *data)
{
	float now;
	float frame_time;
	
	now = get_time();
	frame_time = (now - data->last_time) / 1000.0;
	data->last_time = now;
	data->delta_time = frame_time;
	return (frame_time); 
}
