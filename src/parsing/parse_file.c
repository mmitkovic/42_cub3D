/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:33:30 by hgatarek          #+#    #+#             */
/*   Updated: 2025/09/22 16:41:07 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int check_ext(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (ft_strncmp(str + len - 4, ".cub", 4) == 0)
		return (0);
	return (1);
}
// read .cub, split header/map