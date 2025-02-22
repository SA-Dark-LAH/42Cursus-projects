/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:19:36 by saharraz          #+#    #+#             */
/*   Updated: 2025/02/07 15:51:08 by saharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)str;
	while (p[i] != '\0' && p[i] != (char)c)
		i++;
	if (p[i] == (char)c)
		return (p + i);
	return (0);
}
