/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:29 by saharraz          #+#    #+#             */
/*   Updated: 2025/02/07 14:52:13 by saharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_chars(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			if (!ft_strchr("01ECP", map[i][j]))
			{
				ft_free(map);
				put_error("Error: invalid character in map \n");
			}
			j++;
		}
		i++;
	}
	return (count);
}

void	check_map_walls(char **map)
{
	int	j;

	j = 0;
	while (map[0][j] != '\0')
	{
		if (map[0][j] != '1')
		{
			ft_free(map);
			put_error ("Error: invalid wall in the start walls[start][x]\n");
		}
		j++;
	}
	check_map_walls2(map);
}

void	check_map_walls2(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = ft_strlen (map[i]) - 1;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][j] != '1')
		{
			ft_free(map);
			put_error ("Error: FIX THE WALLS.\n");
		}
		i++;
	}
	i--;
	while (j >= 0)
	{
		if (map[i][j] != '1')
		{
			ft_free(map);
			put_error ("Error: invalid wall at the end walls[end][x]\n");
		}
		j--;
	}
}

void	cheaking_map(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			ft_free(map);
			put_error("Error: fix map lines.\n");
		}
		i++;
	}
	check_map_walls(map);
	if (check_map_chars(map, 'C') < 1 || check_map_chars(map, 'P') != 1)
	{
		ft_free(map);
		put_error("error : there is (no P || > 1 P) || no C(s)\n");
	}
	if (check_map_chars(map, 'E') != 1)
	{
		ft_free(map);
		put_error("error : caracter (E)XIT  doesn't exist\n");
	}
}
