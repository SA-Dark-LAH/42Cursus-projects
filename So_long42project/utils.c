/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:18:36 by saharraz          #+#    #+#             */
/*   Updated: 2025/02/16 18:08:04 by saharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nb_of_c(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	free_data(t_data *data)
{
	int		i;

	i = 0;
	while (data->heapptr_map[i])
	{
		free (data->heapptr_map[i]);
		i++;
	}
	free (data->heapptr_map);
	free (data);

}

void	ft_free(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

int	func_hook(t_game *game)
{
	destroy_game(game);
	exit (1);
	return (0);
}

void	destroy_game(t_game *game)
{
	if (game->img_p1)
		mlx_destroy_image(game->mlx, game->img_p1);
	if (game->img_p2)
		mlx_destroy_image(game->mlx, game->img_p2);
	if (game->img_p3)
		mlx_destroy_image(game->mlx, game->img_p3);
	if (game->img_p4)
		mlx_destroy_image(game->mlx, game->img_p4);
	if (game->img_p5)
	{
		mlx_destroy_image(game->mlx, game->img_p5);
	}
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_free(game->heapptr_map);
	exit(0);
}
