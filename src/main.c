/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:14:37 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/06 16:46:21 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//PARSEING
//		conditional jump in clean_exit when the texture is bad !!

//VALIDATION
//		conditional jump in clean_exit when the texture is bad !!

//MLX
//		fix exit-button-click and clean_memory alongside

//!!! NORMINETTE !!!

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
		printf("Error\nWrong input!\n");
		return (1);
	}
	if (av[1] == NULL)
		return (1);
	map_name = av[1];
	if (check_ext(map_name))
		return (printf("Error\nWrong extension!\n"), 1);
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
		return (printf("Error: cannot open the file\n"), free(parser),
			free(data), 1);
	if (read_map(parser, data))
		return (close(data->fd), free_parser(parser), free(data), 1);
	if (map_check(data, parser->map))
		return (printf("Error\nMap is not valid!\n"), free_parser(parser), free(data), 1);
	start_window(data);
	//place to call raycast
	free_parser(parser);
	free(data);
	close(data->fd);
	return (0);
}
