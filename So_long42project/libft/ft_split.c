/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:19:45 by saharraz          #+#    #+#             */
/*   Updated: 2025/02/07 14:58:16 by saharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	countwords(const char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			counter++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (counter);
}

static int	lensep(const char *s, char sep)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	return (i);
}

static char	*malloc_word(const char *str, char sep)
{
	int		index;
	char	*holder;

	holder = malloc(lensep(str, sep) + 1);
	if (!holder)
		return (NULL);
	index = 0;
	while (str[index] && str[index] != sep)
	{
		holder[index] = str[index];
		index++;
	}
	holder[index] = '\0';
	return (holder);
}

static void	free_it(char **splits, int i)
{
	while (i > 0)
		free(splits[--i]);
	free(splits);
}

char	**ft_split(char const *s, char c)
{
	int		pointers;
	char	**splits;
	int		i;

	if (!s)
		return (NULL);
	pointers = countwords(s, c);
	splits = (char **)malloc((pointers + 1) * sizeof(char *));
	if (!splits)
		return (NULL);
	i = 0;
	while (i < pointers)
	{
		while (*s && *s == c)
			s++;
		splits[i] = malloc_word(s, c);
		if (!(splits[i]))
			return (free_it(splits, i), NULL);
		while (*s && *s != c)
			s++;
		i++;
	}
	splits[i] = NULL;
	return (splits);
}
