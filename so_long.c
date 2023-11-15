/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:55:39 by briveiro          #+#    #+#             */
/*   Updated: 2023/11/08 14:54:27 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// haciendo

void	init_game(t_game *game)
{
	game->mlx = mlx_init(game->map_size.x * 64,
			game->map_size.y * 64, "so_long", false);
	if (!game->mlx)
		print_error("Error\nMLX initialization failed\n");
	load_sprites(game);
	render(game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		print_error("Error\nWrong number of arguments\n");
	else
	{
		if (!file_verifier(argv[1]))
			exit(0);
		game = (t_game *)malloc(sizeof(t_game));
		game->map = map_maker(argv[1]);
		if (checker(game))
			init_game(game);
		// estoy programando aquí, la función de arriba
	}
}

