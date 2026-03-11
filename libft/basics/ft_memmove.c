/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex GEOFFROY <ageoffro@student.42lausa    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:39:07 by Alex GEOFFR       #+#    #+#             */
/*   Updated: 2025/10/10 11:08:43 by Alex GEOFFR      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		ft_memcpy(d, s, n);
		return (dest);
	}
	else
	{
		while (n--)
		{
			d[n] = s[n];
		}
		return (dest);
	}
}
/*
int	main()
{
	char src[] = "capi";
	char dst[] = "baralavida"
	size_t n = 9;

	ft_memmove(dst, src, n);
	printf("%s", dst);
	return (0);
}*/