/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:57:32 by briveiro          #+#    #+#             */
/*   Updated: 2023/11/08 19:05:15 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "stdlib.h"
# include "stdarg.h"
# include "Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# define SPRITE 64

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_sprites
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
}	t_sprites;

typedef struct s_images
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
}	t_images;

typedef struct s_game
{
	mlx_t		*mlx;
	t_position	player;
	t_position	map_size;
	t_images	images;
	char		**map;
	char		**tempmap;
	int			collectibles;
	int			no_collectibles;
	int			moves;
}	t_game;

int		checker(t_game *game);
int		check_symbols(t_game *game);
int		check_walls(t_game *game);
int		check_collectibles(t_game *game);
void	args_verifyer(int argc);
void	print_error(char *str);
char	**map_maker(char *map_path);
int		mem_map(char *map_path);
char	**nullmaker(char **map_matrix);
void	render(t_game *game);
void	render_floor(t_game *game);
void	render_player(t_game *game);
void	render_collectibles(t_game *game);
void	render_walls_and_exit(t_game *game);
void	init_game(t_game *game);
void	load_sprites(t_game *game);
void	sprite_to_image(t_game *game, t_sprites *sprites);
void	free_sprites(t_sprites *sprites);
int		file_verifier(char *map);

#endif