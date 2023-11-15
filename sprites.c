/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:18:34 by briveiro          #+#    #+#             */
/*   Updated: 2023/11/08 15:00:49 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_game *game)
{
	t_sprites	*sprites;

	sprites = malloc(sizeof(t_sprites));
	sprites->wall = mlx_load_png("textures/wall.png");
	sprites->floor = mlx_load_png("textures/floor.png");
	sprites->collectible = mlx_load_png("textures/collectible.png");
	sprites->player = mlx_load_png("textures/player.png");
	sprites->exit = mlx_load_png("textures/exit.png");
	if (!sprites->wall || !sprites->floor || !sprites->collectible
		|| !sprites->player || !sprites->exit)
		print_error("Error\n Sprites path failure\n");
	sprite_to_image(game, sprites);
	free_sprites(sprites);
}

void	sprite_to_image(t_game *game, t_sprites *sprites)
{
	game->images.wall = mlx_texture_to_image(game->mlx, sprites->wall);
	game->images.floor = mlx_texture_to_image(game->mlx, sprites->floor);
	game->images.collectible = mlx_texture_to_image(game->mlx,
			sprites->collectible);
	game->images.player = mlx_texture_to_image(game->mlx, sprites->player);
	game->images.exit = mlx_texture_to_image(game->mlx, sprites->exit);
	if (!game->images.wall || !game->images.floor || !game->images.collectible
		|| !game->images.player || !game->images.exit)
		print_error("Error\n Sprites path failure\n");
	free_sprites(sprites);
}

void	free_sprites(t_sprites *sprites)
{
	mlx_delete_texture(sprites->wall);
	mlx_delete_texture(sprites->floor);
	mlx_delete_texture(sprites->collectible);
	mlx_delete_texture(sprites->player);
	mlx_delete_texture(sprites->exit);
	free(sprites);
}
