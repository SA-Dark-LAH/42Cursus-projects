/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:19:53 by saharraz          #+#    #+#             */
/*   Updated: 2025/02/19 12:40:44 by saharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		destroy_game(game);
		exit(0);
	}
	if (keycode == 65362 || keycode == 119)
		func_move(keycode, game->x, game->y - 1, game);
	else if (keycode == 65364 || keycode == 115)
		func_move(keycode, game->x, game->y + 1, game);
	else if (keycode == 100 || keycode == 65363)
		func_move(keycode, game->x + 1, game->y, game);
	else if (keycode == 97 || keycode == 65361)
		func_move(keycode, game->x - 1, game->y, game);
	return (0);
}

int	collec_check(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->heapptr_map[i] != NULL)
	{
		j = 0;
		while (game->heapptr_map[i][j])
		{
			if (game->heapptr_map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	print_move(t_game *game)
{
	char	*num_str;
	char	*full_str;

	num_str = ft_itoa(game->nb_m);
	full_str = ft_strjoin(" ----| MOVE NUMBER |----> ", num_str);
	mlx_string_put(game->mlx, game->mlx_win, 30, 30, 0xFFFF00, full_str);
	ft_putstr(full_str);
	write(1, "\n", 1);
	free(num_str);
	free(full_str);
}

void	func_move(int keycode, int x, int y, t_game *game)
{
	game->c_s = collec_check(game);
	if (game->heapptr_map[y][x] == '0' || game->heapptr_map[y][x] == 'C')
	{
		if (game->heapptr_map[y][x] == 'C')
			game->c_s--;
		if (keycode == 65364 || keycode == 115)
			game->heapptr_map[y - 1][x] = '0';
		else if (keycode == 65362 || keycode == 119)
			game->heapptr_map[y + 1][x] = '0';
		else if (keycode == 65361 || keycode == 97)
			game->heapptr_map[y][x + 1] = '0';
		else if (keycode == 65363 || keycode == 100)
			game->heapptr_map[y][x - 1] = '0';
		game->heapptr_map[y][x] = 'P';
		game->x = x;
		game->y = y;
		game->nb_m++;
		put_to_window(game, game->heapptr_map, 0, 0);
		print_move(game);
	}
	else if (game->heapptr_map[y][x] == 'E' && game->c_s == 0)
	{
		ft_putstr("\n\n                                    |||  >> YOU WIN AL HAMDOLILAH ! << |||\n");
		destroy_game(game);
	}
}
