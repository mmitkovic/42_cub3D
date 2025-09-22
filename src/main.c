/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:14:37 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/09/22 11:06:39 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	char	*map;
	int		fd;
	
	if (ac != 2)
		printf("Wrong input!\n");
	if (av[1] == NULL)
		return (1);
	map = av[1];

	// init data and node
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (write(1, "Error: cannot open the file\n", 24), 1);
	// read_map(fd, &data)
	close(fd);
	
	return (0);
}
