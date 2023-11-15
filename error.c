/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:22:57 by briveiro          #+#    #+#             */
/*   Updated: 2023/11/08 14:49:20 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// t_game	*game_and_map_verifier(t_game *game, char *map_checker)
// {
// 	size_t	count;

// 	if (map_checker[count - 3] != 'b' || map_checker[count - 2] != 'e'
// 		|| map_checker[count - 4] != '.' || map_checker[count - 1] != 'r')
// 		print_error("Error\nWrong map extension\n");
// 	game = malloc(sizeof(t_game));
// 	if (!game)
// 		print_error("Malloc error\n");
// 	return (game);
// }

void	args_verifyer(int argc)
{
	if (argc != 2)
	{
		print_error("Error\nWrong number of arguments\n");
		exit(0);
	}
}

void	print_error(char *str)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	exit(0);
}
