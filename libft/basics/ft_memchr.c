/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:24:56 by alex              #+#    #+#             */
/*   Updated: 2025/10/11 12:06:14 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	if (n == '\0')
		return (0);
	while (n > 0)
	{
		if (*ptr == (unsigned char)c)
			return ((void *) ptr);
		n--;
		ptr++;
	}
	return (0);
}
