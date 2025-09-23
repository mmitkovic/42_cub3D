/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:14:37 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/09/23 11:37:33 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	char		*map_name;
	int			fd;
	t_parser	*parser;
	
	if (ac != 2)
		printf("Wrong input!\n");
	if (av[1] == NULL)
		return (1);
	map_name = av[1];
	if (check_ext(map_name))
		return (printf("Wrong extension"), 1);
	parser = malloc(sizeof(t_parser));
	if (!parser)
		return (1);
	init_parser(parser);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (write(1, "Error: cannot open the file\n", 24), 1);
	if (read_map(parser, fd))
	{
		close(fd);
		//free parser
		return (1);
	}
	// free parser and strings within parser.
	close(fd);
	return (0);
}
