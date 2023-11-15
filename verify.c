/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:02:42 by briveiro          #+#    #+#             */
/*   Updated: 2023/11/08 14:51:49 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_verifier(char *map)
{
	int	fd;

	if (ft_strncmp(&map[ft_strlen(map) - 4], ".ber", 4) != 0)
		return (write(2, "Error\nWrong map extension\n", 26), 0);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error\nMap not found\n", 20), 0);
	close(fd);
	return (1);
}
