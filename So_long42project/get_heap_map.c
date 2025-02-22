/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:18:26 by saharraz          #+#    #+#             */
/*   Updated: 2025/02/07 14:54:59 by saharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_newlines(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
	{
		free(str);
		put_error("error : newline in map (first line)\n");
	}
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] == '\n')
			{
				free(str);
				put_error("error : newline in map (empty line)\n");
			}
		}
		i++;
	}
}

char	*ft_getline(int fd)
{
	char	*buffer;
	char	*one_line;
	char	*ptr;
	int		i;

	one_line = NULL;
	buffer = malloc(5 * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read (fd, buffer, (int)5);
		if (i <= 0)
			break ;
		buffer[i] = '\0';
		ptr = one_line;
		one_line = ft_strjoin(one_line, buffer);
		free (ptr);
	}
	free (buffer);
	return (one_line);
}

char	**reading_map(int fd)
{
	char	**map;
	char	*file_content;

	file_content = ft_getline(fd);
	if (ft_strlen(file_content) == 0)
	{
		free(file_content);
		put_error("Error : Invalid map !\n");
	}
	check_newlines(file_content);
	map = ft_split(file_content, '\n');
	if (!map)
		return (NULL);
	free (file_content);
	return (map);
}
