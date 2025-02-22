/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:00 by saharraz          #+#    #+#             */
/*   Updated: 2025/02/15 15:37:27 by saharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_alloc_map2(t_game *game, char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		i++;
	game->heapptr_map = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (map && map[i])
	{
		game->heapptr_map[i] = ft_strdup(map[i]);
		i++;
	}
	game->heapptr_map[i] = NULL;
}

void	save_position(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	path_image(t_game *game)
{
	int	x;
	int	y;

	game->img_p1 = mlx_xpm_file_to_image (game->mlx,
			"./textures/wall.xpm", &x, &y);
	check_xpm(game->img_p1, game);
	game->img_p2 = mlx_xpm_file_to_image (game->mlx,
			"./textures/rows.xpm", &x, &y);
	check_xpm(game->img_p2, game);
	game->img_p3 = mlx_xpm_file_to_image (game->mlx,
			"./textures/player.xpm", &x, &y);
	check_xpm(game->img_p3, game);
	game->img_p4 = mlx_xpm_file_to_image (game->mlx,
			"./textures/collectif.xpm", &x, &y);
	check_xpm(game->img_p4, game);
	game->img_p5 = mlx_xpm_file_to_image (game->mlx,
			"./textures/exit.xpm", &x, &y);
	check_xpm(game->img_p5, game);
}

void	put_to_window(t_game *game, char **map, int x, int y)
{
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img_p1,
					x * 50, y * 50);
			if (map[y][x] == '0')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img_p2,
					x * 50, y * 50);
			if (map[y][x] == 'P')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img_p3,
					x * 50, y * 50);
			if (map[y][x] == 'C')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img_p4,
					x * 50, y * 50);
			if (map[y][x] == 'E')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img_p5,
					x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	rendring_game(char **map)
{
	t_game	game;
	int		i;
	int		j;

	j = 0;
	ft_alloc_map2(&game, map);
	save_position(&game, map);
	game.mlx = mlx_init();
	game.nb_m = 0;
	while (map && map[j])
		j++;
	i = ft_strlen(map[0]);
	game.mlx_win = mlx_new_window(game.mlx, i * 50, j * 50, "SO-LONG");
	path_image(&game);
	put_to_window(&game, map, 0, 0);
	ft_free(map);
	mlx_hook(game.mlx_win, 17, 0, func_hook, &game);
	mlx_key_hook(game.mlx_win, keyhook, &game);
	mlx_loop(game.mlx);
}
