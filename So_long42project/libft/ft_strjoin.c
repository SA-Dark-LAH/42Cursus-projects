/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:19:22 by saharraz          #+#    #+#             */
/*   Updated: 2025/02/07 15:56:56 by saharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		ls1;
	int		ls2;
	char	*s;

	if (!s1 && !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	s = (char *)malloc(sizeof (char) * (ls1 + ls2 + 1));
	if (!s)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		s[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
	{
		s[ls1] = s2[i];
		ls1++;
	}
	s[ls1] = '\0';
	return (s);
}
