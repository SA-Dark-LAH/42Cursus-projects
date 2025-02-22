/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:15:00 by saharraz          #+#    #+#             */
/*   Updated: 2025/02/15 15:24:56 by saharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	extention_checker(char *str)
{
	size_t		i;
	char		*extention;
	int			j;
	int			dot;

	extention = ".ber";
	i = ft_strlen(str);
	if (i <= 4)
		put_error("Error : Your map file NAME ISN'T VALID\n");
	j = i - 4;
	i = 0;
	while (str[j] != '\0' && extention[i] != '\0')
		if (str[j++] != extention[i++])
			put_error("Error : False extention! (.ber)\n");
	j = 0;
	dot = 0;
	while (str[j++] != '\0')
	{
		if (str[j] == '.')
			dot++;
	}
	if (dot > 1)
		put_error("Error : INVALID extention !\n");
}

int	main(int ac, char **av)

{
	char	**map;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			put_error("Error opening file.\n");
		extention_checker(av[1]);
		map = reading_map(fd);
		cheaking_map(map);
		path_is_valid(map, 0); //to check all C_s are reachable 
		path_is_valid(map, 1); //to check that the exit is reachable
		rendring_game(map);
		ft_free (map);
	}
	else
		put_error("(Error : INVALID INPUT) -> [input x.ber file]\n");
}
