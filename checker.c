/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 04:54:20 by briveiro          #+#    #+#             */
/*   Updated: 2023/11/08 14:48:57 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//terminar esta función
int	checker(t_game *game)
{
	if (!check_symbols(game))
		return (write(1, "Error\nWrong map symbols\n", 24));
	if (!check_walls(game))
		return (write(1, "Error\nWrong map walls\n", 22));
	if (!check_collectibles(game))
		return (write(1, "Error\nWrong map collectibles\n", 30));
	return (1);
}

int	check_symbols(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (game->map[a])
	{
		while (game->map[a][b])
		{
			if (game->map[a][b] != '1' && game->map[a][b] != '0'
			&& game->map[a][b] != 'C' && game->map[a][b] != 'E'
			&& game->map[a][b] != 'P')
				return (0);
			b++;
		}
		b = 0;
		a++;
	}
	return (1);
}

// revisar ultimo bucle
int	check_walls(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (game->map[0][b])
	{
		if (game->map[0][b] != '1')
			return (0);
		b++;
	}
	b--;
	while (game->map[a])
	{
		if (game->map[a][0] != '1' || game->map[a][b] != '1')
			return (0);
	}
	b = 0;
	while (game->map[a - 1][b])
	{
		if (game->map[a - 1][b] != '1')
			return (0);
		b++;
	}
	return (1);
}

int	check_collectibles(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	game->collectibles = 0;
	while (game->map[a])
	{
		while (game->map[a][b])
		{
			if (game->map[a][b] == 'C')
				game->collectibles++;
			b++;
		}
		b = 0;
		a++;
	}
	if (game->collectibles == 0)
		return (0);
	return (1);
}
