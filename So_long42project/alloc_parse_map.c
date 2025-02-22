/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_parse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:14 by saharraz          #+#    #+#             */
/*   Updated: 2025/02/22 15:52:45 by saharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	alloc_map(t_data *data, char **map)
{
	int		i;

	i = 0;
	while (map && map[i])
		i++;
	data->heapptr_map = malloc((i + 1) * sizeof(char *));
	if (!data->heapptr_map)
		return ;
	i = 0;
	while (map && map[i])
	{
		data->heapptr_map[i] = ft_strdup(map[i]);
		i++;
	}
	data->heapptr_map[i] = NULL;
}

void	save_p_pos(t_data *data, char **map)
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
				data->x_pos = j;
				data->y_pos = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	move_player(t_data *data, int y, int x, int zo)
{
	if (zo == 0)
	{
		if (data->heapptr_map[y][x] == '1' || data->heapptr_map[y][x] == 'E')
			return (0);
		if (data->heapptr_map[y][x] == 'C')
		{
			data->heapptr_map[y][x] = '0';
			data->c_s--;
		}
	}
	else
	{
		if (data->heapptr_map[y][x] == '1')
			return (0);
		if (data->heapptr_map[y][x] == 'E')
		{
			data->heapptr_map[y][x] = '0';
			data->e_x = 0;
		}
	}
	return (1);
}

void	cheaking_path(t_data *data, int y_pos, int x_pos, int zo)
{
	if (y_pos > data->nb_lines || x_pos > data->mapline_len)
		return ;
	if (y_pos < 0 || x_pos < 0)
		return ;
	if (data->c_s == 0)
		return ;
	data->heapptr_map[y_pos][x_pos] = '1';
	if (move_player(data, y_pos, x_pos + 1, zo) != 0)
		cheaking_path(data, y_pos, x_pos + 1, zo);
	if (move_player(data, y_pos - 1, x_pos, zo) != 0)
		cheaking_path(data, y_pos - 1, x_pos, zo);
	if (move_player(data, y_pos, x_pos - 1, zo) != 0)
		cheaking_path(data, y_pos, x_pos - 1, zo);
	if (move_player(data, y_pos + 1, x_pos, zo) != 0)
		cheaking_path(data, y_pos + 1, x_pos, zo);
}

int 	path_is_valid(char	**map, int zo)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->c_s = nb_of_c(map);
	data->e_x = 1;
	save_p_pos(data, map);
	alloc_map(data, map);
	data->mapline_len = ft_strlen(map[0]);
	i = 0;
	while (map[i] != NULL)
		i++;
	data->nb_lines = i; //tell here we just initialize our struct
	if (data->mapline_len >= 40 || data->nb_lines >= 22)
		free_data_map(data, map);
	cheaking_path(data, data->y_pos, data->x_pos, zo); //here we just check the path using flood fill algorithm
	if ((zo == 1 && data->e_x == 0) || (zo == 0 && data->c_s == 0)) // yla dkhlt hna donc path is valid , so kan free struct li 9adit bach ndir had check w knreturn , otherways rah kn free w kanput error .
		return(free_data(data), 0);
	free_data(data);
	ft_free(map);
	put_error("Error : Path isn't valid \n");
	return (0);
}
