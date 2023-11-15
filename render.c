/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:51:15 by briveiro          #+#    #+#             */
/*   Updated: 2023/11/08 14:50:39 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(t_game *game)
{
	render_walls_and_exit(game);
	render_floor(game);
	render_player(game);
	render_collectibles(game);
}

void	render_floor(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (mlx_image_to_window(game->mlx, game->images.floor,
					b * SPRITE, a * SPRITE) == -1)
				print_error("Error\nmlx_image_to_window failure\n");
			b++;
		}
		a++;
	}
}

void	render_player(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (game->map[a][b] == 'P')
			{
				if (mlx_image_to_window(game->mlx, game->images.player,
						b * SPRITE, a * SPRITE) == -1)
					print_error("Error\nmlx_image_to_window failure\n");
			}
			b++;
		}
		a++;
	}
}

void	render_collectibles(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (game->map[a][b] == 'C')
			{
				if (mlx_image_to_window(game->mlx, game->images.collectible,
						b * SPRITE, a * SPRITE) == -1)
					print_error("Error\nmlx_image_to_window failure\n");
			}
			b++;
		}
		a++;
	}
}

void	render_walls_and_exit(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (game->map[a][b] == '1')
			{
				if (mlx_image_to_window(game->mlx, game->images.wall,
						b * SPRITE, a * SPRITE) == -1)
					print_error("Error\nmlx_image_to_window failure\n");
			}
			else if (game->map[a][b] == 'E')
			{
				if (mlx_image_to_window(game->mlx, game->images.exit,
						b * SPRITE, a * SPRITE) == -1)
					print_error("Error\nmlx_image_to_window failure\n");
			}
			b++;
		}
		a++;
	}
}
