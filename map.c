/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 03:01:24 by briveiro          #+#    #+#             */
/*   Updated: 2023/11/08 14:49:49 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//revisar el bucle para ver que no se salte lineas

char	**map_maker(char *map_path)
{
	char	**map_matrix;
	int		fd;
	int		count;

	count = 0;
	map_matrix = malloc(sizeof(char *) * (mem_map(map_path) + 1));
	if (!map_matrix)
		print_error("Malloc error\n");
	fd = open(map_path, O_RDONLY);
	while (get_next_line(fd))
	{
		map_matrix[count] = get_next_line(fd);
		count++;
	}
	map_matrix = nullmaker(map_matrix);
	close(fd);
	return (map_matrix);
}

// Revisar el bucle con los free

int	mem_map(char *map_path)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (count);
}

char	**nullmaker(char **map_matrix)
{
	int	count_a;
	int	count_b;

	count_a = 0;
	while (map_matrix[count_a])
	{
		count_b = 0;
		while (map_matrix[count_a][count_b] != '\n'
			&& map_matrix[count_a][count_b] != '\0')
			count_b++;
		if (map_matrix[count_a][count_b] == '\n' &&
			map_matrix[count_a][count_b + 1] == '\0')
			map_matrix[count_a][count_b] = '\0';
		count_a++;
	}
	map_matrix[count_a] = NULL;
	return (map_matrix);
}
