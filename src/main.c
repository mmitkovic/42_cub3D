/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:14:37 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/09/23 11:25:36 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	char	*map_name;
	int		fd;
	
	if (ac != 2)
		printf("Wrong input!\n");
	if (av[1] == NULL)
		return (1);
	map_name = av[1];
	if (check_ext(map_name))
		return (printf("Wrong extension"), 1);
	// init data and node
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (printf("Cannot open the file\n"), 1);
	// read_map(fd, &data)
	close(fd);
	
	return (0);
}
