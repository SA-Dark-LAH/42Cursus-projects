/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:18:51 by saharraz          #+#    #+#             */
/*   Updated: 2025/02/07 16:02:47 by saharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	searcher;

	if (!haystack && len == 0)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	index = 0;
	while (haystack[index] && index < len)
	{
		searcher = 0;
		while (haystack[index + searcher] == needle[searcher] && (index
				+ searcher) < len && needle[searcher])
			searcher++;
		if (needle[searcher] == '\0')
			return ((char *)(haystack + index));
		index++;
	}
	return (NULL);
}
