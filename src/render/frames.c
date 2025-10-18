/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:07:28 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/18 18:46:52 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_time(void)
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

double calc_timeframe(t_data *data)
{
	double now;
	double frame_time;
	
	now = get_time();
	frame_time = (now - data->last_time) / 1000.0;
	if (frame_time > 0.05f)
		frame_time = 0.05f;
    if (frame_time < 0.001f)
		frame_time = 0.001f;
	data->last_time = now;
	data->delta_time = frame_time;
	return (frame_time); 
}
