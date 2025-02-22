/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharraz <saharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:07 by saharraz          #+#    #+#             */
/*   Updated: 2025/02/07 15:49:32 by saharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*fill(int for_sign, long nb, int nblen)
{
	char	*holder ;

	holder = malloc(nblen + 1);
	if (!holder)
		return (NULL);
	if (for_sign < 0)
		holder[0] = '-';
	holder[nblen--] = '\0';
	while (nb)
	{
		holder[nblen--] = nb % 10 + '0';
		nb /= 10;
	}
	return (holder);
}

static char	*zerocase(void)
{
	char	*holder;

	holder = malloc(2);
	if (!holder)
		return (NULL);
	holder[0] = '0';
	holder[1] = '\0';
	return (holder);
}

char	*ft_itoa(int n)
{
	long	nb;
	long	tmp;
	int		numlen;

	if (n == 0)
		return (zerocase());
	nb = n;
	numlen = 0;
	if (nb < 0)
	{
		nb = -nb;
		numlen += 1;
	}
	tmp = nb;
	while (tmp)
	{
		tmp /= 10;
		numlen++;
	}
	return (fill(n, nb, numlen));
}
