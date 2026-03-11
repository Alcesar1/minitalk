/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex GEOFFROY <ageoffro@student.42lausa    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:40:47 by Alex GEOFFR       #+#    #+#             */
/*   Updated: 2025/10/27 13:23:36 by Alex GEOFFR      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fcount(int n);

char	*ft_itoa(int n)
{
	char		*array;
	int			i;
	long int	nbr;
	int			j;

	j = 0;
	nbr = n;
	i = fcount(nbr);
	array = ft_calloc(i + 1, sizeof(char));
	if (!array)
		return (NULL);
	if (nbr < 0)
	{
		array[0] = '-';
		nbr *= -1;
		j = 1;
	}
	while (i > j)
	{
		i--;
		array[i] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (array);
}

static int	fcount(int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count = 1;
		return (count);
	}
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
