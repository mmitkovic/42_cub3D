/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:33:30 by hgatarek          #+#    #+#             */
/*   Updated: 2025/10/14 14:10:20 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_ext(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strncmp(str + len - 4, ".cub", 4) == 0)
		return (0);
	return (1);
}
