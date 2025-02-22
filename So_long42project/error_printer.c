/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:18:01 by saharraz          #+#    #+#             */
/*   Updated: 2025/02/17 17:02:51 by saharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

void	put_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

void	check_xpm(void *s, t_game *game)
{
	if (!s)
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
		put_error("cannot open file xpm try again !!\n");
	}
}

void	free_data_map(t_data *data, char **map)
{
		free_data(data);
	    ft_free(map);
		put_error("Error: Map large than your screen\n");
}
