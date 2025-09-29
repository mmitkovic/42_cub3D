/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:14:37 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/09/29 18:25:56 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// little leaks in parsing.
// fix when textures get extra letter, for example NOs, SOg

#include "../includes/cub3d.h"

static int	malloc_structs(t_parser **parser, t_data **data)
{
	*parser = malloc(sizeof(t_parser));
	if (!*parser)
		return (free(parser), 1);
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (free(parser), free(data), 1);
	return (0);
}

static int	input_check(int ac, char **av)
{
	char	*map_name;

	if (ac != 2)
	{
		printf("Wrong input!\n");
		return (1);
	}
	if (av[1] == NULL)
		return (1);
	map_name = av[1];
	if (check_ext(map_name))
		return (printf("Wrong extension!\n"), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_parser	*parser;
	t_data		*data;

	if (input_check(ac, av))
		return (1);
	if (malloc_structs(&parser, &data))
		return (1);
	init(parser, data);
	data->parser = parser;
	data->fd = open(av[1], O_RDONLY);
	if (data->fd < 0)
		return (write(1, "Error: cannot open the file\n", 24), free(parser),
			free(data), 1);
	if (read_map(parser, data))
		return (close(data->fd), free(data), 1);
	// check if map is valid before window starts running
	if (map_check(data, parser->map))
		return (printf("Error\nMap is not valid!\n"), 1);
	start_window(data);
	free_parser(parser);
	free(data);
	close(data->fd);
	return (0);
}
